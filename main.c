#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "boolean.h"

#define NEWLINE '\n'
#define NULLCHAR '\0'
#define BLANK ' '
#define MARK_EOF EOF

typedef struct {
    char* contents; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
    int length;
} Word;

void printAns(int row, int col, char posRowCol[row][col])
{
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (j == col-1)
                printf("%c", posRowCol[i][j]);
            else
                printf("%c ", posRowCol[i][j]);
        }
        printf("\n");
    }
}

int incIndexRow(int row, int dir)
{
    switch (dir)
    {
        case 1: // Timur
            return row; break;
        case 2: // Tenggara
            return (row+1); break;
        case 3: // Selatan
            return (row+1); break;
        case 4: // Barat Daya
            return (row+1); break;
        case 5: // Barat
            return row; break;
        case 6: // Barat Laut
            return (row-1); break;
        case 7: // Utara
            return (row-1); break;
        case 8: // Timur Laut
            return (row-1); break;
    }
}

int incIndexCol(int col, int dir)
{
    switch (dir)
    {
        case 1: // Timur
            return (col+1); break;
        case 2: // Tenggara
            return (col+1); break;
        case 3: // Selatan
            return col; break;
        case 4: // Barat Daya
            return (col-1); break;
        case 5: // Barat
            return (col-1); break;
        case 6: // Barat Laut
            return (col-1); break;
        case 7: // Utara
            return col; break;
        case 8: // Timur Laut
            return (col+1); break;
    };
}

void sequentialMatching(int j, int row, int col, char wordPuzzle[], Word words, boolean *found, char posRowCol[row][col], int dir, int *numCompare)
{
    // printf("%d\n\n", dir);
    int idxRow = j/col; // wordPuzzle index
    int idxCol = j%col;
    int idxWord = 1; // word content index
    // printf("%d %d\n", idxRow, idxCol);
    // printf("%d %d %d\n", incIndexRow(idxRow, dir), incIndexCol(idxCol, dir), (incIndexRow(idxRow, dir)*col)+incIndexCol(idxCol, dir));

    while(incIndexCol(idxCol, dir) >= 0 && incIndexCol(idxCol, dir) < col && incIndexRow(idxRow, dir) >= 0 && incIndexRow(idxRow, dir) < row
          && wordPuzzle[(incIndexRow(idxRow, dir)*col)+incIndexCol(idxCol, dir)] == words.contents[idxWord] && words.length > idxWord && (!(*found))){
        posRowCol[idxRow][idxCol] = words.contents[idxWord-1];
        // printf("before: %d %d\n", idxRow, idxCol);
        idxRow = incIndexRow(idxRow, dir);
        idxCol = incIndexCol(idxCol, dir);
        // printf("after: %d %d\n", idxRow, idxCol);
        idxWord++;
    }
    *numCompare++;
    //printf("numCompare : %d\n", *numCompare);
    if (idxWord == words.length){
        *found = true;
        posRowCol[idxRow][idxCol] = words.contents[idxWord-1];
        // printf("%d %d\n", idxRow, idxCol);
    }
    else{
        for (int a = 0; a < row; a++){
            for (int b = 0; b < col; b++){
                posRowCol[a][b] = '-';
            }
        }
    }
}

int main()
{
    FILE *fp = fopen("cobainput.txt", "r");

    if (fp == NULL){
        printf("File tidak tersedia");
    }
    else{
        char* wordPuzzle;
        char currChar;
        int charCtr = 0;
        int row = 0;
        int col = -1;
        boolean beforeNL = false;
        boolean emptyLine = false;
        boolean memory = false; // true if reallocation unsuccessfull

        int numWord = 0;
        int lenWord = 0;

        wordPuzzle = (char*)malloc(charCtr * sizeof(char));
        if (wordPuzzle != NULL){
            // Read wordPuzzle matrix
            currChar = getc(fp);
            while ((!emptyLine) && (!memory)){
                if (currChar != BLANK && currChar != NEWLINE){
                    if(beforeNL){
                        beforeNL = false;
                    }

                    charCtr++;
                    wordPuzzle = realloc(wordPuzzle, charCtr * sizeof(char));
                    if(wordPuzzle != NULL){
                        wordPuzzle[charCtr-1] = currChar;
                    }
                    else{
                        printf("Memory dynamic reallocation unsuccessfull!");
                        memory = true;
                    }
                    wordPuzzle[charCtr] = currChar;
                }
                else if (currChar == NEWLINE && col == -1){
                    col = charCtr;
                    row = 1;
                    beforeNL = true;
                }
                else if (currChar == NEWLINE){
                    if (beforeNL){
                        emptyLine = true;
                    }
                    else{
                        row++;
                        beforeNL = true;
                    }
                }
                currChar = getc(fp);
            }

            // Read words to be searched within wordPuzzle
            if (row > col){
                lenWord = row;
            }
            else{
                lenWord = col;
            }

            memory = false;
            Word* words = malloc(numWord * sizeof(Word));
            if (words != NULL){
                while (currChar != MARK_EOF && (!memory)){
                    numWord++;
                    words = realloc(words, numWord * sizeof(Word));
                    if (words != NULL){
                        words[numWord-1].contents = (char*)malloc(lenWord * sizeof(char*));

                        int ctr = 0;
                        while(currChar != MARK_EOF && currChar != NEWLINE && currChar != BLANK && currChar != NULLCHAR){
                            words[numWord-1].contents[ctr] = currChar;
                            ctr++;
                            currChar = getc(fp);
                        }
                        words[numWord-1].length = ctr;
                        currChar = getc(fp);
                    }
                    else{
                        printf("Memory dynamic reallocation unsuccessfull!");
                        memory = true;
                    }
                }
            }
            else{
                printf("Memory allocation unsuccessfull!");
            }

            // Brute Force Algorithm for Word Puzzle Problem
            // Algorithm :
            // 1. Start with a word. Iterate through wordPuzzle to find the first letter of the word.
            // 2. If the word's first letter is found, check for all directions for the second letter.
            //    If second letter is found, continue to search letter per letter on that direction.
            //    Otherwise, move to another direction. Repeat until found or all directions have searched.
            //    If not found, continue iteration through wordPuzzle. Repeat step 1.
            // 3. If found, continue step 1 to another word. Repeat until all words have been found.
            struct timeval start, end;

            gettimeofday(&start, NULL);

            for (int i = 0; i < numWord; i++){
                int numCompare = 0;
                int j = 0;
                boolean found = false;
                char posRowCol[row][col];

                for (int a = 0; a < row; a++){
                    for (int b = 0; b < col; b++){
                        posRowCol[a][b] = '-';
                    }
                }
                for(int j=0; j < words[i].length; j++){
                    printf("%c", words[i].contents[j]);
                }
                printf("\n");

                while (j < charCtr && (!found)){
                    if(wordPuzzle[j] == words[i].contents[0]){
                        // First letter found
                        if (words[i].length == 1){ // One letter retrieved
                            found = true;
                        }
                        else {
                            // Continue to search the rest to all directions
                            int dir = 1;
                            while (!found && dir <= 8){
                                sequentialMatching(j, row, col, wordPuzzle, words[i], &found, posRowCol, dir, &numCompare);
                                //printf("ketemu atau nggak : %d\n", found);
                                dir++;
                            }
                        }
                    }
                    j++;
                }
                // Finished searching a word
                printAns(row, col, posRowCol);
                printf("\n");
            }

            gettimeofday(&end, NULL);
            int ms_elapsed = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
            long s_elapsed = (end.tv_sec - start.tv_sec);
            printf("%d microseconds\n%lld seconds", ms_elapsed, s_elapsed);
        }
        else{
            printf("Memory allocation unsuccessfull!");
        }
    }
    fclose(fp);
    return 0;
}

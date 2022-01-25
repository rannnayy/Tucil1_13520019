# Penyelesaian <i>Word Search Puzzle</i> dengan Algoritma <i>Brute Force</i>
> Tugas Kecil 1 IF2121 Strategi Algoritma
> Maharani Ayu Putri Irawan - 13520019 - K1

## Table of Contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Features](#features)
* [Screenshots](#screenshots)
* [Setup](#setup)
* [Usage](#usage)
* [Project Status](#project-status)
* [Room for Improvement](#room-for-improvement)
* [Acknowledgements](#acknowledgements)
* [Contact](#contact)


## General Information
- <i>Word Search Puzzle</i> merupakan permainan mencari kata-kata di dalam kumpulan huruf yang biasanya disusun dalam bentuk persegi atau persegi panjang.
- Permainan ini dilakukan dengan menelusuri setiap huruf yang ada untuk menemukan kata yang dicari.
- Algoritma <i>brute force</i> merupakan algoritma yang <i>straightforward</i>. Alasan inilah yang menyebabkan algoritma ini cocok digunakan untuk mencari solusi dari <i>word search puzzle</i>.
Berikut merupakan penjelasan algoritma yang digunakan.
- Mulai dengan kata pertama yang hendak dicari dalam puzzle.
- Menelusuri setiap huruf yang terdapat dalam word puzzle untuk mencari huruf yang sama dengan huruf pertama kata yang dicari.
- Jika ditemukan huruf yang sesuai, lanjut dengan mencocokkan huruf kedua dan seterusnya dengan mencari ke arah Timur, Tenggara, Selatan, Barat Daya, Barat, Barat Laut, Utara, dan terakhir Timur Laut. Apabila huruf kedua ditemukan pada salah satu arah, akan diteruskan dengan mencocokkan huruf ketiga, keempat, dan seterusnya ke arah yang sama. Jika seluruh huruf pada kata tersebut telah ditemukan, pencarian ke arah mata angin setelahnya (yang belum dilalui) maupun huruf dalam word puzzle lainnya tidak perlu dilakukan. Namun, jika kata tersebut tidak ditemukan pada suatu arah, akan diteruskan pencarian ke arah setelahnya. Bila pada seluruh arah mata angin telah dicari namun tidak ditemukan, akan dilanjutkan ke langkah berikutnya.
- Bila tidak ditemukan huruf yang sesuai, lanjut dengan mencocokkan huruf pertama dengan huruf pada word puzzle selanjutnya.
- Jika sebuah kata telah ditemukan pada word puzzle tersebut, pencarian dilanjutkan pada langkah kedua terhadap kata selanjutnya.
- Bila seluruh kata telah ditemukan posisinya dalam word puzzle, pencarian berakhir.
- Setiap kali satu kata ditemukan posisinya di dalam word puzzle, ditampilkan matriks yang menunjukkan posisi suatu kata di dalam word puzzle.
- Pada akhir program, ditampilkan waktu eksekusi program dan jumlah perbandingan huruf yang diperlukan.
- Program ini disusun dalam bahasa C.


## Technologies Used
- Code::Blocks Text Editor - versi 20.03
- Gcc - versi 8.1.0 (MinGW x86_64-posix-seh-rev0)


## Features
Fitur yang terdapat dalam program ini antara lain:
- Pengguna dapat memilih file teks berisi puzzle yang akan diselesaikan. Dengan catatan bahwa file tersebut harus berada dalam folder yang sama dengan kode sumber.
- Keluaran program dalam bentuk kata, serta posisinya masing-masing di dalam puzzle.
- Di akhir akan ditampilkan jumlah komparasi yang diperlukan untuk menyelesaikan puzzle ini serta waktu eksekusinya. Dengan catatan, jumlah komparasi yang dihitung hanya komparasi antara huruf dalam kata yang dicari dengan huruf pada puzzle, serta waktu eksekusi yang diukur hanyalah waktu eksekusi pencarian solusi (tidak termasuk waktu proses menampilkan ke layar dan waktu proses pembacaan file).


## Screenshots
![SampleOutput](https://drive.google.com/uc?export=view&id=1lrmn1fB6NmKyrC7f4oY0GWBuLyEKEbIp)


## Setup
Program ini dibangun menggunakan bahasa C sehingga membutuhkan compiler yang dapat diinstal pada link <a href="https://sourceforge.net/projects/mingw/" alt="Link download installer MinGW">berikut</a>.
Untuk menjalankan program, buka Code::Blocks (download installer melalui link <a href="https://www.codeblocks.org/downloads/">ini</a>). Lalu, download kode sumber dan extract. Buka project kode sumber, lalu tekan tombol "Build and run". Program akan berjalan dan menampilkan daftar file yang tersedia pada folder test. Masukkan input file dengan diawali

`./test/`

Lalu program akan mencari solusi word search puzzle pada file yang dimaksudkan. Hasil pencarian akan ditampilkan untuk setiap kata yang dicari. Di akhir akan ditampilkan waktu eksekusi yang diperlukan serta jumlah perbandingan yang dilakukan.


## Usage
Saat program dijalankan, user akan diminta untuk memasukkan nama file yang berisi puzzle yang hendak diselesaikan. Contoh input yang valid adalah sebagai berikut:

`./test/cobainput.txt`

Setelahnya, program akan secara otomatis mencari solusi puzzle yang dipilih menggunakan algoritma ,<i>brute force</i>.


## Project Status
Project is: _complete_.


## Room for Improvement
Program ini masih dapat dikembangkan lebih lanjut, antara lain:

Room for improvement:
- Mengubah keluaran sehingga hanya berupa 1 word puzzle yang telah diberi warna berbeda untuk setiap kata. Untuk alasan keterbatasan hardware yang digunakan dalam membangun program ini, peningkatan ini tidak dapat terealisasi.
- Penggunaan GUI.
- Optimisasi baik dalam hal memori dan waktu dalam proses.


## Acknowledgements
Ucapan terima kasih hendak saya sampaikan kepada:
- Bapak/Ibu Dosen pengampu mata kuliah IF2121 Strategi Algoritma ITB.
- Kakak-kakak asisten mata kuliah IF2121 Strategi Algoritma.
- Tim pembangun website https://tools.atozteacherstuff.com/word-search-maker/wordsearch.php yang telah membantu saya dalam membuat <i>test case</i> yang digunakan untuk menguji program ini.


## Contact
Created by [@rannnayy](https://github.com/rannnayy) - feel free to contact me!

<b>Maharani Ayu Putri Irawan - 13520019 - K1</b>
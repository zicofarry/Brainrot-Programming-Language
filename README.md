
# BrainrotLang (brot) 🧠☕︎

[![npm version](https://img.shields.io/npm/v/brainrot-language.svg)](https://www.npmjs.com/package/brainrot-language)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/zicofarry/Brainrot-Programming-Language)

**BrainrotLang** adalah sebuah bahasa pemrograman *esoterik* (esolang) berbasis bahasa C yang dirancang untuk mengintegrasikan budaya internet modern dan terminologi meme ke dalam struktur pemrograman prosedural. Proyek ini bertujuan untuk mengeksplorasi pembuatan interpreter dengan sintaksis yang tidak konvensional namun tetap fungsional.

---

## 🛠️ Prasyarat Sistem

Sebelum menggunakan BrainrotLang, pastikan sistem Anda telah memenuhi persyaratan berikut:

* **Node.js & NPM**: Digunakan untuk instalasi paket secara global.
* **GCC Compiler (MinGW/Cygwin)**: Diperlukan untuk proses kompilasi kode hasil transpilasi ke dalam file eksekusi (.exe). Pastikan `gcc` sudah terdaftar dalam **Environment Variables (PATH)** Anda.

---

## 🚀 Instalasi

### Metode 1: Melalui NPM (Rekomendasi)

Anda dapat menginstal BrainrotLang secara global untuk mengakses perintah `brot` dari direktori mana pun:

```bash
npm install -g @zicofarry/brainrot-language
```

### Metode 2: Melalui Repositori (Development)

Jika Anda ingin berkontribusi atau melakukan modifikasi pada kode sumber:

```bash
git clone https://github.com/zicofarry/Brainrot-Programming-Language.git
cd Brainrot-Programming-Language

```

---

## 💻 Penggunaan

Untuk menjalankan file sumber BrainrotLang (`.brainrot`), gunakan perintah berikut pada terminal:

```bash
brot nama_file.brainrot

```

---

## 📜 Dokumentasi Perintah

Dokumentasi ini berisi daftar lengkap sintaksis **BrainrotLang** dan padanannya dalam bahasa pemrograman C. Semua perintah harus ditulis dalam huruf kecil (*lowercase*) sesuai dengan spesifikasi interpreter.


### 1. Fungsi & Kontrol Alur (Basic Functions & Control Flow)

| Brainrot Syntax | Padanan C | Deskripsi |
| --- | --- | --- |
| `gyatt` | `scanf()` | Mengambil input dari pengguna. |
| `bombaclat` | `printf()` | Menampilkan output ke konsol. |
| `goofy` | `if` | Percabangan kondisi utama. |
| `sus` | `else if` | Percabangan kondisi alternatif. |
| `ahh` | `else` | Kondisi terakhir jika semua syarat tidak terpenuhi. |
| `lingaguliguli` | `while` | Perulangan selama kondisi terpenuhi. |
| `tungtungtung` | `for` | Perulangan dengan inisialisasi dan batas tertentu. |
| `unpause` | `continue` | Melanjutkan ke iterasi perulangan berikutnya. |
| `stahp` | `}` (End Block) | Penutup blok kode (End if/End for/End while). |
| `danYappp` | `return 0;` | Mengakhiri eksekusi program (Finally function). |


### 2. Tipe Data (Data Types)

| Brainrot Syntax | Tipe Data C | Penggunaan |
| --- | --- | --- |
| `skibidi` | `int` | Bilangan bulat. |
| `skibidiToilet` | `float` | Bilangan desimal/pecahan. |
| `sigma` | `char` | Karakter tunggal. |
| `sigmaBoy` | `char[] / string` | Kumpulan karakter (teks). |


### 3. Operator Logika & Perbandingan (Operators)

| Brainrot Syntax | Operator C | Deskripsi |
| --- | --- | --- |
| `butAlso` | `&&` | Logika AND. |
| `orNahh` | `\|\|` | Logika OR. |
| `peak` | `>` | Lebih besar dari. |
| `mid` | `<` | Lebih kecil dari. |
| `mogged` | `>=` | Lebih besar atau sama dengan. |
| `cooked` | `<=` | Lebih kecil atau sama dengan. |
| `match` | `==` | Sama dengan (perbandingan). |
| `hitdiff` | `!=` | Tidak sama dengan. |
| `is` | `=` | Inisialisasi/Penugasan nilai. |


### 4. Sintaks Khusus (Special Syntax)

* **Penugasan (Assignment)**:
```text
[variable] is [value]
```


*Digunakan untuk memberikan nilai spesifik pada variabel dengan tipe data tertentu.*
* **Inisialisasi Iterasi**:
`sahur` (Padanan: `i = 0`)
*Biasanya digunakan di dalam blok perulangan.*
* **Pembatas Rentang**:
`tilz` (Padanan: `limit` atau batas hingga)
*Digunakan untuk menentukan batas akhir sebuah perulangan.*


### Tips Penggunaan

Pastikan setiap blok kode kondisional atau perulangan selalu diakhiri dengan keyword `stahp` untuk menghindari error pada saat proses *parsing* ke bahasa C.

Daftar perintah selengkapnya dapat Anda akses pada: **[COMMAND.md](https://github.com/zicofarry/Brainrot-Programming-Language/blob/main/COMMAND.md)**

---

## 📂 Contoh Implementasi (MEWING 🤫🧏)

### 1. Struktur Kondisional (Conditional)

Berikut adalah contoh logika percabangan untuk menentukan bilangan positif atau negatif:

```text
skibidi n
bombaclat "Masukan angka broww!"
gyatt n

goofy n peak 0 :
    bombaclat "Angka Masukan adalah bilangan Positif"
sus n mid 0 :
    bombaclat "Angka Masukan adalah bilangan Negatif"
ahh
    bombaclat "Kamu masukin angka nol yahh"
stahp

danYappp
```

### 2. Struktur Perulangan (Looping)

Contoh penggunaan *loop* untuk mencetak teks secara berulang dengan interval tertentu:

```text
skibidi n
gyatt n
skibidi x is 1

lingaguliguli x cooked n * 10000 :
    bombaclat "Wilujeng Sumping."
    x +10000 aura
stahp

danYappp
```

---

## 🤝 Kontribusi & Lisensi

Proyek ini dikembangkan oleh **Muhammad 'Azmi Salam, Shakila Aulia, Repa Pitriani, Rifa Muhammad, Adwar Salman** sebagai bagian dari eksplorasi kreatif dalam pengembangan bahasa pemrograman.

* **Lisensi**: UPI (Universitas Pendidikan Indonesia)
* **Repositori**: [GitHub Project](https://github.com/zicofarry/Brainrot-Programming-Language)
* **Isu & Bug**: [Laporkan di sini](https://github.com/zicofarry/Brainrot-Programming-Language/issues)


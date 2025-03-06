// /* --------------------------------------------------------- */
// /* File Program : PTR1.CPP */
// /* Contoh pemakaian pointer */
// /* Tujuan : mengetahui panjang dan posisi variabel di memory */
// /* --------------------------------------------------------- */
// #include <stdio.h>
// int main(){
//     int x, y; // deklarsi variabel x dan y
//     int *px; // dekalrasi pointer px 
//     x = 87; // inisialisasi x dg value 87
//     px = &x; // px menunjuk alamat x
//     y = *px; // y diisi dg nilai yg ditunjuk oleh px
//     printf("Alamat x = %p\n", &x);
//     printf("Isi px = %d\n", x);
//     printf("Nilai yang ditunjuk oleh px = %d\n", *px);
//     printf("Nilai y = %d\n", y);
//     return 0;
// /* STUDI KASUS : */
// /* - Eksekusi file program tersebut dan pahami maksud program ini */
// /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
// /* - Tambahkan pernyataan untuk menampilkan Alamat varabel y, eksekusi, dan perhatikan hasilnya */
//     printf("Alamat y = %p\n", &y); //print alamat y
// /* - Bila pernyataan px = &x; diganti dengan y = *px; ,apa yang terjadi? */
// /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
// }
// // hasil pemahaman: pointer adalah variabel yg menyimpan alamat memori dari variabel lain




// /* --------------------------------------------------------- */
// /* File Program : PTR2.CPP */
// /* Contoh pemakaian pointer yang salah */
// /* Tujuan : mengetahui panjang dan posisi variabel di memory */
// /* --------------------------------------------------------- */
// #include <stdio.h>
// int main(){
//     float *pu; //deklarasi pointer pu bertipe float
//     float nu; //dekarasi variabel nu bertipe float
//     int u = 1234; // deklarasi variabel u bertipe integer dengan nilai 1234
//     pu = &u; // pu menunjuk alamat u
//     nu = *pu; // nu diisi nilai yg ditunjuk pu
//     // ^ beda tipe pointer seharusya variabel yg ditunjuk juga sma tipenya
//     printf("u = %d\n", u); // print nilai u
//     printf("nu = %f\n", nu); // print nilai nu
//     return 0;
// /* STUDI KASUS : */
// /* - Eksekusi file program tersebut dan pahami maksud program ini */
// /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
// /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
// }
// // hasil pemahaman: pointer harus sama tipe datanya dengan variabel yg ditunjuknya



// /* --------------------------------------------------------- */
// /* File Program : PTR3.CPP */
// /* Contoh pengubahan isi suatu variabel melalui pointer */
// /* Tujuan : Menggunakan type data pointer dan manipulasinya */
// /* --------------------------------------------------------- */
// #include <stdio.h>
// int main(){
//     float d, *pd; // deklarasi variabel float d, pointer float pd
//     d = 54.5; // inisialisasi d dg nilai 54.5
//     printf("Isi d semula = %g\n", d); // print nilai d
//     pd = &d; // pd menunjuk alamat d
//     *pd = *pd + 10; // nilai yg ditunjuk pd ditambah 10
//     printf("Isi d kini = %g\n", d); //print nilai d terbaru
//     return 0;
// /* STUDI KASUS : */
// /* - Eksekusi file program tersebut dan pahami maksud program ini */
// /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
// /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
// }
// // hasil pemahaman: nilai variabel yg ditunjuk oleh pointer bisa diubah dengan cara mengubah nilai yg dtunjuk oleh pointer tsb
// //                  pointer dapat digunakan untuk mengubah nilai variabel yang ditunjuk



// /* --------------------------------------------------------- */
// /* File Program : PTR4.CPP */
// /* Contoh pemakaian pointer */
// /* --------------------------------------------------------- */
// #include <stdio.h>
// int main(){
//     int z, s, *pz, *ps; // deklarasi variabel z,s, pointer pz, ps bertipe integer
//     z = 20; // inisialisasi z dg nilai 20
//     s = 30; // inisialisasi s dg nilai 30
//     pz = &z; // pz menunjuk alamat z
//     ps = &s; // ps menunjuk alamat s
//     *pz = *pz + *ps; // nilai yg ditunjuk pz ditambah nilai yg ditunjuk ps
//     printf("z = %d, s = %d\n", z , s); // print nilai z dan s
//     return 0;
// /* STUDI KASUS : */
// /* - Eksekusi file program tersebut dan pahami maksud program ini */
// /* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
// /* - Tulis hasil pemahaman Anda pada kertas yang disediakan */
// } 
// // hasil pemahaman: pointer dapat digunakan untuk melakukan operasi aritmatika pada variabel yang ditunjuk



// /* --------------------------------------------------------------------------------------------- */
// /* File Program : PTR5.CPP */
// /* Deskripsi : pointer ke type dasar, mendeklarasikan & alokasi variabel dinamik */
// /* --------------------------------------------------------------------------------------------- */
// #include <stdlib.h>
// #include <stdio.h>
// int main() {
//     /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
//     int i = 5, j; // deklarasi var i dan j sbg integer
//     char c = 'X'; // deklarasi var c sbg char
//     int *Ptri = (int *) malloc(4); // deklarasi pointer Ptri sbg integer
//     int *Ptrj = (int *) malloc(sizeof(int)); // deklarasi pointer Ptrj sb integer
//     float *fx = (float *) malloc(sizeof(float)); // deklarasi pointer fx sbg float
//     int A[5]; // deklarasi array A dg 5 elemen
//     float f = 7.23; // deklarasi var f sbg float dengan nilai 7.23
//     /* program */
//     *Ptri = 8; // nilai yg ditunjuk Ptri diisi 8
//     *Ptrj = 0; // nilai yg ditunjuk Ptrj diisi 0
//     *fx = 3; // nilai yg ditunjuk fx diisi 3
//     printf("Alamat i = %x \n", &i); 
//     printf("Nilai i = %d \n", i);
//     printf("Ukuran int = %d byte\n\n", sizeof(int));
//     printf("Alamat j = %x \n", &j);
//     printf("Nilai j = %d \n", j);
//     printf("Alamat c = %x \n", &c);
//     printf("Nilai c = %c \n", c);
//     printf("Ukuran char = %d byte\n\n", sizeof(char));
//     printf("Alamat Ptri = %x \n", &Ptri);
//     printf("Isi var Ptri = %x \n", Ptri);
//     printf("Nilai yang ditunjuk oleh Ptri = %d \n", *Ptri);
//     printf("Ukuran pointer int = %d byte\n\n", sizeof(int *));
//     printf("Alamat Ptrj = %x \n", &Ptrj);
//     printf("Isi var Ptrj = %x \n", Ptrj);
//     printf("Nilai yang ditunjuk oleh Ptrj = %d \n", *Ptrj);
//     Ptrj = Ptri; // Ptrj menunjuk alamat yg ditunjuk Ptri
//     printf("Isi var Ptrj sekarang = %x \n", Ptrj);
//     printf("Nilai yang ditunjuk oleh Ptrj sekarang = %d \n", *Ptrj);
//     printf("Alamat A = %x \n", &A);
//     printf("Isi var A = %x \n", A[0]);
//     printf("Ukuran array A = %d byte\n\n", sizeof(A));
//     printf("Alamat f = %x \n", &f);
//     printf("Nilai f = %f \n", f);
//     printf("Ukuran float = %d byte\n\n", sizeof(float));

//      // Menghapus alokasi memori untuk menghindari kebocoran memori
//      free(Ptri);
//      free(Ptrj);
//      free(fx);
//     return 0;
// }
// // hasil: Program ini menunjukkan penggunaan pointer untuk alokasi memori dinamis dan
// //        bagaimana mengakses serta memanipulasi data melalui pointer. Pastikan untuk
// //        selalu membebaskan memori yang dialokasikan untuk mencegah kebocoran memori.




// /* ----------------------------------------------------- */
// /* File Program : PTR6.CPP */
// /* Deskripsi : pointer yang menunjuk ke array */
// /* ---------------------------------------------------- */

// #include <stdio.h>

// int main() {
//     static int tgl_lahir[] = {18, 6, 1989}; // deklarasi array tgl_lahir
//     int *ptgl; // Deklarasi pointer yang akan menunjuk ke integer
//     ptgl = tgl_lahir; // Pointer ptgl menunjuk ke elemen pertama dari array tgl_lahir
//     printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl); // menampilkn nilai yg ditunjuk ptgl
//     printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[0]); // menampilkan nilai pertama dari tgl_lahir
//     for (int i = 0; i < 3; i++) { // loop u/ menampilkan seluruh elemen array tgl_lahir
//         printf("tgl_lahir[%d] = %d\n", i, *(ptgl + i)); // Mengakses elemen array menggunakan pointer
//     }
//     return 0;
// }
// /* STUDI KASUS : */
// /* Eksekusi dan pahami maksud program ini (tulis tujuan program ini) */
// /* Modifikasi program tersebut agar bisa menampilkan seluruh elemen array tgl_lahir !*/
// // Maksud Program: Program ini mendemonstrasikan penggunaan pointer untuk
// //                 mengakses elemen dari array. Pointer ptgl menunjuk ke elemen pertama dari array
// //                 tgl_lahir, dan program ini menampilkan nilai dari elemen pertama serta seluruh
// //                 elemen array menggunakan pointer.



// /* ----------------------------------------------------------- */
// /* File Program : PTR7.CPP */
// /* (Pointer dan String bagian ke-1) */
// /* Deskripsi : pointer yang menunjuk ke data string */
// /* ---------------------------------------------------------- */
// #include <stdio.h>
// int main(){
// /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
//     char *pkota = "BANDUNG"; // deklarasi pointer bertipe char pkota yg menunjuk ke string bandung
//     puts(pkota); // menampilkan string yg ditunjuk pkota; puts() = print string
//     return 0;
// }
// /* STUDI KASUS : */
// /* Apa perbedaan deklarasi variabel char *pkota='BANDUNG'; dengan char kota[]='BANDUNG' ?
// */
// // Perbedaan Deklarasi:

// // char *pkota = "BANDUNG"; mendeklarasikan pkota sebagai pointer yang menunjuk ke string literal. 
// //                          String ini bersifat read-only.
// // char kota[] = "BANDUNG"; mendeklarasikan kota sebagai array karakter yang menyimpan salinan dari string "BANDUNG".
// //                          Array ini dapat dimodifikasi.



// /* -------------------------------------------------------------------------------- */
// /* File Program : PTR8a.CPP */
// /* (Pointer dan String bagian ke-2) */
// /* Deskripsi : menukar isi dua buah string TANPA pemakaian pointer */
// /* ------------------------------------------------------------------------------- */
// #include <stdio.h>
// #include <string.h>
// #define PANJANG 20 // deklarasi konstanta PANJANG=20
// int main(){
// /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
//     char nama1[PANJANG] = "DEWI SARTIKA"; // deklarasi string nama1
//     char nama2[PANJANG] = "SULTAN HASANUDDIN"; // deklarasi string nama2
//     char namaX[PANJANG]; // deklarasi string namaX, dijadikan temp
//     puts("Nama semula : "); // print string
//     printf("Nama 1 --> %s\n", nama1); // print string nama1
//     printf("Nama 2 --> %s\n", nama2); // print string nama2
//     /* Pertukaran string */
//     strcpy(namaX, nama1); // copy string nama1 ke namaX
//     strcpy(nama1, nama2); // copy string nama2 ke nama1
//     strcpy(nama2, namaX); // copy string namaX ke nama2
//     puts("Nama sekarang : "); // print string
//     printf("Nama 1 --> %s\n", nama1); //print string nama1
//     printf("Nama 2 --> %s\n", nama2); // print string nama2
//     return 0;
// }
// // Maksud Program: Program ini menukar isi dua string tanpa menggunakan pointer.
// //                 Pertukaran dilakukan dengan menggunakan variabel sementara namaX untuk
// //                 menyimpan salah satu string selama proses pertukaran.



// /* ------------------------------------------------------------------------------------------------- */
// /* File Program : PTR8b.CPP */
// /* (Pointer dan String bagian ke-2) */
// /* Deskripsi : menukar isi dua buah string yang ditunjuk oleh pointer */
// /* PERHATIKAN! Bila dibandingkan dengan program PTR8A.cpp, maka dengan */
// /* pointer, penyalinan isi array tidak perlu dilakukan. Sehingga bisa menghemat waktu eksekusi. */
// /* ---------------------------------------------------------------------------------------------- */
// #include <stdio.h>
// int main(){
// /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
// char *nama1 = "DEWI SARTIKA"; // deklarasi pointer bertipe char nama1 yg menunjuk ke str dewi sartika
// char *nama2 = "SULTAN HASANUDDIN"; // deklarasi pointer bertp char nama2 yg mnunjuk ke str sultan hasanuddin
// char *namaX; // deklarasi pointer bertipe char namaX
// puts("Nama semula : "); // print str
// printf("Nama 1 --> %s\n", nama1); // print str nama1
// printf("Nama 2 --> %s\n", nama2); // print str nama2
// /* Penukaran string yang ditunjuk oleh pointer nama1 dan nama2 */
// namaX = nama1; // namaX menunjuk ke alamat yg ditunjuk nama1
// nama1 = nama2; // nama1 menunjuk ke alamat yg ditunjuk nama2
// nama2 = namaX; // nama2 menunjuk ke alamat yg ditunjuk namaX
// puts("Nama sekarang : "); // print str
// printf("Nama 1 --> %s\n", nama1); // print str nama1
// printf("Nama 2 --> %s\n", nama2); // print str nama2
// return 0;
// }
// // Maksud Program: Program ini menukar isi dua string yang ditunjuk oleh pointer tanpa
// //                 perlu menyalin isi string. Ini lebih efisien karena tidak memerlukan alokasi memori
// //                 tambahan untuk menyimpan salinan string.



// /* -------------------------------------------------- */
// /* File Program : PTR9.CPP */
// /* Deskripsi : pointer yang menunjuk pointer */
// /* -------------------------------------------------- */
// #include <stdio.h>
// int main(){
//     /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
//     int var_x = 273;
//     int *ptr1; /* ptr1 adl pointer yang menunjuk ke objek bertipe integer */
//     /* (Boleh disebut pointer integer saja) */
//     int **ptr2; /* ptr2 adl pointer yang menunjuk ke pointer yang menunjuk */
//     /* ke objek bertipe integer (Boleh disebut : pointer menunjuk ke pointer integer saja) */
//     ptr1 = &var_x; // ptr1 menunjuk ke alamat var_x
//     ptr2 = &ptr1; // ptr2 menunjuk ke alamat ptr1
//     /* Mengakses nilai var_x melalui ptr1 dan ptr2 */
//     printf("Nilai var_x = %d\n", *ptr1); // print nilai var_x melalui ptr1
//     printf("Nilai var_x = %d\n", **ptr2); // print nilai var_x melalui ptr2
//     return 0;
// }
// /* STUDI KASUS : */
// /* Eksekusi dan pahami maksud program ini dan */
// /* komentari setiap baris programnya (mulai dari baris ptr1= &var_x; ) */
// // Maksud Program: Program ini menunjukkan penggunaan pointer yang menunjuk ke
// //                 pointer. ptr1 menunjuk ke var_x, dan ptr2 menunjuk ke ptr1. Program ini
// //                 menampilkan nilai var_x dengan mengaksesnya melalui kedua pointer.



// /* -------------------------------------------------------------- */
// /* File : PTR10.cpp */
// /* Deskripsi : Pointer dan fungsi/prosedur */
// /* -------------------------------------------------------------- */
// #include <stdio.h>
// /* Prototype */
// void f1(void); 
// void f2(void);
// void f3(void);
// void f4(void);
// /* kamus Global */
// #define true 1 // define true 1
// #define false 0 // define false 0
// int quit = false; // deklarasi var quit dg nilai false
// int main(){
//     /* kamus lokal */
//     /* Definisi tabel yang elemennya adalah pointer ke fungsi */
//     /* Elemen tabel yang ke - i akan mengakses fungsi ke - i */
//     /* Pilihan menjadi indeks tabel, dan dipakai untuk mengaktifkan fungsi */
//     /* yang sesuai */
//     void (*tab[4]) () = {f1, f2, f3, f4}; /* Pointer ke procedure */ 
//     /* program */
//     printf("Pointer to function : \n");
// /* Menu */
//     do{
//         printf("Pilih salah satu : \n");
//         printf("1. Buka file hanya untuk baca \n");
//         printf("2. Tutup file \n");
//         printf("3. Edit file \n");
//         printf("4. Quit \n");
//         tab[getchar() - '1'] () ;
//         getchar(); /* untuk membuang return karakter */
//     } while (!quit); 
//     return 0;
// }
// /* Body Function */
// void f1 (){
//     printf("Ini fungsi f1 \n");
// }

// void f2 (){
//     printf("Ini fungsi f2 \n");
// }

// void f3 (){
//     printf("Ini fungsi f3 \n");
// }

// void f4 (){
//     quit = true;
//     printf("Quit ... \n");
// }
// // maksud program: program ini menunjukkan penggunaan pointer ke fungsi/prosedur.
// //                Program ini menampilkan menu yang memungkinkan pengguna untuk memilih
// //                fungsi yang akan dijalankan. Pilihan pengguna digunakan sebagai indeks
// //                u/ m'aktifkan fungsi yang sesuai dalam tabel pointer ke fungsi.



// /* ----------------------------------------------------------------------------- */
// /* File : PTR11.cpp */
// /* Deskripsi : Pointer ke function (Function sebagai parameter) */
// /* Melakukan offset terhadap tabel tergantung fungsi f */
// /* ----------------------------------------------------------------------------- */
// #include <stdio.h>
// /* Kamus Global */
// int N; /* ukuran efektif */
// /* Prototype, fungsi yang diberikan sebagai parameter aktual */
// int succ (int i); /* succ -> singkatan dari suksessor */
// int pred (int i); /* pred -> singkatan dari predesessor */
// /* Prosedur dengan parameter sebuah fungsi */
// void geser (int *TT, int (*f) (int)); // f adalah pointer ke fungsi, tt adalah pointer ke int 
// /* Program Utama */
// int main(){
//     /* kamus lokal */
//     int MyTab[10]; // deklarasi array MyTab
//     int i; // deklarasi var i
//     /* program */
//     N = 10; // inisialisasi N=10
//     for (i = 0; i < N; i++){ // loop u/ mengisi array MyTab
//         MyTab[i] = i; // isi array MyTab
//     }
//     printf("Isi tabel dalam main sebelum pemanggilan : \n");
//     for (i = 0; i < N; i++){ // loop u/ menampilkan isi array MyTab
//         printf(" %d ", MyTab[i]); // print isi array mytab
//     }
//     printf("\n");
//     /* Pakai geser dengan parameter succ */
//     printf("Geser dengan succ \n"); // print struing
//     geser (MyTab, succ); // panggil fungsi geser dengan param succ
//     printf(" dalam main \n"); // print string
//     for (i = 0; i < N; i++){ // loop u/ menampilkan isi array mytab
//         printf(" %d ", MyTab[i]); // print isi array mytab
//     }
//     printf("\n"); // print newline
//     /* Pakai geser dengan parameter pred */
//     printf("Geser dengan pred \n"); // print string
//     geser (MyTab, pred); // panggil fungsi geser dg param pred
//     printf(" dalam main setelah aplikasi pred \n"); // print string
//     for (i = 0; i < N; i++){ // loop u/ menampilkan isi array mytab
//         printf(" %d ", MyTab[i]); // print isi array m=ytab
//     }
//     printf("\n"); // print newline
//     return 0;
// }
// /* Body Function */
// int succ (int i){ //fungsi succ
//     return (i+1); // return nilai i+1
// }

// int pred (int i){ // fungsi pred
//     return (i-1); // return nilai i-1
// }
// void geser (int *TT, int (*f) (int)){ // prosedur geser dengan param tt pointer ke int, f pointer ke fungsi
//     int i; // deklarasi var i
//     printf(" dalam geser \n"); // print string
//     for (i = 0; i < N; i++){ // loop u/ menggeser isi array tt
//         TT[i] = f (TT[i]); // isi array tt dg nilai yg dikembalikan oleh fungsi f
//         printf(" %d ", TT[i]); // print isi array tt
//     }
//     printf("\n"); // print newline
// }
// // maksud program: program ini menunjukkan penggunaan pointer ke fungsi sbg parameter.
// //                 program ini menunjukkan bagaimana fungsi dapat digunakan sebagai paramater
// //                 aktual dalam prosedur. fungsi ini digunakan u/ menggeser isi array tergantung
// //                 fungsi yang diberikan sbg param aktual


// /* ------------------------------------------------------------------------------------------------------------------ */
// /* File : PTR12.cpp */
// /* Deskripsi : Pointer ke function (Procedure dengan parameter input/output sebagai parameter) */
// /* Melakukan offset terhadap tabel tergantung fungsi f */
// /* ------------------------------------------------------------------------------------------------------------------ */
// #include <stdio.h>
// /* Kamus Global */
// int N; /* ukuran efektif */
// /* Prototype, fungsi yang diberikan sebagai parameter aktual */
// void succ (int *i); /* suksessor, berupa procedure by ref */
// void pred (int *i); /* predesessor */
// /* Prosedur dengan parameter sebuah fungsi */
// void geser (int *TT, void (*f) (int *)); // tt adalah pointer ke int(disini array), f adalah pointer ke modul
// /* Program Utama */

// int main(){
//     /* kamus lokal */
//     int MyTab[10]; // deklar array MyTab
//     int i; // deklar var i
//     /* program */
//     N = 10; // inisialisasi N=10
//     for (i = 0; i < N; i++){ // loop u/ mengisi array mytab
//         MyTab[i] = i; // isi array mytab
//     }
//     printf("Isi tabel dalam main sebelum pemanggilan : \n"); // print str
//     for (i = 0; i < N; i++){ // loop u/ menampilkan isi array mytab
//         printf(" %d ", MyTab[i]); // print isi array mytab
//     }
//     printf("\n"); // print nextlin
//     /* Pakai geser dengan parameter succ */
//     printf("Geser dengan succ \n"); // prirnt str
//     geser (MyTab, succ); // panggil fungsi geser dg param succ
//     printf(" dalam main \n"); // print str
//     for (i = 0; i < N; i++){ // loop u/ mnampilkan isi array mytab
//         printf(" %d ", MyTab[i]); // print isi array mytab
//     }
//     printf("\n"); // print nextline
//     /* Pakai geser dengan parameter pred */
//     printf("Geser dengan pred \n"); // print str
//     geser (MyTab, pred); // panggil fungsi geser dg param pred
//     printf(" dalam main setelah aplikasi pred \n"); // print str
//     for (i = 0; i < N; i++){ // loop u/ mnampilkan isi array mytab
//         printf(" %d ", MyTab[i]); // print isi array mytab
//     }
//     printf("\n"); // print nextline
//     return 0;
// }

// /* Body Function */
// void succ (int *i){ // prosedur succ
//     *i = *i+1; // isi i dg i+1
// }
// void pred (int *i){ // proc pred
//     *i = *i-1; // isi i dg i-1
// }
// void geser (int *TT, void (*f) (int *)){ // proc geser dg param tt pointer ke int (disini array), f pointer ke modul
//     int i; // declare var i
//     printf(" dalam geser \n"); // print str
//     for (i = 0; i < N; i++){ // loop u/ menggeser isi array tt
//         f (&TT[i]); // isi array tt dg nilai yg dikembalikan oleh fungsi f
//     printf(" %d ", TT[i]); // print isi array tt
//     }
//     printf("\n"); // print nextline
// }
// // maksud program: program ini menunjukkan pgunaan pointer ke prosedur dg param input/output
// //                 program ini menunjukkan bagaimana prosedur dapat digunakan sbg param
// //                 aktual dalam proc. proc ini digunakan u/ mgeser isi array tergantung 
// //                 prosedur yg diberikan sbg param aktual
// //                 perbedaan dengan ptr11 adalah ptr11 mggunakan fungsi sbg param, sedangkan ptr12
// //                 menggunakan prosedur sbg param



/* ------------------------------------------------------------------------------------------------------------------ */
/* File : PTR13.cpp */
/* Deskripsi : Pointer ke function (Procedure dengan parameter input/output sebagai parameter) */
/* Melakukan offset terhadap tabel tergantung fungsi f */
/* ------------------------------------------------------------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>

// Kamus Global
int N; // ukuran efektif
enum MyType { bulat, karakter };

// Prototype
void succI(int *i); // suksessor, berupa procedure by ref
void predI(int *i); // predesessor
void succC(char *c); // suksessor, berupa procedure by ref
void predC(char *c); // predesessor
void printtab(void *T, enum MyType Ty); // print tabel yang belum ketahuan typenya
void geserInt(int *TT, void (*f)(int *)); // Prosedur dengan parameter sebuah fungsi untuk int
void geserChar(char *TT, void (*f)(char *)); // Prosedur dengan parameter sebuah fungsi untuk char

// Program Utama
int main() {
    // kamus lokal
    int *MyTabInt;
    char *MyTabC;
    int i;

    // program
    N = 10;
    MyTabInt = (int *)malloc(N * sizeof(int));
    MyTabC = (char *)malloc(N * sizeof(char));

    for (i = 0; i < N; i++) {
        MyTabInt[i] = i; // Mengisi array integer
        MyTabC[i] = 'Z'; // Mengisi array karakter
    }

    printf("Isi tabel dalam main sebelum pemanggilan : \n");
    printf(" Tabel integer \n");
    printtab(MyTabInt, bulat);
    printf(" Tabel karakter \n");
    printtab(MyTabC, karakter);
    printf("\n");

    // Pakai geser dengan parameter succ
    printf("Geser dengan succ \n");
    geserInt(MyTabInt, succI);
    geserChar(MyTabC, succC);
    printf(" dalam main \n");
    printf(" Tabel integer \n");
    printtab(MyTabInt, bulat);
    printf(" Tabel karakter \n");
    printtab(MyTabC, karakter);
    printf("\n");

    // Pakai geser dengan parameter pred
    printf("Geser dengan pred \n");
    geserInt(MyTabInt, predI);
    geserChar(MyTabC, predC);
    printf(" dalam main \n");
    printf(" Tabel integer \n");
    printtab(MyTabInt, bulat);
    printf(" Tabel karakter \n");
    printtab(MyTabC, karakter);
    printf("\n");

    // Bebaskan memori
    free(MyTabInt);
    free(MyTabC);

    return 0;
}

// Body Function
void succI(int *i) {
    *i = *i + 1;
}

void predI(int *i) {
    *i = *i - 1;
}

void succC(char *c) {
    *c = *c + 1;
}

void predC(char *c) {
    *c = *c - 1;
}

void geserInt(int *TT, void (*f)(int *)) {
    int i;
    printf(" dalam geser \n");
    for (i = 0; i < N; i++) {
        f(&TT[i]);
        printf(" %d ", TT[i]);
    }
    printf("\n");
}

void geserChar(char *TT, void (*f)(char *)) {
    int i;
    printf(" dalam geser \n");
    for (i = 0; i < N; i++) {
        f(&TT [i]);
        printf(" %c ", TT[i]);
    }
    printf("\n");
}

void printtab(void *T, enum MyType Ty) {
    int i;
    for (i = 0; i < N; i++) {
        switch (Ty) {
            case bulat: printf("%d ", *((int *)T + i)); break; // Konversi ke int* sebelum dereference
            case karakter: printf("%c ", *((char *)T + i)); break; // Konversi ke char* sebelum dereference
        }
    }
    printf("\n");
}
// maksud prgm: prgrm ini menunjjukkan penggunakan pointer ke fingsi u/ melakukan operasi pada array, dg menggunakan
//               fungsi sbg pram program ini dapat menggeser isi array tergantung fungsi yg diberikan sbg param aktual
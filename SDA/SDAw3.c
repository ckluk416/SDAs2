// /* ---------------------------------------------------------------------------------------------- */
// /* File Program : PTR14.CPP */
// /* Deskripsi : Array dinamis, dimana ukuran array ditentukan dari read keyboard */
// /* ---------------------------------------------------------------------------------------------- */
// #include <stdlib.h>
// #include <stdio.h>
// int main(){
//     /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
//     int *tab; // pointer ke integer 
//     /* deklarasi array, perhatikan belum tampak bedanya dg
//     deklarasi pointer biasa */
//     int N, i; // N ukuran array
//     /* program */
//     printf("Contoh mengisi array dinamis berukuran 0..N : \n"); // N ditenttukan dari kebooard
//     printf("N = "); // menanyakan ukuuran arra
//     scanf("%d", &N); // membaca ukuran array, disimpan di allamat N
//     printf("Alokasi setelah mengetahui ukuran array \n"); // alokasi arra
//     tab = (int *) malloc((N+1) *sizeof(int)); // alokasi array, ukuran array n+1
//     if (tab != NULL){ // Jika alokasi berhasil
//         for (i=0; i<=N; i++){ // loop u/ mengisi array
//             printf("i=%d tab[i]=%d \n", i, *(tab + i)); // print isi array dengan nilai yg diinpt serta alamatnya
//         };
//         printf("Akhir program \n"); // akhir prgram 
//         /* dealloc */
//         free(tab); /*dealokasi*/
//         return 0; 
//     }else{ // jika alokasi gagal
//         printf("Alokasi gagal ... \n");
//         return 1; 
//     }
//     return 0; 
// }
// // maksud program: proogram ini mendemonstrasikan penggunaan array dinamis, dimana ukuran
// //                 array ditentuukan dari input keyyboard. progrram ini juga menunjukkan
// //                 bagaimana alokasi dan dealokasi memori dilakukan pada array dinamis
// //                 menggunakan fungsi malloc() dan free()



/* ---------------------------------------------------------------------------------------------------------------- */
/* File Program : PTR15.CPP */
/* Deskripsi : Array of string : Pendefinisian dan pengaksesan. Perhatikanlah permasalahannya */
/* ---------------------------------------------------------------------------------------------------------------- */
// #include <stdlib.h>
// #include <stdio.h>
// int main(){
//     /* kamus */
//     /* Definisi array yang elemennya string, statik dan sekaligus mengisi */
//     static char *s[3] = {"the", "time", "is"}; // array statis yang berisi tiga string
//     /* Definisi array yang elemennya string, dinamik */
//     char *(*TabStr); /* Deklarasi array of string */ // Deklarasi Array Dinamis
//     // TabStr adalah pointer ke pointer vhar, yang akan digunakan u/mnyimpan arr str yang dialokasikan secara dinamis.
//     int i; // deklarasi var i

//     /* program */
//     for (i=0; i < 3; i++) { //cetak setiap string dari array statis s
//         printf("%s\n", s[i]); // priint issi array s
//     }
//     /* Alokasi TabStr sebanyak 3 */
//     TabStr = (char **) malloc (3 * sizeof(char *)); // alokasi array tabstr sebanyak 3
//     // memori dialokasikan untuk TabStr, yang akan menyimpan tiga pointer ke string
//     for (i=0; i < 3; i++) { // loop u/ mengisi array tabstr
//         /* Alokasi string yang merupakan elemen tabel */
//         *(TabStr + i) = (char *) malloc (5 * sizeof(char)); // alok str sebanyak 5
//         printf("\nInput Str[%d], maksimum 5 karakter : ", i);
//         scanf("%5s", *(TabStr+i)); /* Mengisi nilai string */
//         printf("\n Nilai Str[%d] : %5s\n ", i, *(TabStr + i)); // print nilai string
//     }


//     // dealok memori
//     for (i = 0; i < 3; i++) {
//         free(TabStr[i]); // Bebaskan memori untuk setiap string
//     }
//     free(TabStr); // Bebaskan memori untuk array TabStr


//     return 0;
// }
// // maksud prgram: program ini menunjuukkan penggunaan array of sring,  baik yang didefinisikan secara 
// //                statis maupun dinamis.



// /* ---------------------------------------------------------------------------------------------------------------- */
// /* File Program : PTR16CPP */
// /* Deskripsi : Array of string : Pendefinisian dan pengaksesan. Perhatikanlah permasalahannya */
// /* Jelaskan perbedaannya dengan program PTR15.cpp! */
// /* ---------------------------------------------------------------------------------------------------------------- */
// #include <stdlib.h>
// #include <stdio.h>
// #define STRING char* // define STRING sbg chhar*
// int main(){
//     /* kamus */
//     /* Definisi array yang elemennya string, statik dan sekaligus mengisi */
//     static STRING s[3] = {"the", "time", "is"}; // array statis yg brisi tiga string
//     /* Definisi array yang elemennya string, dinamik */
//     STRING (*TabStr); /* Deklarasi array of string */ // deklarasi array dinamis
//     int i; // declare var int t
//     /* program */
//     for (i=0; i < 3; i++) { /* Print isi s */ //cetak setiap string dari array statis s
//         printf("%s\n", s[i]);
//     }
//     /* Alokasi TabStr sebanyak 3 */
//     TabStr = (STRING *) malloc (3 * sizeof(STRING)); // alokasi array tabstr sebanyak 3 
//     for (i=0; i < 3; i++) { // loop u/ mengisi array tabstr
//     /* Alokasi string yang merupakan elemen tabel */
//         *(TabStr + i) = (STRING ) malloc (5 * sizeof(char)); // alok str sebanyak 5
//         printf("\nInput Str[%d], maksimum 5 karakter : ", i);
//         scanf("%5s", *(TabStr+i)); /* Mengisi nilai string */
//     printf("\n Nilai Str[%d] : %5s\n ", i, *(TabStr + i)); // print nilai string
//     }


//     // Bebaskan memori (tidak ada di kode ini, tetapi penting untuk ditambahkan)
//     for (i = 0; i < 3; i++) {
//         free(TabStr[i]); // Bebaskan memori untuk setiap string
//     }
//     free(TabStr); // Bebaskan memori untuk array TabStr


//     return 0;
// }
// // perbedaan dg ptr15 
// // - pada ptr15, tabstr dideclare sebagai char**, sedangkan pd ptr16, tabstr didecclare 
// //    sbg char* (dgn define, jjadi setiap pakai STRING sama dg char*)
// // - di ptr16, SSTRING (*TabStr); mendeclre tabstr sbg pointer ke STRING, ygg pada gilirannya
// //    adalah char* (pointer ke char), berarti tabstr adalah poiner ygg dapat digunakan u/ menyimpan 
// //    alamat dari string.
// //   pd ptr15, char *(*tabstr) secara explisit mendeclare tabstr sebagai dobel pointer, ygg jugga
// //    juga dapat digunakan u/ menimpan array dari sttring
// // - di ptr16, alokasi u/ tabstr dillakukan dg TabStr = (STRING *) malloc (3 * sizeof(STRING));
// //    Di sini, sizeof(STRING) akan menjadi sizeof(char*) yg mengalokasikn memori / 3 pointer ke char
// //   pd ptr15, lokasi memori dilakukan dengan TabStr = (char **) malloc (3 * sizeof(char *));
// //    yang juga mengalokasikan memori untuk 3 pointer ke karakter,
// //    tetapi lebih eksplisit dalam menunjukkan bahwa ini adalah pointer ke pointer.
// // - di ptr16, alok memori uu/ setiap sttring dilakukan dg 
// //    *(TabStr + i) = (STRING) malloc (5 * sizeof(char));, yang mengalokasikan memori 
// //    untuk 5 karakter untuk setiap string.
// //   pd ptr15, ini dilakukan dengan *(TabStr + i) = (char *) malloc (5 * sizeof(char));
// // Kesamaan
// // - keduua program melakuukan hal yg sama dalam hal fungsionalitas yaitu mendefinisikan array string,
// //    mencetak string statis, dan mengalok memori u/ string dinamis
// // - keduanya minnta inpuut dari uuser u/ mengisi string dan mencetak nilai yg dimasukkan
// // jadi, penggunaan define dalam ptr16 membuat kode lebih berssih dan mudah dibaca;
// //  meskipuun dua duanyya memiliki tujuan yyg sama, tapi cara mereka declare dan mengelola pointer
// //  sedikit berbeda;



// /* --------------------------------------------------------------------------------------------------------- */
// /* File Program : PTR17.CPP */
// /* Deskripsi : Array dengan def type:mengisi dg assignment, menulis */
// /* --------------------------------------------------------------------------------------------------------- */
// #include <stdlib.h>
// #include <stdio.h>
// int main(){
//     /* kamus */ /* Definisi tabel integer */
//     typedef struct {
//         int *T; /* array integernya */ // u/ menyimpan array inttegernyya
//         int N; /* Ukuran efektif */ // menyimpan ukuran array yg eektif
//     } tabint;
//     tabint MyTab; // deklarasi var mytab bertipe tabint
//     int i;

//     /* program */
//     printf("Tentukan ukuran tabel, maks 10 = ");
//     scanf("%d", &(MyTab.N));
//     MyTab.T = (int *) malloc (MyTab.N * sizeof(int)); // alok memori u/ array mytab
//     // Memori dialokasikan untuk array integer dengan ukuran MyTab.N. 
//     // Ini memungkinkan program untuk menyimpan N integer dalam array T.

//     /* isi dengan assignment */
//     for (i = 0; i < MyTab.N; i++) {
//         *(MyTab.T + i) = i;
//         printf("i = %d MyTab.T = %d \n", i, *(MyTab.T+i));
//     };
//     // loop ini mengisi setiap eleman dari array mytab.t dg nilai indexnya (0, 1, 2, .., N-1)
//     // dan mencetak nilai tsb

//     // dealok
//     free(MyTab.T); // bebaskan memori yyg dialok u/ arr mytab

//     return 0;
// }
// // maksuud program: ptr117 menunjjukkan cara menggunakan struct u/ mengelola arry dinamis




// /* ------------------------------------------------------------------------------------------------------------- */
// /* File Program : PTR18.CPP */
// /* Deskripsi : program array dinamis dan statis : mengisi dgn baca, menulis (Modular, program */
// /* passing parameter tabel/array */
// /* ------------------------------------------------------------------------------------------------------------- */
// #include<stdio.h>
// /* Definisi tabel integer */
// typedef struct {
//     int tab[10]; /* array integernya */ // aray statis dg max 10 elemne
//     int N; /* Ukuran efektif */ // int yg m4enyimpan ukuuran efektiff dari array(jumlah elemen yg digunakan)
// } tabint;
// /* Prototype */
// void incTab (tabint *T); /* Increment setiap elemen tabel */ // menerima pointer ke tabint dan akan menginc setiap elemen dlm arr
// void printTab (tabint T); /* Print tabel */ // menerima tabint sbg param dan akan memprint elemen2 dari array
// int main(){
//     /* kamus */
//     tabint T; // deklar vart t bertipe tabint
//     int i;
//     /* program */
//     T.N = 3; // ukuran efektif N diset jadi 3
//     printf("Isi dan print tabel untuk indeks 1..5 \n");
//     /* isi dari pembacaan */
//     for (i = 0; i < T.N; i++) {
//         printf("Input tabel ke -[%d] = ", i);
//         scanf ("%d", &(T.tab[i]));
//     };
//     /* Print : perhatikan passing parameter by value */
//     printTab(T); // dipanggil u/ mencetak elemen2 array, passing bt value
//     /* Increment : perhatikan passing parameter by reference */
//     incTab (&T); // passing by reff(pakai alamat T), yg akan meninc setiap elemen dalam arr
//     printTab (T); // print elemen2 array setelah diinc     
//     return 0;
// }
// /* Body prototype */
// void incTab(tabint *T){  // inc setiap elemen tabel
//     /* Increment setiap elemen tabel */
//     /* Kamus lokal */
//     int i;
//     /* Program */
//     for (i = 0; i < (*T).N; i++){
//         (*T).tab[i] = (*T).tab[i]+1; // inc setiap elemen
//     }
// }

// void printTab(tabint T){ // menerima tabint sbg param dan mencetak ssetiap elemen dari arr tab
//     /* Print setiap elemen tabel */
//     /* Kamus lokal */
//     int i;
//     /* Program untuk traversal print */
//     for (i = 0; i < T.N; i++){
//         printf("T[%d] = %d \n", i, T.tab[i]); // mencetak setiap elenmen
//     }
// }
// // maksud program: ptr18 mrnunjukan cara menggunakan struct u/ mengelola array statis dan melakukan
// //                  operasi pada arr teb dgn memanfaatkan pasing by ref dan value




/* --------------------------------------------------------------------------------------------------------- */
/* File Program : PTR19.CPP */
/* Deskripsi : Maksud program sama dengan PTR18.cpp. Cari perbedaannnya! */
/* --------------------------------------------------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>
/* Definisi tabel integer */
typedef struct {
    int *tab; /* array integernya */ // tab dideklare sbg pointer ke integer
    int N; /* Ukuran efektif */
} tabint;
/* Prototype */
void incTab (tabint *T); /* Increment setiap elemen tabel */
void printTab (tabint T); /* Print tabel */
int main(){ 
    /* kamus */
    tabint T; // dejkare var t bertipe tabint
    int i;
    /* program */
    T.tab = (int *) malloc (3*sizeof(int)); //  alok memori u/arr mytab
    T.N = 3; // ukuran efektif N diset jadi 3
    printf("Isi dan print tabel untuk indeks 1..3 \n");
    for (i = 0; i < T.N; i++) { /* isi dari pembacaan */
        printf("Input tabel ke -[%d] = ", i);
        scanf ("%d", &(T.tab[i]));
    };
    printTab(T); /* Print : perhatikan passing parameter by value */
    incTab (&T); /* Increment : perhatikan passing parameter by reference */
    printTab (T);

    free(T.tab);
    return 0;
}
/* Body prototype */
void incTab(tabint *T)
/* Increment setiap elemen tabel */
{ /* Kamus lokal */
    int i;
    /* Program */
    for (i = 0; i < (*T).N; i++){
        (*T).tab[i] = (*T).tab[i]+1;
    }
}
void printTab(tabint T) /* Print setiap elemen tabel */
{ /* Kamus lokal */
    int i;
    /* Program untuk traversal print */
    for (i = 0; i < T.N; i++){
        printf("T[%d] = %d \n", i, T.tab[i]);
    }
}
// perbedaan dg ptr18
// - definisi array, pd ptr18 array dideklar ssbg array statiss
//   pd ptr19, arr tab dideklar ssbg pointer ke integer, memori arry dialokasikan sscr dinamiss
//    menggunakan malloc
// - alokasi memori, pd ptr18 tidak ada alokai memoori dinamis, ukuran arr ditentukan scr statis
//    dalam struct
//   pd ptr19, memoori u/ arr dialok scr dinbamiss menggunakan maloc
// - ukuran efektif, di ptr18 ukuran efejtuf N diatur scr manual, tapi elemen max pada arr tab adalah 10
//   pd ptr19, ukuran efektif N sama diatur manual, tapi elenmen max pada tab dpt memiliki ukuran yg lebgih
//    fflekssibel karena dialokasi scr dinamis
// - dealok memori, karena 118 pakai array sstatis jadi tidak ada untuk pembebasan memoori sedangkan 119 ada karena pakai arr dinamis
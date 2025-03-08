// /*---------------------------------------------------------------------------*/
// /* File : PTR20.cpp */
// /* Deskripsi : contoh pendefinisian struct dan pointer ke struct */
// /* Dibuat oleh : Tim Dosen SDP */
// /* Tanggal : 13-09-2001 */
// /*---------------------------------------------------------------------------*/
// #include<stdlib.h>
// #include<stdio.h>
// int main(){ 
//     /* kamus */
//     /* cara 3 : INI yang membuat TYPE baru */
//     typedef struct { // deklarasi tipe struk dg nm Point
//         float x;
//         float y;
//     } Point; /* nama type */
//     Point *P2; /* deklarasi pointer ke struct */ 
//     Point *P3 = (Point *) malloc (sizeof (Point)); /* deklarasi alokasi */
//     /* program */
//     /* Cara 1 : mengacu elemen pointer ke struct */
//     printf("Titik P2, dengan P2->x dan P2->y : \n");
//     P2 = (Point *) malloc (sizeof(Point)); /* Alokasi */
//     P2->x = 9.12; /* Isi nilai komponen */
//     P2->y = 2.567;
//     printf("P2.x = %f \nP2.y = %f \n", P2->x, P2->y);
//     /* Cara 2 : Perhatikanlah tanda kurung, lihat prioritas () dibuku TC */

//     printf("titik p3, dg (*P3).x dan (*P3).y : \n");

//     (*P3).x = 0.5; /* Mendefinisikan isi */
//     (*P3).y = 10.5;
//     printf("P3.x = %f \nP3.y = %f \n", (*P3).x, (*P3).y);

//     free(P2);
//     free(P3);
//     return 0;
// }
// // maksud program: program ini menunjukkan cara mendefine struk dan pointer ke struk
// //                 program ini menunjukkan cara mengakses elemen struk melalui pointer
// // jadi, program ini sebenarnya hanya menunjukkan cara mendefinisikan struct dan pointer ke struct



/*----------------------------------------------------------------------------*/
/* File : PTR21.cpp */
/* Deskripsi : contoh deklarasi list dan pemakaian makro */
/* Dibuat oleh : Tim Dosen SDP */
/* Tanggal : 13-09-2001 */
/*----------------------------------------------------------------------------*/
#include<stdlib.h>
#include<stdio.h>
/*Definisi akses komponen type, standard kuliah Algoritma dan pemrograman*/
#define info(P) (P)->info // makro u/ mengakses info dari elemen list
#define next(P) (P)->next // makro u/ mengakses pointer ke elemen berikutnya
#define Nil NULL          // makro u/ menyatakan nilai null
/* Definisi TYPE global (sebenarnya untuk soal ini tidak perlu global) */
/* Element list linier */
typedef int infotype;               // ripe data u/ info list berupa integer
typedef struct tElmtlist *address; // alias u/ pointer ke elemen list
typedef struct tElmtlist {          // struct baru  untuk elemen list
    infotype info;                 // informasi yang disimpan dlm elemen
    address next;                  // pointer ke elemen berikutnya
} ElmtList;
/* Program Utama */
int main(){
    /* kamus */
    address First;   // pointer u/ menunjuk ke elemen pertama dari list
    address P, Q;    // pointer u/ elemen yg akan ditambahkan ke list
    /* program */
    /* Create list kosong */
    First = Nil;     // inisialisasi list kosong dg null
    /* Alokasi, insert as first elemen */
    P = (address) malloc(sizeof (ElmtList));  // alokasi memori u/ elemen baru
    info(P) = 10;                             // set nilai info elemen pertama menjadi 10
    next(P) = Nil;                            // set pointer next elemen pertama menjadi null
    First = P;                                // set fitst untuk menjuk ke elemen pertama
    /* Alokasi, insert as first elemen */
    Q = (address) malloc(sizeof (ElmtList));  // alokasi memori u/ elemen baru
    info(Q) = 20;                             // set nilai info elemen kedua menjadi 20
    next(Q) = Nil;                            // set pointer next elemen kedua menjadi null
    next(Q) = First;                          // set pointer next elemen kedua u/ menunjuk ke elemen pertama
    First = Q;                                // set first u/ menunjuk ke elemen kedua
    /* Alokasi, insert as first elemen */
    P = (address) malloc(sizeof (ElmtList));  // alokasi memori u/ elemen baru
    info(P) = 30;                             // set nilai info elemen ketiga menjadi 30
    next(P) = Nil;                            // setpointer next elemen ketiga menjadi null
    next(P) = First;                          // set pointer next elemen ketika u/ menunjuk ke elemen pertama
    First = P;                                // set fitst u/ menunjuk ke elemen ketiga
    printf("%d \n", info(next(next(First)))); 

    free(P);
    free(Q);
    return 0;
}
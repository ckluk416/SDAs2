#ifndef NRLL_H
#define NRLL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define info(P) (P)->info
#define next(P) (P)->next

typedef char* infotype;

typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;      
    address next; 
} ElmtList;


typedef struct {
    address First;
} NRLL;

void CreateList(NRLL *L);
void InsertAtLast(NRLL *L, infotype X);
void DeleteBetween(NRLL *L, infotype Y);
void DeallocateList(NRLL *L);

#endif
#ifndef DOUBLEPOINTERLINKEDLIST_H
#define DOUBLEPOINTERLINKEDLIST_H

#include "Book.h"
#include "Borrower.h"

typedef struct DPLNode {
    void* data; // Book or Borrower
    struct DPLNode* next;
    struct DPLNode* down; // For borrower list
} DPLNode;

typedef struct {
    DPLNode* head;
} DoublePointerLinkedList;

DoublePointerLinkedList* DPL_Create();
void DPL_InsertBook(DoublePointerLinkedList* list, Book* book);
void DPL_InsertBorrower(DoublePointerLinkedList* list, char* bookTitle, Borrower* borrower);
Book* DPL_FindBook(DoublePointerLinkedList* list, char* title);
void DPL_Destroy(DoublePointerLinkedList* list);

#endif
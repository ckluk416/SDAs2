#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "Book.h"
#include "Borrower.h"

typedef struct SLLNode {
    void* data; // Can be Book or Borrower
    struct SLLNode* next;
} SLLNode;

typedef struct {
    SLLNode* head;
} SinglyLinkedList;

SinglyLinkedList* SLL_Create();
void SLL_InsertBook(SinglyLinkedList* list, Book* book);
void SLL_InsertBorrower(SinglyLinkedList* list, Borrower* borrower);
void* SLL_RemoveFirst(SinglyLinkedList* list);
void SLL_Destroy(SinglyLinkedList* list);

#endif
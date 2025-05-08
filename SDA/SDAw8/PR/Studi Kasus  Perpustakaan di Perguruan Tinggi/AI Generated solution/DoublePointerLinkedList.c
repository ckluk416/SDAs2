#include "DoublePointerLinkedList.h"
#include <stdlib.h>
#include <string.h>

DoublePointerLinkedList* DPL_Create() {
    DoublePointerLinkedList* list = malloc(sizeof(DoublePointerLinkedList));
    list->head = NULL;
    return list;
}

void DPL_InsertBook(DoublePointerLinkedList* list, Book* book) {
    DPLNode* newNode = malloc(sizeof(DPLNode));
    newNode->data = book;
    newNode->next = list->head;
    newNode->down = NULL;
    list->head = newNode;
}

void DPL_InsertBorrower(DoublePointerLinkedList* list, char* bookTitle, Borrower* borrower) {
    DPLNode* current = list->head;
    while (current != NULL) {
        Book* book = (Book*)current->data;
        if (strcmp(book->title, bookTitle) == 0) {
            DPLNode* newBorrower = malloc(sizeof(DPLNode));
            newBorrower->data = borrower;
            newBorrower->next = NULL;
            newBorrower->down = current->down;
            current->down = newBorrower;
            return;
        }
        current = current->next;
    }
}

Book* DPL_FindBook(DoublePointerLinkedList* list, char* title) {
    DPLNode* current = list->head;
    while (current != NULL) {
        Book* book = (Book*)current->data;
        if (strcmp(book->title, title) == 0) {
            return book;
        }
        current = current->next;
    }
    return NULL;
}

void DPL_Destroy(DoublePointerLinkedList* list) {
    DPLNode* current = list->head;
    while (current != NULL) {
        DPLNode* next = current->next;
        
        // Free borrower list
        DPLNode* down = current->down;
        while (down != NULL) {
            DPLNode* nextDown = down->down;
            free(down->data);
            free(down);
            down = nextDown;
        }
        
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}
#include "SinglyLinkedList.h"
#include <stdlib.h>
#include <string.h>

SinglyLinkedList* SLL_Create() {
    SinglyLinkedList* list = malloc(sizeof(SinglyLinkedList));
    list->head = NULL;
    return list;
}

void SLL_InsertBook(SinglyLinkedList* list, Book* book) {
    SLLNode* newNode = malloc(sizeof(SLLNode));
    newNode->data = book;
    newNode->next = list->head;
    list->head = newNode;
}

void SLL_InsertBorrower(SinglyLinkedList* list, Borrower* borrower) {
    SLLNode* newNode = malloc(sizeof(SLLNode));
    newNode->data = borrower;
    newNode->next = list->head;
    list->head = newNode;
}

void* SLL_RemoveFirst(SinglyLinkedList* list) {
    if (list->head == NULL) return NULL;
    
    SLLNode* temp = list->head;
    void* data = temp->data;
    list->head = list->head->next;
    free(temp);
    return data;
}

void SLL_Destroy(SinglyLinkedList* list) {
    SLLNode* current = list->head;
    while (current != NULL) {
        SLLNode* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}
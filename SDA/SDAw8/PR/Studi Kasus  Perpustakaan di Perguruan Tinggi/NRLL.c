#include "NRLL.h"

void CreateList(NRLL *L) {
    L->First = NULL;
}

void InsertAtLast(NRLL *L, infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    P->info = strdup(X); 
    P->next = NULL;
    if (L->First == NULL) {
        L->First = P;
    } else {
        address current = L->First;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = P;
    }
}

void DeleteBetween(NRLL *L, infotype Y) {
    if (L->First == NULL) return;
    address current = L->First;
    address previous = NULL;
    while (current != NULL && strcmp(current->info, Y) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) return;
    if (previous == NULL) {
        L->First = current->next;
    } else {
        previous->next = current->next;
    }
    free(current->info);
    free(current);
}
void DeallocateList(NRLL *L) {
    address current = L->First;
    address temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->info);
        free(temp);
    }
    L->First = NULL;
}
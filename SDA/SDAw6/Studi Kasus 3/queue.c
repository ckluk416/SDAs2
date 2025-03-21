#include "queue.h"

void createQueue(Queue *Q){
    CreateList(&Q->list);
}

void enqueue(Queue *Q, infotype X){
    InsertAtLast(&Q->list, X);
}

void dequeue(Queue *Q){
    DeleteAtFirst(&Q->list);
}

int isQueueEmpty(Queue *Q){
    return (Q->list.First == NULL);
}

void printQueue(Queue *Q){
    address current = Q->list.First;
    if(current == NULL){
        printf("antrian kosonx.\n");
        return;
    }
    printf("antrian: ");
    while(current != NULL){
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

void DeallocateQueue(Queue *Q) {
    DeallocateList(&Q->list);
}
#ifndef QUEUE_H
#define QUEUE_H

#include "NRLL.h"

typedef struct{
    NRLL list;
} Queue;

void createQueue(Queue *Q);
void enqueue(Queue *Q, infotype X);
void dequeue(Queue *Q);
int isQueueEmpty(Queue *Q);
void printQueue(Queue *Q);
void DeallocateQueue(Queue *Q);

#endif
#ifndef STACK_H
#define STACK_H

#include "NRLL.h"

typedef struct{
    NRLL L;
} Stack;

void CreateStack(Stack *S);
void Push(Stack *S, infotype X);
void Pop(Stack *S);
infotype Top(Stack S);
int isEmpty(Stack S);
void DeallocateStack(Stack *S);

#endif 
#include "stack.h"

void CreateStack(Stack *S){
    CreateList(&S->L);
}

void Push(Stack *S, infotype X){
    InsertAtFirst(&S->L, X);
}

void Pop(Stack *S){
    DeleteAtFirst(&S->L);
}

infotype Top(Stack S){
    if (!isEmpty(S)){
        return S.L.First->info;
    }
    return NULL;
}

int isEmpty(Stack S){
    return S.L.First == NULL;
}

void DeallocateStack(Stack *S){
    DeallocateList(&S->L);
}

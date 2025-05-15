#include "bintree.h"

BinaryTree CreateTree(char info){
    return createNode(info);
}

bool IsEmpty(BinaryTree P){
    return P == NULL;
}

void PreOrderRecursive(BinaryTree P){
    if (P == NULL) return;
    printf("%c ", P->info);
    PreOrderRecursive(P->left);
    PreOrderRecursive(P->right);
}

void PreOrderNonRecursive(BinaryTree P){
    if (P == NULL) return;
    Node *stack[100];
    int top = -1;
    stack[++top] = P;

    while(top >= 0){
        Node *current = stack[top--];
        printf("%c ", current->info);
        if(current->right) stack[++top] = current->right;
        if(current->left) stack[++top] = current->left;    
    }
}

void PreOrder(BinaryTree P){
    PreOrderRecursive(P);
    // PreOrderNonRecursive(P);
}

void InOrderRecursive(BinaryTree P){
    if(P == NULL) return;
    InOrderRecursive(P->left);
    printf("%c ", P->info);
    InOrderRecursive(P->right);
}

void InOrderNonRecursive(BinaryTree P){
    if(P == NULL) return;
    Node *stack[100];
    int top = -1;
    Node *current = P;

    while(current != null || TOP >= 0){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%c ", current->info);
        current = current->right;
    }
}

void InOrder(BinaryTree P){
    InOrderRecursive(P);
    // InOrderNonRecursive(P);
}

void PostOrderRecursive(BinaryTree P){
    if(P == NULL) return;
    PostOrderRecursive(P->left);
    PostOrderRecursive(P->right);
    printf("%c ", P->info);
}

void PostOrderNonRecursive(BinaryTree P){
    if(P == NULL) return;
    Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = P;

    while(top1 >= 0){
        Node* current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left) stack1[++top1] = current->left;
        if (current->right) stack1[++top1] = current->right;
    }
    while(top2 >= 0){
        printf("%c ", stack2[top2--]->info);
    }
}

void PostOrder(BinaryTree P){
    PostOrderRecursive(P);
    // PostOrderNonRecursive(P);
}

void LevelOrder(BinaryTree P){
    if(P == NULL) return;
    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = P;

    while(front < rear){
        Node *current = queue[front++];
        printf("%c ", current->info);
        if(current->left) queue[rear++] = current ->left;
        if(current->right) queue[rear++] = curren->right;
    }
}

bool Search(BinaryTree P, char X){
    if(P == NULL) return false;
    if(P->info == X) return true;
    return Search(P->left, X) || Search(P->right, X);
}

int binElmt(BinaryTree P){
    if(P == NULL) return 0;
    return 1 + binElmt(P->left) + binElmt(P->right);
}

int binDaun(BinaryTree P){
    if(P == NULL) return 0;
    if(P->left == NULL && P->right == NULL) return 1;
    return binDaun(P->left) + binDaun(P->right);
}

int Level(BinaryTree P, char X, int level){
    if(P == NULL) return  -1;
    if(P->info -- X) return level;
    int leftLevel = Level(P->left, X, level + 1);
    if(leftLEvel != -1) return leftLevel;
    return Level(P->right, X, level + 1);
}

int Depth(BinaryTree P){
    if(P == NULL) return 0;
    int leftDepth = Depth(P->left);
    int rightDepth = Depth(P->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int Max(int Data1, int Data2){
    return (Data1 > Data2) ? Data1 : Data2;
}

void DeallocTree(BinaryTree P) {
    if (P == NULL) return;
    DeallocTree(P->left);
    DeallocTree(P->right);
    free(P);
}
#include "binarytree.h"

void CreateTree(BinaryTreeStatic *T){
    T->root = NIL;
    T->size = 0;
    for (int i = 0; i < JML_MAKS; i++){
        T->nodes[i].info = ' ';
        T->nodes[i].left = NIL;
        T->nodes[i].right = NIL;
    }
}

void PreOrderRecursive(BinaryTreeStatic *T, int idx){
    if (idx == NIL) return;
    printf("%c ", T->nodes[idx].info);
    PreOrderRecursive(T, T->nodes[idx].left);
    PreOrderRecursive(T, T->nodes[idx].right);
}

void PreOrderNonRecursive(BinaryTreeStatic *T){
    int stack[JML_MAKS], top = -1;
    if(T->root == NIL) return;
    stack[++top] = T->root;

    while (top >= 0){
        int idx = stack[top--];
        printf("%c ", T->nodes[idx].info);

        if(T->nodes[idx].right != NIL) stack[++top] = T->nodes[idx].right;
        if(T->nodes[idx].left != NIL) stack[++top] = T->nodes[idx].left;
    }
}

void InOrderRecursive(BinaryTreeStatic *T, int idx){
    if (idx == NIL) return;
    InOrderRecursive(T, T->nodes[idx].left);
    printf("%c ", T->nodes[idx].info);
    InOrderRecursive(T, T->nodes[idx].right);
}

void InOrderNonRecursive(BinaryTreeStatic *T){
    int stack[JML_MAKS], top = -1;
    int idx = T->root;

    while (idx != NIL || top >= 0){
        while (idx != NIL) {
            stack[++top] = idx;
            idx = T->nodes[idx].left;
        }
        idx = stack[top--];
        printf("%c ", T->nodes[idx].info);
        idx = T->nodes[idx].right;
    }
}

void PostOrderRecursive(BinaryTreeStatic *T, int idx){
    if (idx == NIL) return;
    PostOrderRecursive(T, T->nodes[idx].left);
    PostOrderRecursive(T, T->nodes[idx].right);
    printf("%c ", T->nodes[idx].info);
}

void PostOrderNonRecursive(BinaryTreeStatic *T){
    int stack1[JML_MAKS], stack2[JML_MAKS];
    int top1 = -1, top2 = -1;
    
    if (T->root == NIL) return;
    
    stack1[++top1] = T->root;

    while (top1 >= 0){
        int idx = stack1[top1--];
        stack2[++top2] = idx;

        if (T->nodes[idx].left != NIL) stack1[++top1] = T->nodes[idx].left;
        if (T->nodes[idx].right != NIL) stack1[++top1] = T->nodes[idx].right;
    }

    while (top2 >= 0){
        printf("%c ", T->nodes[stack2[top2--]].info);
    }
}

void LevelOrderNonRecursive(BinaryTreeStatic *T){
    int queue[JML_MAKS], front = 0, rear = 0;
    if (T->root == NIL) return;
    
    queue[rear++] = T->root;

    while (front < rear){
        int idx = queue[front++];
        printf("%c ", T->nodes[idx].info);

        if (T->nodes[idx].left != NIL) queue[rear++] = T->nodes[idx].left;
        if (T->nodes[idx].right != NIL) queue[rear++] = T->nodes[idx].right;
    }
}

bool Search(BinaryTreeStatic *T, char X){
    for (int i = 0; i < T->size; i++) {
        if (T->nodes[i].info == X) return true;
    }
    return false;
}

int bElmt(BinaryTreeStatic *T){
    return T->size;
}

int bDaun(BinaryTreeStatic *T){
    int count = 0;
    for (int i = 0; i < T->size; i++){
        if (T->nodes[i].left == NIL && T->nodes[i].right == NIL)
            count++;
    }
    return count;
}

int Level(BinaryTreeStatic *T, char X, int level){
    for (int i = 0; i < T->size; i++){
        if (T->nodes[i].info == X) return level;
    }
    return -1;
}

int Depth(BinaryTreeStatic *T, int idx){
    if (idx == NIL) return 0;
    int leftDepth = Depth(T, T->nodes[idx].left);
    int rightDepth = Depth(T, T->nodes[idx].right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
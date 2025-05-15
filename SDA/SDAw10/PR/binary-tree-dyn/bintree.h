#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    char info;
    struct Node *left, *right;
} Node;

typedef Node *BinaryTree;

Node *createNode(char info){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->info = info;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BinaryTree CreateTree(char info);
bool IsEmpty(BinaryTree P);
void PreOrder(BinaryTree P);
void InOrder(BinaryTree P);
void PostOrder(BinaryTree P);
void LevelOrder(BinaryTree P);
bool Search(BinaryTree P, char X);
int binElmt(BinaryTree P);
int binDaun(BinaryTree P);
int Level(BinaryTree P, char X, int level);
int Depth(BinaryTree P);
int Max(int Data1, int Data2);
void DeallocTree(BinaryTree P);

#endif

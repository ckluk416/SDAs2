#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdbool.h>

#define JML_MAKS 20
#define NIL -1 

typedef struct{
    char info;
    int left, right;
} bTreeNode;

typedef struct{
    bTreeNode nodes[JML_MAKS];
    int root; 
    int size; 
} BinaryTreeStatic;

void CreateTree(BinaryTreeStatic *T);

void PreOrderRecursive(BinaryTreeStatic *T, int idx);
void PreOrderNonRecursive(BinaryTreeStatic *T);
void InOrderRecursive(BinaryTreeStatic *T, int idx);
void InOrderNonRecursive(BinaryTreeStatic *T);
void PostOrderRecursive(BinaryTreeStatic *T, int idx);
void PostOrderNonRecursive(BinaryTreeStatic *T);
void LevelOrderNonRecursive(BinaryTreeStatic *T);

bool Search(BinaryTreeStatic *T, char X);
int bElmt(BinaryTreeStatic *T);
int bDaun(BinaryTreeStatic *T);
int Level(BinaryTreeStatic *T, char X, int level);
int Depth(BinaryTreeStatic *T, int idx);

#endif
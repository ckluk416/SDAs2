#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    char info;
    struct Node *left, *right;
} Node;

Node* createNode(char info);
void insertNode(Node **root, char info, const char *path);
Node* searchNode(Node *root, char info);
void inOrder(Node *root);
void deallocateTree(Node *root);

#endif
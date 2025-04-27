#include <stdio.h>
#include <stdlib.h>
#include "nontree.h"

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// Fungsi untuk membebaskan tree
void freeTree(Node* root) {
    if (root == NULL) return;

    // Bebaskan anak pertama
    freeTree(root->firstChild);
    // Bebaskan saudara berikutnya
    freeTree(root->nextSibling);

    // Bebaskan node ini
    free(root);
}

#include <stdio.h>
#include <stdlib.h>
#include "traversal.h"
#include "nontree.h"

void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->value);
    preorderTraversal(root->firstChild);
    preorderTraversal(root->nextSibling);
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->firstChild);
    printf("%d ", root->value);
    inorderTraversal(root->nextSibling);
}

void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->firstChild);
    postorderTraversal(root->nextSibling);
    printf("%d ", root->value);
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* node = queue[front++];
        printf("%d ", node->value);

        if (node->firstChild) queue[rear++] = node->firstChild;
        Node* sibling = node->firstChild;
        while (sibling) {
            if (sibling->nextSibling) queue[rear++] = sibling->nextSibling;
            sibling = sibling->nextSibling;
        }
    }
}
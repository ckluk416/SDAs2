#include "binary_tree.h"

Node* createNode(char info){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = info;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertNode(Node **root, char info, const char *path) {
    if (*root == NULL) *root = createNode(' ');

    Node *current = *root;
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == '.') {
            if (current->left == NULL) current->left = createNode(' ');
            current = current->left;
        } else if (path[i] == '-') {
            if (current->right == NULL) current->right = createNode(' ');
            current = current->right;
        }
    }
    current->info = info;
}

Node* searchNode(Node *root, char info) {
    if (root == NULL) return NULL;

    if (root->info == info) {
        printf("Found: %c\n", info);
        return root;
    }

    Node *leftSearch = searchNode(root->left, info);
    if (leftSearch) return leftSearch;

    return searchNode(root->right, info);
}

void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    if (root->info != ' ') printf("%c ", root->info);
    inOrder(root->right);
}

void deallocateTree(Node *root) {
    if (root == NULL) return;
    deallocateTree(root->left);
    deallocateTree(root->right);
    free(root);
}
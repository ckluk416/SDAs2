#include <stdio.h>
#include "traversal.h"
#include "nontree.h"

int main() {
    Node* root = createNode(1);
    root->firstChild = createNode(2);
    root->firstChild->nextSibling = createNode(3);
    root->firstChild->firstChild = createNode(4);
    root->firstChild->firstChild->nextSibling = createNode(5);

    printf("Preorder Traversal:\n");
    preorderTraversal(root);

    printf("\nInorder Traversal:\n");
    inorderTraversal(root);

    printf("\nPostorder Traversal:\n");
    postorderTraversal(root);

    printf("\nLevel Order Traversal:\n");
    levelOrderTraversal(root);

    freeTree(root);

    return 0;
}
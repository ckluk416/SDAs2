#ifndef NONTREE_H
#define NONTREE_H

// Struktur Node untuk Non-Binary Tree
typedef struct Node {
    int value;
    struct Node* firstChild;  // Anak pertama
    struct Node* nextSibling; // Saudara berikutnya
} Node;

// Fungsi untuk membuat node baru
Node* createNode(int value);

// Fungsi untuk membebaskan tree dari memori
void freeTree(Node* root);


#endif
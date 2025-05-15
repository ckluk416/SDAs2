#ifndef MORSE_TREE_H
#define MORSE_TREE_H

#include "binary_tree.h"

void buildMorseTree(Node **root);
void findMorseCode(Node *root, char target, char *path, int depth, char *result);
char* convertToMorse(Node *root, const char *text);
void convertFileToMorse(Node *root, const char *inputFile, const char *outputFile);

#endif
#include "morse_tree.h"
#include <ctype.h>
#include <string.h>

void buildMorseTree(Node **root) {
    insertNode(root, 'A', ".-");
    insertNode(root, 'B', "-...");
    insertNode(root, 'C', "-.-.");
    insertNode(root, 'D', "-..");
    insertNode(root, 'E', ".");
    insertNode(root, 'F', "..-.");
    insertNode(root, 'G', "--.");
    insertNode(root, 'H', "....");
    insertNode(root, 'I', "..");
    insertNode(root, 'J', ".---");
    insertNode(root, 'K', "-.-");
    insertNode(root, 'L', ".-..");
    insertNode(root, 'M', "--");
    insertNode(root, 'N', "-.");
    insertNode(root, 'O', "---");
    insertNode(root, 'P', ".--.");
    insertNode(root, 'Q', "--.-");
    insertNode(root, 'R', ".-.");
    insertNode(root, 'S', "...");
    insertNode(root, 'T', "-");
    insertNode(root, 'U', "..-");
    insertNode(root, 'V', "...-");
    insertNode(root, 'W', ".--");
    insertNode(root, 'X', "-..-");
    insertNode(root, 'Y', "-.--");
    insertNode(root, 'Z', "--..");
}

void findMorseCode(Node *root, char target, char *path, int depth, char *result) {
    if (root == NULL) return;

    if (root->info == target) {
        path[depth] = '\0';
        strcat(result, path); 
        strcat(result, " ");
        return;
    }

    if (root->left) {
        path[depth] = '.';
        findMorseCode(root->left, target, path, depth + 1, result);
    }

    if (root->right) {
        path[depth] = '-';
        findMorseCode(root->right, target, path, depth + 1, result);
    }
}

char* convertToMorse(Node *root, const char *text) {
    static char morseResult[256];
    char path[10];
    morseResult[0] = '\0';

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            strcat(morseResult, "  ");
            continue;
        }

        char uppercaseChar = toupper(text[i]);
        findMorseCode(root, uppercaseChar, path, 0, morseResult);
    }

    return morseResult;
}

void convertFileToMorse(Node *root, const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");
    char line[256];

    if (!in || !out) {
        printf("Error membuka file.\n");
        return;
    }

    while (fgets(line, sizeof(line), in)) {
        char *morseCode = convertToMorse(root, line);
        fprintf(out, "Morse: %s\n", morseCode);
    }

    fclose(in);
    fclose(out);
}
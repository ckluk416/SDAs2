#include "morse_tree.h"

int main() {
    Node *morseTree = NULL;
    buildMorseTree(&morseTree);

    printf("Traversal InOrder:\n");
    inOrder(morseTree);
    printf("\n");

    printf("\nKonversi ke Morse:\n");
    char *morseCode = convertToMorse(morseTree, "JTK Politeknik Negeri Bandung");
    printf("%s\n", morseCode);

    convertFileToMorse(morseTree, "input.txt", "output.txt");

    deallocateTree(morseTree);
    return 0;
}
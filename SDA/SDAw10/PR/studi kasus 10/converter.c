#include "converter.h"
#include <string.h>
#include <ctype.h>

void BuildTreeFromData(Isi_Tree P) {
    CreateTree(P, 38);
    
    P[1] = (nbtree){' ', 2, NIL, NIL}; // root
    P[2] = (nbtree){'X', 4, 3, 1};
    P[3] = (nbtree){'L', 6, NIL, 1};
    P[4] = (nbtree){'E', 8, 5, 2};
    P[5] = (nbtree){'K', 10, NIL, 2};
    P[6] = (nbtree){'Y', 12, 7, 3};
    P[7] = (nbtree){'G', 14, NIL, 3};
    P[8] = (nbtree){'8', 16, 9, 4};
    P[9] = (nbtree){'D', 18, NIL, 4};
    P[10] = (nbtree){'0', 20, 11, 5};
    P[11] = (nbtree){' ', 22, NIL, 5}; //spasi
    P[12] = (nbtree){'R', 23, 13, 6};
    P[13] = (nbtree){'H', 25, NIL, 6};
    P[14] = (nbtree){'O', 27, 15, 7};
    P[15] = (nbtree){'U', 29, NIL, 7};
    P[16] = (nbtree){'N', NIL, 17, 8};
    P[17] = (nbtree){'4', 31, NIL, 8};
    P[18] = (nbtree){'1', NIL, 19, 9};
    P[19] = (nbtree){'6', NIL, NIL, 9};
    P[20] = (nbtree){'T', NIL, 21, 10};
    P[21] = (nbtree){'2', 32, NIL, 10};
    P[22] = (nbtree){'V', 33, 38, 11};
    P[23] = (nbtree){'P', NIL, 24, 12};
    P[24] = (nbtree){'5', 35, NIL, 12};
    P[25] = (nbtree){'A', 36, 26, 13};
    P[26] = (nbtree){'J', NIL, NIL, 13};
    P[27] = (nbtree){'B', NIL, 28, 14};
    P[28] = (nbtree){'I', NIL, NIL, 14};
    P[29] = (nbtree){'9', 37, 30, 15};
    P[30] = (nbtree){'3', NIL, NIL, 15};
    P[31] = (nbtree){'Z', NIL, NIL, 17};
    P[32] = (nbtree){'W', NIL, NIL, 21};
    P[33] = (nbtree){'C', NIL, 34, 22};
    P[34] = (nbtree){'7', NIL, NIL, 22};
    P[35] = (nbtree){'Q', NIL, NIL, 24};
    P[36] = (nbtree){'S', NIL, NIL, 25};
    P[37] = (nbtree){'F', NIL, NIL, 29};
    P[38] = (nbtree){'M', NIL, NIL, 11};
}

void CharToCode(Isi_Tree P, char character, char* code) {
    char upperChar = toupper(character);
    
    for (int i = 1; i <= 38; i++) {
        if (toupper(P[i].info) == upperChar) {

            int current = i;
            int parent = P[current].ps_pr;
            int len = 0;
            char temp[20] = {0};
            
            while (parent != NIL) {
                if (P[parent].ps_fs == current) {
                    temp[len++] = 'L';
                } else {
                    
                    int nb = P[parent].ps_fs;
                    while (nb != NIL && nb != current) {
                        nb = P[nb].ps_nb;
                        temp[len++] = 'R';
                    }
                }
                current = parent;
                parent = P[current].ps_pr;
            }
            
            
            for (int j = 0; j < len; j++) {
                code[j] = temp[len - 1 - j];
            }
            code[len] = '\0';
            return;
        }
    }
    
    
    strcpy(code, "?");
}

void StringToCode(Isi_Tree P, const char* input, char* output) {
    char code[20];
    output[0] = '\0'; 
    
    for (int i = 0; input[i] != '\0'; i++) {
        CharToCode(P, input[i], code);
        strcat(output, code);
        if (input[i+1] != '\0') {
            strcat(output, " "); 
        }
    }
}

char CodeToChar(Isi_Tree P, const char* code) {
    int current = 1; 
    int i = 0;
    
    while (code[i] != '\0' && current != NIL) {
        if (code[i] == 'L') {
            current = P[current].ps_fs;
        } else if (code[i] == 'R') {
            if (P[current].ps_nb != NIL) {
                current = P[current].ps_nb;
            } else {
                return '?';
            }
        } else {
            return '?';
        }
        i++;
    }
    
    if (current != NIL && P[current].info != ' ') {
        return P[current].info;
    } else {
        return '?';
    }
}

void CodeToString(Isi_Tree P, const char* input, char* output) {
    char tempCode[20] = {0};
    int codePos = 0;
    int outPos = 0;
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            
            tempCode[codePos] = '\0';
            output[outPos++] = CodeToChar(P, tempCode);
            codePos = 0;
        } else if (input[i] == 'L' || input[i] == 'R') {
            tempCode[codePos++] = input[i];
        }
    }
    
    
    if (codePos > 0) {
        tempCode[codePos] = '\0';
        output[outPos++] = CodeToChar(P, tempCode);
    }
    
    output[outPos] = '\0'; 
}
#ifndef CONVERTER_H
#define CONVERTER_H

#include "nbtrees.h"

void BuildTreeFromData(Isi_Tree P);
void CharToCode(Isi_Tree P, char character, char* code);
void StringToCode(Isi_Tree P, const char* input, char* output);
char CodeToChar(Isi_Tree P, const char* code);
void CodeToString(Isi_Tree P, const char* input, char* output);

#endif
#ifndef BOOK_H
#define BOOK_H

#include <stdbool.h>

typedef struct {
    char* title;
    int stock;
    void* borrowerList; // Pointer to borrower list (type varies by representation)
} Book;

#endif
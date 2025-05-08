#ifndef ARRAYREPRESENTATION_H
#define ARRAYREPRESENTATION_H

#include "Book.h"
#include "Borrower.h"

#define MAX_BOOKS 100

typedef struct {
    Book* books[MAX_BOOKS];
    int count;
} LibraryArray;

LibraryArray* AR_Create();
void AR_AddBook(LibraryArray* library, Book* book);
void AR_AddBorrower(LibraryArray* library, char* bookTitle, Borrower* borrower);
Book* AR_FindBook(LibraryArray* library, char* title);
void AR_Destroy(LibraryArray* library);

#endif
#include "ArrayRepresentation.h"
#include <stdlib.h>
#include <string.h>

LibraryArray* AR_Create() {
    LibraryArray* library = malloc(sizeof(LibraryArray));
    library->count = 0;
    for (int i = 0; i < MAX_BOOKS; i++) {
        library->books[i] = NULL;
    }
    return library;
}

void AR_AddBook(LibraryArray* library, Book* book) {
    if (library->count >= MAX_BOOKS) return;
    
    library->books[library->count] = book;
    library->count++;
}

void AR_AddBorrower(LibraryArray* library, char* bookTitle, Borrower* borrower) {
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i]->title, bookTitle) == 0) {
            SinglyLinkedList* borrowerList = (SinglyLinkedList*)library->books[i]->borrowerList;
            if (borrowerList == NULL) {
                borrowerList = SLL_Create();
                library->books[i]->borrowerList = borrowerList;
            }
            SLL_InsertBorrower(borrowerList, borrower);
            return;
        }
    }
}

Book* AR_FindBook(LibraryArray* library, char* title) {
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i]->title, title) == 0) {
            return library->books[i];
        }
    }
    return NULL;
}

void AR_Destroy(LibraryArray* library) {
    for (int i = 0; i < library->count; i++) {
        if (library->books[i]->borrowerList != NULL) {
            SLL_Destroy((SinglyLinkedList*)library->books[i]->borrowerList);
        }
        free(library->books[i]->title);
        free(library->books[i]);
    }
    free(library);
}
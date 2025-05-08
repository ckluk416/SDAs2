#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include "Book.h"
#include "Borrower.h"

typedef enum { 
    REPRESENTATION_SLL, 
    REPRESENTATION_DPL, 
    REPRESENTATION_ARRAY 
} RepresentationType;

typedef struct {
    void* libraryData; // The actual library data structure
    RepresentationType type;
} LibraryManager;

LibraryManager* LM_Create(RepresentationType type);
void LM_AddBook(LibraryManager* manager, char* title, int stock);
void LM_AddBorrower(LibraryManager* manager, char* bookTitle, char* name, Priority priority);
Book* LM_BorrowBook(LibraryManager* manager, char* bookTitle);
void LM_ReturnBook(LibraryManager* manager, char* bookTitle);
void LM_CancelBorrow(LibraryManager* manager, char* bookTitle, char* borrowerName);
void LM_Destroy(LibraryManager* manager);
void LM_PrintStatus(LibraryManager* manager);

#endif
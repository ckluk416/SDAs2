#include "LibraryManager.h"
#include <stdlib.h>
#include <string.h>

LibraryManager* LM_Create(RepresentationType type) {
    LibraryManager* manager = malloc(sizeof(LibraryManager));
    manager->type = type;
    
    switch (type) {
        case REPRESENTATION_SLL:
            manager->libraryData = SLL_Create();
            break;
        case REPRESENTATION_DPL:
            manager->libraryData = DPL_Create();
            break;
        case REPRESENTATION_ARRAY:
            manager->libraryData = AR_Create();
            break;
    }
    
    return manager;
}

void LM_AddBook(LibraryManager* manager, char* title, int stock) {
    Book* book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->stock = stock;
    book->borrowerList = NULL;
    
    switch (manager->type) {
        case REPRESENTATION_SLL:
            SLL_InsertBook((SinglyLinkedList*)manager->libraryData, book);
            break;
        case REPRESENTATION_DPL:
            DPL_InsertBook((DoublePointerLinkedList*)manager->libraryData, book);
            break;
        case REPRESENTATION_ARRAY:
            AR_AddBook((LibraryArray*)manager->libraryData, book);
            break;
    }
}

void LM_AddBorrower(LibraryManager* manager, char* bookTitle, char* name, Priority priority) {
    Borrower* borrower = malloc(sizeof(Borrower));
    borrower->name = strdup(name);
    borrower->priority = priority;
    
    switch (manager->type) {
        case REPRESENTATION_SLL: {
            SinglyLinkedList* list = (SinglyLinkedList*)manager->libraryData;
            // Implementation for SLL would need to find the right book first
            break;
        }
        case REPRESENTATION_DPL:
            DPL_InsertBorrower((DoublePointerLinkedList*)manager->libraryData, bookTitle, borrower);
            break;
        case REPRESENTATION_ARRAY:
            AR_AddBorrower((LibraryArray*)manager->libraryData, bookTitle, borrower);
            break;
    }
}

// Other functions would be implemented similarly...

void LM_Destroy(LibraryManager* manager) {
    switch (manager->type) {
        case REPRESENTATION_SLL:
            SLL_Destroy((SinglyLinkedList*)manager->libraryData);
            break;
        case REPRESENTATION_DPL:
            DPL_Destroy((DoublePointerLinkedList*)manager->libraryData);
            break;
        case REPRESENTATION_ARRAY:
            AR_Destroy((LibraryArray*)manager->libraryData);
            break;
    }
    free(manager);
}
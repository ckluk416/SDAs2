#include <stdio.h>
#include <stdlib.h>
#include "LibraryManager.h"

void printMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Add Borrower\n");
    printf("3. Borrow Book\n");
    printf("4. Return Book\n");
    printf("5. Cancel Borrow\n");
    printf("6. Print Status\n");
    printf("7. Change Representation\n");
    printf("8. Exit\n");
    printf("Choose option: ");
}

void printRepresentationMenu() {
    printf("\nSelect Data Representation:\n");
    printf("1. Singly Linked List\n");
    printf("2. Double Pointer Linked List\n");
    printf("3. Array\n");
    printf("Choose representation: ");
}

int main() {
    RepresentationType currentRep = REPRESENTATION_SLL;
    LibraryManager* manager = LM_Create(currentRep);
    
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        
        char title[100], name[100];
        int stock, priorityChoice;
        
        switch (choice) {
            case 1:
                printf("Enter book title: ");
                scanf("%s", title);
                printf("Enter stock: ");
                scanf("%d", &stock);
                LM_AddBook(manager, title, stock);
                break;
                
            case 2:
                printf("Enter book title: ");
                scanf("%s", title);
                printf("Enter borrower name: ");
                scanf("%s", name);
                printf("Enter priority (1-Student, 2-Teacher, 3-Public): ");
                scanf("%d", &priorityChoice);
                LM_AddBorrower(manager, title, name, priorityChoice-1);
                break;
                
            case 3:
                printf("Enter book title to borrow: ");
                scanf("%s", title);
                Book* borrowed = LM_BorrowBook(manager, title);
                if (borrowed) {
                    printf("Book '%s' borrowed successfully.\n", borrowed->title);
                } else {
                    printf("No available copy or no eligible borrower.\n");
                }
                break;
                
            case 4:
                printf("Enter book title to return: ");
                scanf("%s", title);
                LM_ReturnBook(manager, title);
                printf("Book returned.\n");
                break;
                
            case 5:
                printf("Enter book title: ");
                scanf("%s", title);
                printf("Enter borrower name to cancel: ");
                scanf("%s", name);
                LM_CancelBorrow(manager, title, name);
                break;
                
            case 6:
                LM_PrintStatus(manager);
                break;
                
            case 7:
                printRepresentationMenu();
                scanf("%d", &choice);
                if (choice >= 1 && choice <= 3) {
                    RepresentationType newRep = choice - 1;
                    if (newRep != currentRep) {
                        LM_Destroy(manager);
                        currentRep = newRep;
                        manager = LM_Create(currentRep);
                        printf("Representation changed.\n");
                    }
                }
                break;
                
            case 8:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);
    
    LM_Destroy(manager);
    return 0;
}
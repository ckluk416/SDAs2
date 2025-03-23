#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "NRLL.h"

void displayMenu(){
    printf("=== Menu Riwayat Kunjungan Website ===\n");
    printf("1. tambah website baru ke riwayat kunjungan\n");
    printf("2. cek riwayat website\n");
    printf("3. hapus riwayat website terbaru\n");
    printf("4. hapus riwayat website terlama\n");
    printf("5. keluar\n");
    printf("pilih opsi: ");
    
}



int isDuplicate(NRLL *L, infotype website) {
    address current = L->First;
    while (current != NULL) {
        if (strcmp(current->info, website) == 0) {
            return 1; 
        }
        current = current->next;
    }
    return 0; 
}

void printHistory(Stack *S, Queue *Q) {
    NRLL combinedList; 
    CreateList(&combinedList); 

    address current = S->L.First;
    while (current != NULL) {
        if (!isDuplicate(&combinedList, current->info)) {
            InsertAtLast(&combinedList, current->info); 
        }
        current = current->next;
    }

    current = Q->list.First;
    while (current != NULL) {
        if (!isDuplicate(&combinedList, current->info)) {
            InsertAtLast(&combinedList, current->info);
        }
        current = current->next;
    }

    printf("\n=== riwayat kunjungan website ===\n");
    current = combinedList.First;
    while (current != NULL) {
        printf("%s\n", current->info);
        current = current->next;
    }

    DeallocateList(&combinedList);
}




int webHistoRun(){
    Stack S;
    Queue Q; 
    CreateStack(&S);
    createQueue(&Q);

    int choice;
    infotype website;

    do{
        displayMenu();
        scanf("%d", &choice);
        getchar();
        system("cls");

        switch (choice){
            case 1:
                website = (infotype)malloc(100 * sizeof(char));
                printf("masukkan link website: ");
                fgets(website, 100, stdin);
                website[strcspn(website, "\n")] = 0;
                Push(&S, website);
                enqueue(&Q, website);
                printf("website ditambahkan ke riwayat.\n\n");
                break;
            case 2:
                printHistory(&S, &Q);
                break;
            case 3:
                if (!isEmpty(S)){
                    Pop(&S);
                    printf("website terbaru telah dihapus\n");
                } else {
                    printf("stack kosong, tidak ada website untuk dihapus\n");
                }
                break;
            case 4:
                if (!isQueueEmpty(&Q)){
                    dequeue(&Q);
                    printf("website terlama telah dihapus\n");
                } else{
                    printf("queue kosong, tidak ada website untuk dihapus\n");
                }
                break;
            case 5:
                printf("terimakasih telah menggunakan program ini\n");
                break;
            default:
                printf("pilihan tidak valid, coba lagi\n");
        }
    } while (choice != 5);

    DeallocateStack(&S);
    DeallocateQueue(&Q);

    return 0;
}
#include <stdio.h>
#include "bankQueue.h"

void runBankQueueSim(){
    Queue Q;
    createQueue(&Q); 
    int choice, numAntrian = 1;

    while (1){
        printf("pilihan:\n");
        printf("1. ambil antrian\n");
        printf("2. proses antrian\n");
        printf("3. cetak antrian\n");
        printf("4. keluar\n");
        printf("pilih: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                enqueue(&Q, numAntrian);
                printf("nomor antrian ke-%d telah ditambahkan\n", numAntrian);
                numAntrian++; 
                printQueue(&Q);
                break;
            case 2: 
                if(!isQueueEmpty(&Q)){
                    printf("nomor antrian ke-%d sedang diproses\n", Q.list.First->info);
                    dequeue(&Q);
                } else{
                    printf("antrian kosong\n");
                }
                printQueue(&Q);
                break;
            case 3: 
                printQueue(&Q);
                break;
            case 4:
                DeallocateQueue(&Q);
                printf("terimakasih telah mggunakan layanan bank ini\n");
                return;
            default:
                printf("pilihan tidak valid, silakan coba lagi\n");
        }
    }
}
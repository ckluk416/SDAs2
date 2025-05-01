#include "perpustakaan.h"

NRLL priorityQueues[3];

void initPriorityQueues() {
    for (int i = 0; i < 3; i++) {
        CreateList(&priorityQueues[i]);
    }
}

void tambahBukuSingly(bukuSingly **head, char *judul, int stok) {
    bukuSingly *newBook = (bukuSingly*)malloc(sizeof(bukuSingly));
    strcpy(newBook->judul, judul);
    newBook->stok = stok;
    newBook->next = *head;
    *head = newBook;
}

void tampilkanBukuSingly(bukuSingly *head) {
    bukuSingly *current = head;
    while (current != NULL) {
        printf("Judul: %s, Stok: %d\n", current->judul, current->stok);
        current = current->next;
    }
}

void hapusBukuSingly(bukuSingly **head, char *judul) {
    bukuSingly *temp = *head, *prev;   
    if (temp != NULL && strcmp(temp->judul, judul) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }    
    while (temp != NULL && strcmp(temp->judul, judul) != 0) {
        prev = temp;
        temp = temp->next;
    }    
    if (temp == NULL) return;    
    prev->next = temp->next;
    free(temp);
}

void tambahBukuDoubly(bukuDoubly **head, char *judul, int stok) {
    bukuDoubly *newBook = (bukuDoubly*)malloc(sizeof(bukuDoubly));
    strcpy(newBook->judul, judul);
    newBook->stok = stok;
    newBook->next = *head;
    newBook->prev = NULL;
    if (*head != NULL)
        (*head)->prev = newBook;
    *head = newBook;
}

void tampilkanBukuDoubly(bukuDoubly *head) {
    bukuDoubly *current = head;
    while (current != NULL) {
        printf("Judul: %s, Stok: %d\n", current->judul, current->stok);
        current = current->next;
    }
}

void hapusBukuDoubly(bukuDoubly **head, char *judul) {
    bukuDoubly *temp = *head;
    while (temp != NULL && strcmp(temp->judul, judul) != 0)
        temp = temp->next;   
    if (temp == NULL) return;    
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;
        
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
        
    free(temp);
}

void tambahBukuArray(bukuArray *arr, int *size, char *judul, int stok) {
    strcpy(arr[*size].judul, judul);
    arr[*size].stok = stok;
    (*size)++;
}

void tampilkanBukuArray(bukuArray *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Judul: %s, Stok: %d\n", arr[i].judul, arr[i].stok);
    }
}

void hapusBukuArray(bukuArray *arr, int *size, char *judul) {
    int found = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(arr[i].judul, judul) == 0) {
            found = i;
            break;
        }
    }   
    if (found == -1) return;   
    for (int i = found; i < *size - 1; i++) {
        arr[i] = arr[i+1];
    }  
    (*size)--;
}

// Loan management functions
void tambahPeminjam(char *nama, int prioritas, char *judulBuku) {
    if (prioritas < 0 || prioritas > 2) return;
    InsertAtLast(&priorityQueues[prioritas], nama);
}

void prosesPeminjaman(char *judulBuku) {
    const char *prioritasName[] = {"Dosen", "Mahasiswa", "Umum"};
    for (int i = 0; i < 3; i++) {
        if (priorityQueues[i].First != NULL) {
            address firstInQueue = priorityQueues[i].First;
            printf("%s (prioritas %s) meminjam buku %s\n", 
                  firstInQueue->info, prioritasName[i], judulBuku);
            DeleteBetween(&priorityQueues[i], firstInQueue->info);
            return;
        }
    }
    printf("Tidak ada peminjam untuk buku %s\n", judulBuku);
}

void tampilkanAntrian() {
    const char *prioritasName[] = {"Dosen", "Mahasiswa", "Umum"};
    for (int i = 0; i < 3; i++) {
        printf("Antrian %s:\n", prioritasName[i]);
        address current = priorityQueues[i].First;
        while (current != NULL) {
            printf("- %s\n", current->info);
            current = current->next;
        }
    }
}

void batalkanPeminjaman(char *nama, char *judulBuku) {
    for (int i = 0; i < 3; i++) {
        DeleteBetween(&priorityQueues[i], nama);
    }
    printf("%s membatalkan peminjaman buku %s\n", nama, judulBuku);
}
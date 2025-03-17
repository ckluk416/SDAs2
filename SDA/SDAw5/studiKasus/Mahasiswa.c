#include "Mahasiswa.h"

// membuat list kosong; kreator/konstruktor
void CreateList(ListMahasiswa *L) {
    L->First = NULL;
}

// membebaskan memori yang dialokasikan; destruktor
void DeallocateList(ListMahasiswa *L) {
    address current = L->First;
    address temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    L->First = NULL;
}

// memeriksa apakah list kosong; validator
int IsEmpty(ListMahasiswa L) {
    return L.First == NULL;
}

// menyisipkan elemen secara terurut berdasarkan nama; setter
void InsertSorted(ListMahasiswa *L, infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P == NULL) return;

    P->info = X;
    P->next = NULL;

    if (IsEmpty(*L) || strcmp(L->First->info.nama, X.nama) > 0) {
        P->next = L->First;
        L->First = P;
    } else {
        address current = L->First;
        while (current->next != NULL && strcmp(current->next->info.nama, X.nama) < 0) {
            current = current->next;
        }
        P->next = current->next;
        current->next = P;
    }
}

// mmenampilkan isi list secara ascending berdasarkan nama; printObjek
void PrintListAscending(ListMahasiswa L) {
    address current = L.First;
    while (current != NULL) {
        printf("Nama: %s, Nilai UTS: %d\n", current->info.nama, current->info.nilaiUTS);
        current = current->next;
    }
}

// menampilkan isi list secara descending berdasarkan nilai; printObjek
void PrintListDescending(ListMahasiswa L) {
    int count = CountElements(L);
    infotype *arr = (infotype *)malloc(count * sizeof(infotype));
    address current = L.First;
    for (int i = 0; i < count; i++) {
        arr[i] = current->info;
        current = current->next;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[i].nilaiUTS < arr[j].nilaiUTS) {
                infotype temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("Nama: %s, Nilai UTS: %d\n", arr[i].nama, arr[i].nilaiUTS);
    }

    free(arr);
}

// menghitung jumlah elemen dalam list
int CountElements(ListMahasiswa L) {
    int count = 0;
    address current = L.First;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// menyalin elemen list1 ke list2 dgn ketentuan nilai > 70; setter
void CopyElements(ListMahasiswa L1, ListMahasiswa *L2, int kkm) {
    address current = L1.First;
    while (current != NULL) {
        if (current->info.nilaiUTS > kkm) {
            InsertSorted(L2, current->info);
        }
        current = current->next;
    }
}

// menghapus elemen duplikat berdasarkan nama
void RemoveDuplicates(ListMahasiswa *L) {
    address current = L->First;
    while (current != NULL && current->next != NULL) {
        address runner = current;
        while (runner->next != NULL) {
            if (strcmp(current->info.nama, runner->next->info.nama) == 0) {
                address temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}
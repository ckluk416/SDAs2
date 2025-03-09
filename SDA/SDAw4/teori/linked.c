#include "linked.h"

// Memeriksa apakah linked list kosong
boolean isEmpty(address p) {
    return (p == NULL);
}

// Membuat node baru
void Create_Node(address *p) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        (*p)->next = NULL; // Inisialisasi next ke NULL
    }
}

// Mengisi node dengan nilai
void Isi_Node(address *p, infotype nilai) {
    if (*p != NULL) {
        (*p)->info = nilai;
        (*p)->next = NULL; // Inisialisasi next ke NULL
    }
}

// Menampilkan seluruh isi linked list
void Tampil_List(address p) {
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

// Menyisipkan node baru di awal linked list
void Ins_Awal(address *p, address PNew) {
    PNew->next = *p;
    *p = PNew;
}

// Menyisipkan node baru di akhir linked list
void Ins_Akhir(address *p, address PNew) {
    if (*p == NULL) {
        *p = PNew; // Jika list kosong, node baru menjadi head
    } else {
        address last = *p;
        while (last->next != NULL) {
            last = last->next; // Mencari elemen terakhir
        }
        last->next = PNew; // Menyambungkan node baru di akhir
    }
}

// Mencari elemen dalam linked list
address Search(address p, infotype nilai) {
    while (p != NULL) {
        if (p->info == nilai) {
            return p; // Ditemukan
        }
        p = p->next;
    }
    return NULL; // Tidak ditemukan
}

// Menyisipkan node baru setelah node tertentu
void InsertAfter(address *pBef, address PNew) {
    PNew->next = (*pBef)->next;
    (*pBef)->next = PNew;
}

// Menghapus elemen pertama dari linked list
void Del_Awal(address *p, infotype *X) {
    if (*p != NULL) {
        *X = (*p)->info; // Menyimpan nilai info
        address temp = *p;
        *p = (*p)->next; // Memindahkan head ke node berikutnya
        free(temp); // Menghapus node pertama
    }
}

// Menghapus elemen terakhir dari linked list
void Del_Akhir(address *p, infotype *X) {
    if (*p == NULL) return; // List kosong

    if ((*p)->next == NULL) { // Hanya ada satu elemen
        *X = (*p)->info;
        free(*p);
        *p = NULL; // Set head ke NULL
    } else {
        address current = *p;
        while (current->next->next != NULL) {
            current = current->next; // Mencari elemen sebelum terakhir
        }
        *X = current->next->info; // Menyimpan nilai info
        free(current->next); // Menghapus elemen terakhir
        current->next = NULL; // Set next ke NULL
    }
}

// Menghapus node setelah node tertentu
void Del_After(address *pBef, infotype *X) {
    if (*pBef != NULL && (*pBef)->next != NULL) {
        address temp = (*pBef)->next;
        *X = temp->info; // Menyimpan nilai info
        (*pBef)->next = temp->next; // Menghubungkan node sebelumnya ke node setelahnya
        free(temp); // Menghapus node
    }
}

// Mengembalikan address P ke sistem
void DeAlokasi(address *p) {
    if (*p != NULL) {
        free(*p);
        *p = NULL; // Set pointer ke NULL setelah dealokasi
    }
}

// Menghitung jumlah elemen dalam linked list
int NbElmt(address p) {
    if (p == NULL) return 0; // List kosong
    return 1 + NbElmt(p->next); // Rekursif untuk menghitung elemen
}

// Mengembalikan nilai minimum dari elemen dalam linked list
infotype Min(address p) {
    if (p == NULL) {
        // Penanganan jika list kosong, bisa disesuaikan
        return -1; // Misalnya, mengembalikan -1 jika tidak ada elemen
    }
    infotype minValue = p->info;
    while (p != NULL) {
        if (p->info < minValue) {
            minValue = p->info; // Update nilai minimum
        }
        p = p->next;
    }
    return minValue;
}

// Menghitung rata-rata nilai dari elemen dalam linked list
infotype Rerata(address p) {
    if (p == NULL) return 0; // List kosong
    int sum = 0, count = 0;
    while (p != NULL) {
        sum += p->info; // Menjumlahkan nilai
        count++; // Menghitung jumlah elemen
        p = p->next;
    }
    return (count > 0) ? (sum / count) : 0; // Mengembalikan rata-rata
}

// Membalik elemen dalam linked list
address BalikList(address p) {
    address prev = NULL;
    address current = p;
    address next = NULL;
    while (current != NULL) {
        next = current->next; // Simpan node berikutnya
        current->next = prev; // Balik arah pointer
        prev = current; // Pindah ke node berikutnya
        current = next; // Lanjutkan ke node berikutnya
    }
    return prev; // Kembalikan head baru
}
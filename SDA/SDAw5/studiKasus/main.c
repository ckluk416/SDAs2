#include "Mahasiswa.h"

int main() {
    //Buat List L1 dan L2 untuk menampung daftar mahasiswa
    ListMahasiswa L1, L2;
    CreateList(&L1);
    CreateList(&L2);

    infotype mhs1 = {"Akbar", 85};
    infotype mhs2 = {"Baihaqi", 75};
    infotype mhs3 = {"Carisa", 90};
    infotype mhs4 = {"Denis", 65};
    infotype mhs5 = {"Budi", 70};

    InsertSorted(&L1, mhs1);
    InsertSorted(&L1, mhs2);
    InsertSorted(&L1, mhs3);
    InsertSorted(&L1, mhs4);
    InsertSorted(&L1, mhs5);

    // 4. Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut ascending berdasarkan nama
    printf("List L1 (ascending berdsarkan nama):\n");
    PrintListAscending(L1);

    // 5. Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut desending berdasarkan nilai
    printf("\nList L1 (descending berdasarkan nilai uts):\n");
    PrintListDescending(L1);

    // 6. Hitung Jumlah elemen (jumlah mahasiswa pada list), kemudian tampilkan
    int count = CountElements(L1);
    printf("\nJumlah elemen di L1: %d\n", count);

    // 7. Copy seluruh elemen pada list L1 yang Nilainya > 70 ke List L2
    CopyElements(L1, &L2, 70);

    // 8. Tampilkan Isi elemen List L2
    printf("\nList L2 (copy elemen dgn Nilai UTS > 70):\n");
    PrintListAscending(L2);

    // 9. hapus duplikat
    RemoveDuplicates(&L2);

    // 10. Tampilkan elemen List L2 yang baru
    printf("\nList L2 (hanya satu):\n");
    PrintListAscending(L2);

    // 11. hapus List L1 dan List L2
    DeallocateList(&L1);
    DeallocateList(&L2);

    return 0;
}
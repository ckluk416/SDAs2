#include "SLL.h"

int main() {
    City cities[2];

    // buat kota
    CreateCity(&cities[0], "Bandung");
    CreateCity(&cities[1], "Jakarta");

    // mnambahkan orang ke kota
    AddPersonToCity(&cities[0], "Yahya");
    AddPersonToCity(&cities[0], "Wahab");
    AddPersonToCity(&cities[0], "Amir");

    AddPersonToCity(&cities[1], "Hasan");
    AddPersonToCity(&cities[1], "Badu");

    // mnampilkan isi kota
    printf("isi kota:\n");
    DisplayCity(&cities[0]);
    DisplayCity(&cities[1]);

    // mnghapus orang dari kota
    DeletePersonFromCity(&cities[0], "Wahab");
    DeletePersonFromCity(&cities[1], "Hasan");

    // mnampilkan isi kota setelah penghapusan
    printf("\nisi kota (setelah penghapusan orang):\n");
    DisplayCity(&cities[0]);
    DisplayCity(&cities[1]);

    DeallocateAllCities(cities, 2);

    return 0;
}
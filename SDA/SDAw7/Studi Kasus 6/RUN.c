#include "RUN.h"

int startProgram(){
    struct City* cityList = NULL;
    char cityName[50];
    char personName[50];
    int choice;

    do {
        printf("\n====== menu ======\n");
        printf("1. tambah kota\n");
        printf("2. tambah orang ke kota\n");
        printf("3. tampilkan semua kota\n");
        printf("4. hapus orang dari kota\n");
        printf("5. hapus kota\n");
        printf("6. keluar\n");
        printf("pilih slah satu: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("masukkan nama kota baru: ");
                scanf("%s", cityName);
                AddCity(&cityList, cityName);
                printf("kota '%s' telah ditambahkan.\n", cityName);
                break;
            case 2:
                printf("masukkan nama kota tempat menambahkan orang: ");
                scanf("%s", cityName);
                struct City* currentCity = cityList;
                while (currentCity != NULL && strcmp(currentCity->cityName, cityName) != 0){
                    currentCity = currentCity->next; //cari kota berdasarkan nama
                }
                if (currentCity == NULL){
                    printf("kota tidak ditemukan.\n");
                } else{
                    printf("masukkan nama orang: ");
                    scanf("%s", personName);
                    AddPersonToCity(currentCity, personName); //tambahkan orang ke kota
                    printf("%s telah ditambahkan ke kota %s.\n", personName, currentCity->cityName);
                }
                break;
            case 3:
                printf("\nIsi Kota dan Orang:\n");
                DisplayCities(cityList); //tampilkan semua kota dan orang
                break;
            case 4:
                printf("masukkan nama kota tempat menghapus orang: ");
                scanf("%s", cityName);
                struct City* targetCity = cityList;
                while (targetCity != NULL && strcmp(targetCity->cityName, cityName) != 0) {
                    targetCity = targetCity->next; //cari kota berdasarkan nama
                }
                if (targetCity == NULL){
                    printf("kota tidak ditemukan.\n");
                } else {
                    printf("masukkan nama orang yang ingin dihapus: ");
                    scanf("%s", personName);
                    DeletePersonFromCity(targetCity, personName); //hapus orang dari kota
                }
                break;
            case 5:
                printf("masukkan nama kota yang ingin dihapus: ");
                scanf("%s", cityName);
                DeleteCity(&cityList, cityName); //hapus kota
                break;
            case 6:
                printf("program akan ditutup sesaat lagi\n");
                break;
            default:
                printf("pilihan tidak valid.\n");
        }
    } while (choice != 6);
    //dealloc
    struct City* currentCity = cityList;
    while (currentCity != NULL) {
        DeallocateList(&(currentCity->list)); //dealloc orang
        struct City* tempCity = currentCity;
        currentCity = currentCity->next;
        free(tempCity); 
    }
    printf("program telah ditutup\n");
    return 0;
}
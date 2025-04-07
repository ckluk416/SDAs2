#include "LL.h"

//add kota DLL
void AddCity(struct City** cityList, char* cityName){
    struct City* newCity = (struct City*)malloc(sizeof(struct City));
    strcpy(newCity->cityName, cityName);
    CreateList(&(newCity->list));
    newCity->prev = NULL;
    newCity->next = *cityList;

    if (*cityList != NULL){
        (*cityList)->prev = newCity;
    }
    *cityList = newCity;
}

//menambahkan orang SLL ke kota 
void AddPersonToCity(struct City* city, char* personName){
    InsertAtLast(&(city->list), (infotype)personName); 
}

//menghapus orang dari kota
void DeletePersonFromCity(struct City* city, char* personName){
    DeleteBetween(&(city->list), personName);
}

//menghapus kota dari DLL
void DeleteCity(struct City** cityList, char* cityName){
    if (*cityList == NULL){
        printf("tidak ada kota yang dapat dihapus.\n");
        return;
    }

    struct City* current = *cityList;

    //cari kota berdasarkan nama
    while (current != NULL && strcmp(current->cityName, cityName) != 0){
        current = current->next;
    }

    if (current == NULL){
        printf("kota dengan nama '%s' tidak ditemukan.\n", cityName);
        return;
    }

    //hapus semua orang di kota
    DeallocateList(&(current->list));

    //perbarui hubungan antar kota
    if (current->prev != NULL){ //jika bukan kota pertama
        current->prev->next = current->next;
    } else{ //jika kota pertama
        *cityList = current->next;
    }

    if (current->next != NULL){ //jika bukan kota terakhir
        current->next->prev = current->prev;
    }

    free(current);
    printf("kota dengan nama '%s' dan seluruh orang di dalamnya telah dihapus.\n", cityName);
}

//menampilkan semua kota dan orang
void DisplayCities(struct City* cityList){
    struct City* currentCity = cityList;
    while (currentCity != NULL) {
        printf("Kota: %s\n", currentCity->cityName);

        address currentPerson = currentCity->list.First;
        while (currentPerson != NULL) {
            printf("  Nama: %s\n", (char*)currentPerson->info);
            currentPerson = currentPerson->next;
        }

        currentCity = currentCity->next; //pindah ke kota berikutnya
    }
}
#ifndef LL_H
#define LL_H

#include "NRLL.h"

//DLL kota
struct City {
    char cityName[50];    
    NRLL list;           
    struct City* prev;   
    struct City* next;   
};

//proc untuk menambahkan kota
void AddCity(struct City** cityList, char* cityName);

//proc untuk menambahkan orang ke kota
void AddPersonToCity(struct City* city, char* personName);

//proc untuk menghapus orang dari kota
void DeletePersonFromCity(struct City* city, char* personName);

//proc untuk menghapus kota
void DeleteCity(struct City** cityList, char* cityName);

//proc untuk menampilkan semua kota dan orang
void DisplayCities(struct City* cityList);

#endif
#include <stdio.h>
#include "menu_fuggvenyek.h"

int fomenu(){
    printf("Valassza ki a funkciot:\n"
           "1:Adatok hozzaadasa\n"
           "2:Adatok keresese\n"
           "3:Adatok torlese\n"
           "4:Szerviztortenet\n"
           "5:Adatok kiirasa\n"
           "6:Lejarok\n"
           "7:Mentes\n"
           "0:Mentes es kilepes\n"
           "----------------------\n");
           int valasz;
           scanf("%d",&valasz);
           return valasz;
}
int uj_menu(){
    printf( "1:Auto hozzaadasa\n"
            "2:Ugyfel hozzaadasa\n"
            "3:Javitas hozzaadasa\n"
            "0:Vissza a fomenube\n");
        int valasz;
        scanf("%d",&valasz);
        return valasz;
}
int keres_menu(){
    printf( "1:Auto keresese\n"
            "2:Ugyfel keresese\n"
            "0:Vissza a fomenube\n");
        int valasz;
        scanf("%d",&valasz);
        return valasz;
}
int autokeres_menu(){
        printf("1: Kereses rendszam alapjan\n"
               "2: Kereses azonosito alapjan\n"
               "0: Vissza a fomenube\n");
        int valasz;
        scanf("%d",&valasz);
        return valasz;
}
int ugyfelkeres_menu(){
        printf("1: Ugyfel keresese azonosito alapjan\n"
               "2: Ugyfel keresese nev alapjan\n"
               "0: Vissza a fomenube\n");
        int valasz;
        scanf("%d",&valasz);
        return valasz;
}
int torles_menu(){
    printf( "1:Auto torlese\n"
            "2:Ugyfel torlese\n"
            "0:Vissza a fomenube\n");
        int valasz;
        scanf("%d",&valasz);
        return valasz;
}
int kiir_menu(){
    printf( "1:Autok kiirasa\n"
            "2:Ugyfelek kiirasa\n"
            "3:Javitasok kiirasa\n"
            "0:Vissza a fomenube\n");
        int valasz;
        scanf("%d",&valasz);
        return valasz;
}

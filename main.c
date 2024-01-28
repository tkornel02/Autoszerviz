#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"
#include <string.h>
#include "strukturak.h"
#include "seged_fuggvenyek.h"
#include "ugyfel_fuggvenyek.h"
#include "auto_fuggvenyek.h"
#include "javitas_fuggvenyek.h"
#include "fajlkezelo_fuggvenyek.h"
#include "menu_fuggvenyek.h"

int main()
{
    Ugyfel *ugyfelLista = NULL;
    Auto *autolista = NULL;
    Javitas *javlista = NULL;

    autolista = autoBe("autok.txt");
    ugyfelLista = ugyfelBe("ugyfelek.txt");
    javlista = javitasBe("javitasok.txt");

    int valasz;
    do{
    printf("\n-----------------AUTOSZERVIZ-----------------\n\n");
        valasz = fomenu();
           switch (valasz){
       case 1:
           switch (uj_menu()){
           case 1:
               inputAutoBeszur(&autolista,&ugyfelLista);
            break;
           case 2:
               inputUgyfelBeszur(&ugyfelLista);
            break;
           case 3:
               inputJavitasBeszur(&javlista,&autolista,&ugyfelLista);
            break;
           case 0:
               system("cls");
            break;
           }
        break;
       case 2:
           switch(keres_menu()){
           case 1:
                {
                system("cls");
                switch(autokeres_menu(autolista)){
            case 1:

                inputAutoKeresRendszam(autolista);
                break;
            case 2:
                inputAutoKeresID(autolista);
                break;
            case 0:
                break;
                }
            }
            break;
           case 2:
               {

                    switch(ugyfelkeres_menu()){
                    case 1:
                        inputUgyfelKeresID(ugyfelLista,autolista);
                        break;
                    case 2:
                        ugyfelKeresNev(ugyfelLista,autolista);
                        break;
                    }
               }
            break;
           case 0:
            system("cls");
            break;
           }
        break;
       case 3:
           switch(torles_menu()){
            case 1:

                inputAutoTorol(&autolista);
            break;
            case 2:

                inputUgyfelTorol(&ugyfelLista,&autolista); /*2 param*/
            break;
            case 0:
            system("cls");
            break;
           }
        break;
       case 4:
            system("cls");
           inputSzerviztortenet(javlista);
        break;
       case 5:
           switch (kiir_menu()){
       case 1:
            system("cls");
            autoListaKiir(autolista);
        break;
       case 2:
            system("cls");
            ugyfelListaKiir(ugyfelLista);
        break;
       case 3:
            system("cls");
            javitasListaKiir(javlista);
        break;
       case 0:
        system("cls");
        break;
           }
        break;
       case 6:
           system("cls");
           lejarok(autolista);
        break;
       case 0:
           {
        autoMentes("autok.txt",autolista);
        UgyfelMentes("ugyfelek.txt",ugyfelLista);
        javitasMentes("javitasok.txt",javlista);
        ugyfelListaFelszab(ugyfelLista);
        javitasListaFelszab(javlista);
        autoListaFelszab(autolista);
        return 0;
           }
        break;
       case 7:{
        autoMentes("autok.txt",autolista);
        UgyfelMentes("ugyfelek.txt",ugyfelLista);
        javitasMentes("javitasok.txt",javlista);
        system("cls");printf("Adatok mentve.\n");
        }
        break;
       default:
        system("cls");
        printf("Ervenytelen parancs.\n");
        break;
        }
    } while (valasz!=0);


}

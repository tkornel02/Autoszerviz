#ifndef UGYFEL_FUGGVENYEK_H_INCLUDED
#define UGYFEL_FUGGVENYEK_H_INCLUDED
#include "strukturak.h"

Ugyfel *ujUgyfel(int azonosito, char *nev, char *tel);
/*Létrehoz egy új ügyfelet paraméterben megadott adatokkal és visszatér egy ügyfélre mutató pointerrel*/

void ugyfelFelszab(Ugyfel *ugyfel);
/*felszabadítja a paraméterben megadott ügyfelet*/

void ugyfelListaFelszab(Ugyfel *listaFej);
/*felszabadítja a paraméterben megadott ügyféllistát*/

void ugyfelBeszur(Ugyfel **listaFej, int azonosito, char *nev, char *elerhetoseg);
/*beszúr egy ügyfelet a paraméterben megadott láncolt listába,
paraméterként veszi át az adatait az új ügyfélnek*/

void ugyfelKiir(Ugyfel *ugyfel);
/*kiírja a paraméterben megadott ügyfelet*/

void ugyfelListaKiir(Ugyfel *listaFej);
/*kiír egy ügyféllistát*/

Ugyfel *ugyfelKeres(Ugyfel *listaFej,int azonosito);
/*Keres egy ügyfelet a paraméterben megadott listában azonosító alapján és visszatér az arra ügyfélre mutató pointerrel*/

void ugyfelTorol(Ugyfel **listaFej,int azonosito);
/*Töröl egy ügyfelet a paraméterben megadott láncolt listából*/

void inputUgyfelBeszur(Ugyfel** Listafej);
/*szkennel egy ugyfelet es beszurja a paraméterben megadott listaba */

void inputUgyfelTorol(Ugyfel **ugyfListaFej,Auto **autListaFej);
/*szkennel egy azonositot es kitorli a paraméterben megadott lancolt listabol (autoit is ki kell torolni ezert kell az autos lista is) */

void inputUgyfelKeresID(Ugyfel* ListaFej,Auto *autListaFej);
/*szkennelt ugyfelazonosito segitsegevel keres a paraméterben megadott listaban egy ugyfelet es az alapjan kiirja,
 hogy van-e találat, ha van kiírja az adatait*/
void ugyfelKeresNev(Ugyfel *listaFej,Auto *autolista);
/*beszkennelt nevre keres a megadott listaban, kiirja az osszes talalatot es azon ugyfelek autoit*/
#endif // UGYFEL_FUGGVENYEK_H_INCLUDED


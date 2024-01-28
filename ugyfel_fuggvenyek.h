#ifndef UGYFEL_FUGGVENYEK_H_INCLUDED
#define UGYFEL_FUGGVENYEK_H_INCLUDED
#include "strukturak.h"

Ugyfel *ujUgyfel(int azonosito, char *nev, char *tel);
/*L�trehoz egy �j �gyfelet param�terben megadott adatokkal �s visszat�r egy �gyf�lre mutat� pointerrel*/

void ugyfelFelszab(Ugyfel *ugyfel);
/*felszabad�tja a param�terben megadott �gyfelet*/

void ugyfelListaFelszab(Ugyfel *listaFej);
/*felszabad�tja a param�terben megadott �gyf�llist�t*/

void ugyfelBeszur(Ugyfel **listaFej, int azonosito, char *nev, char *elerhetoseg);
/*besz�r egy �gyfelet a param�terben megadott l�ncolt list�ba,
param�terk�nt veszi �t az adatait az �j �gyf�lnek*/

void ugyfelKiir(Ugyfel *ugyfel);
/*ki�rja a param�terben megadott �gyfelet*/

void ugyfelListaKiir(Ugyfel *listaFej);
/*ki�r egy �gyf�llist�t*/

Ugyfel *ugyfelKeres(Ugyfel *listaFej,int azonosito);
/*Keres egy �gyfelet a param�terben megadott list�ban azonos�t� alapj�n �s visszat�r az arra �gyf�lre mutat� pointerrel*/

void ugyfelTorol(Ugyfel **listaFej,int azonosito);
/*T�r�l egy �gyfelet a param�terben megadott l�ncolt list�b�l*/

void inputUgyfelBeszur(Ugyfel** Listafej);
/*szkennel egy ugyfelet es beszurja a param�terben megadott listaba */

void inputUgyfelTorol(Ugyfel **ugyfListaFej,Auto **autListaFej);
/*szkennel egy azonositot es kitorli a param�terben megadott lancolt listabol (autoit is ki kell torolni ezert kell az autos lista is) */

void inputUgyfelKeresID(Ugyfel* ListaFej,Auto *autListaFej);
/*szkennelt ugyfelazonosito segitsegevel keres a param�terben megadott listaban egy ugyfelet es az alapjan kiirja,
 hogy van-e tal�lat, ha van ki�rja az adatait*/
void ugyfelKeresNev(Ugyfel *listaFej,Auto *autolista);
/*beszkennelt nevre keres a megadott listaban, kiirja az osszes talalatot es azon ugyfelek autoit*/
#endif // UGYFEL_FUGGVENYEK_H_INCLUDED


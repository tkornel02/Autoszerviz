#ifndef JAVITAS_FUGGVENYEK_H_INCLUDED
#define JAVITAS_FUGGVENYEK_H_INCLUDED

Javitas *ujJavitas(Datum datum, char *tipus, int ar, char *rendszam, int tulaj);
/*L�trehoz egy �j javit�st a param�terek alapj�n, �s visszat�r annak a c�m�vel*/

void javitasFelszab(Javitas *javitas);
/*felszabad�t egy jav�t�st*/

void javitasListaFelszab(Javitas *listaFej);
/*felszabad�t egy jav�t�sokb�l �ll� list�t*/

void javitasBeszurAzon(Javitas** listaFej,Datum datum, char *tipus, int ar, char* rendszam, int tulaj);
/*azonos�t� alapj�n sz�r be egy jav�t�st a megadott l�ncolt list�ba(nem haszn�ljuk a programban)*/

void javitasBeszurDatum(Javitas** listaFej,Datum datum, char *tipus, int ar, char* rendszam, int tulaj);
/*D�tum alapj�n sz�r be egy jav�t�st a megadott l�ncolt list�ba*/

void javitasKiir(Javitas *javitas);
/*ki�rja a megadott jav�t�st*/

void javitasListaKiir(Javitas *listaFej);
/*ki�rja a megadott l�ncolt list�t ami jav�t�sokb�l �ll*/

void szervizTortenet(Javitas *listaFej,char *rendszam);
/*ki�rja a megadott aut� szervizt�rt�net�t*/

void inputJavitasBeszur(Javitas **ListaFej,Auto **autolista,Ugyfel **ugyfListaFej);
/*szkennel egy javitast es beirja a lancolt listaba a 3 parameter a kulonbozo feltetelek miatt van,
pl ha nincsen benne az adatbazisban az auto vagy az ugyfel*/

void inputSzerviztortenet(Javitas *ListaFej);
/*szkennel egy rendsz�mot �s ki�rja az ahhoz tartoz� aut� szervizt�rt�net�t*/

#endif // JAVITAS_FUGGVENYEK_H_INCLUDED



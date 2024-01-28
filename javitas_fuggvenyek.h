#ifndef JAVITAS_FUGGVENYEK_H_INCLUDED
#define JAVITAS_FUGGVENYEK_H_INCLUDED

Javitas *ujJavitas(Datum datum, char *tipus, int ar, char *rendszam, int tulaj);
/*Létrehoz egy új javitást a paraméterek alapján, és visszatér annak a címével*/

void javitasFelszab(Javitas *javitas);
/*felszabadít egy javítást*/

void javitasListaFelszab(Javitas *listaFej);
/*felszabadít egy javításokból álló listát*/

void javitasBeszurAzon(Javitas** listaFej,Datum datum, char *tipus, int ar, char* rendszam, int tulaj);
/*azonosító alapján szúr be egy javítást a megadott láncolt listába(nem használjuk a programban)*/

void javitasBeszurDatum(Javitas** listaFej,Datum datum, char *tipus, int ar, char* rendszam, int tulaj);
/*Dátum alapján szúr be egy javítást a megadott láncolt listába*/

void javitasKiir(Javitas *javitas);
/*kiírja a megadott javítást*/

void javitasListaKiir(Javitas *listaFej);
/*kiírja a megadott láncolt listát ami javításokból áll*/

void szervizTortenet(Javitas *listaFej,char *rendszam);
/*kiírja a megadott autó szerviztörténetét*/

void inputJavitasBeszur(Javitas **ListaFej,Auto **autolista,Ugyfel **ugyfListaFej);
/*szkennel egy javitast es beirja a lancolt listaba a 3 parameter a kulonbozo feltetelek miatt van,
pl ha nincsen benne az adatbazisban az auto vagy az ugyfel*/

void inputSzerviztortenet(Javitas *ListaFej);
/*szkennel egy rendszámot és kiírja az ahhoz tartozó autó szerviztörténetét*/

#endif // JAVITAS_FUGGVENYEK_H_INCLUDED



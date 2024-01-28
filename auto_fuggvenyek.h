#ifndef AUTO_FUGGVENYEK_H_INCLUDED
#define AUTO_FUGGVENYEK_H_INCLUDED

Auto *ujAuto(char *rendszam, char *tipus, Datum ervenyesseg,int tulaj);
/*Létrehoz egy új autót a paraméterek alapján, és visszatér annak a címével*/

void autoFelszab(Auto *aut);
/*felszabadítja a paraméterben megadott autót*/

void autoListaFelszab(Auto *listaFej);
/*felszabadítja a paraméterben megadott autókat tartalmazó listát*/

void autoBeszur(Auto **listaFej,char *rendszam, char *tipus, Datum ervenyesseg,int tulaj);
/*beszúr a paraméterben megadott listába egy autót a szintén paraméterben megadott adatokkal*/

void autoKiir(Auto* aut);
/*kiírja konzolra az autó adatait*/

void autoListaKiir(Auto *listaFej);
/*kiírja konzolra az autókat tartalmazó lista tartalmát*/

void autoKeresOsszes(Auto *listaFej,int azon);
/*ügyfélazonosító alapján megkeresi az összes autóját az adott azonosítójú ügyfélnek a listában*/

Auto *autoKeresID(Auto *listaFej,int azon);
/*segédfgv a törléshez, Ügyfélazonosító alapján keresi az első talált autót a listában, visszatér az arra az autóra pointerrel*/

Auto *autoKeresRendszam(Auto *listaFej,char *rendszam);
/*Rendszám alapján keres autót a listában, visszatér a talált autóra mutató pointerrel */

void autoTorolID(Auto **listaFej,int azonosito);
/*segédfgv, az ügyfél elsõ talált autóját törli a listából */

void ugyfelAutoTorol(Auto **listaFej,int azonosito);
/*azonosító alapján kitörli az összes autóját az ügyfélnek a listából*/

void autoTorolRendszam(Auto **listaFej,char *rendszam);
/*rendszám alapjan töröl egy autót a listából*/

void lejarok(Auto *ListaFej);
/*kiirja azokat az autokat a listából amelyeknek vagy lejárt már vagy 6 hónapon belül le fog járni érvényessége*/

     //                                                                                      //
    /*AZ ALÁBBI FÜGGVÉNYEK AZ ELŐBBIEKET HÍVJÁK MEG, CSAK A FELHASZNÁLÓ ADJA MEG AZ ADATOKAT*/
   //                                                                                      //

void inputAutoBeszur(Auto** ListaFej,Ugyfel **ugyfListaFej);
/*szkennel egy autot es beirja a lancolt listaba*/

void inputAutoTorol(Auto **ListaFej);
/*töröl egy autót a láncolt listából, bemenet alapjan szkennel*/

void inputAutoKeresID(Auto *ListaFej);
/*ugyfelazonositot ker es kiirja az ugyfel osszes autóját*/

void inputAutoKeresRendszam(Auto *ListaFej);
/*rendszamot ker es kiirja ha talal ilyen rendszamu autót*/



#endif // AUTO_FUGGVENYEK_H_INCLUDED

#ifndef FAJLKEZELO_FUGGVENYEK_H_INCLUDED
#define FAJLKEZELO_FUGGVENYEK_H_INCLUDED


char *sortBeolvas(FILE *bemenet);
/*beolvas egy sort dinamikusan a megadott fájlból*/

Ugyfel *ugyfelBe(char *fajlNev);
/*épít egy ügyfelekbõl álló listát a paraméterben megadott fájlból*/

Auto *autoBe(char *fajlNev);
/*épít egy autókból álló listát a paraméterben megadott fájlból*/

Javitas *javitasBe(char *fajlNev);
/*épít egy javításokból álló listát a paraméterben megadott fájlból*/

void javitasMentes(char *fajlNev,Javitas *listaFej);
/*fájlba írja egy javításokat tároló láncolt lista tartalmát*/

void autoMentes(char *fajlNev, Auto *listaFej);
/*fájlba írja egy autókat tároló láncolt lista tartalmát*/

void UgyfelMentes(char *fajlNev, Ugyfel *listaFej);
/*fájlba írja egy ügyfeleket tároló láncolt lista tartalmát*/

#endif // FAJLKEZELO_FUGGVENYEK_H_INCLUDED


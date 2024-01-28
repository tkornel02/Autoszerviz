#ifndef FAJLKEZELO_FUGGVENYEK_H_INCLUDED
#define FAJLKEZELO_FUGGVENYEK_H_INCLUDED


char *sortBeolvas(FILE *bemenet);
/*beolvas egy sort dinamikusan a megadott f�jlb�l*/

Ugyfel *ugyfelBe(char *fajlNev);
/*�p�t egy �gyfelekb�l �ll� list�t a param�terben megadott f�jlb�l*/

Auto *autoBe(char *fajlNev);
/*�p�t egy aut�kb�l �ll� list�t a param�terben megadott f�jlb�l*/

Javitas *javitasBe(char *fajlNev);
/*�p�t egy jav�t�sokb�l �ll� list�t a param�terben megadott f�jlb�l*/

void javitasMentes(char *fajlNev,Javitas *listaFej);
/*f�jlba �rja egy jav�t�sokat t�rol� l�ncolt lista tartalm�t*/

void autoMentes(char *fajlNev, Auto *listaFej);
/*f�jlba �rja egy aut�kat t�rol� l�ncolt lista tartalm�t*/

void UgyfelMentes(char *fajlNev, Ugyfel *listaFej);
/*f�jlba �rja egy �gyfeleket t�rol� l�ncolt lista tartalm�t*/

#endif // FAJLKEZELO_FUGGVENYEK_H_INCLUDED


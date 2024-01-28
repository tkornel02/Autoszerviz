#ifndef STRUKTURAK_H_INCLUDED
#define STRUKTURAK_H_INCLUDED



typedef struct Datum{
    int ev;
    int honap;
    int nap;
} Datum;
/*d�tumokat tartalmazni tud� strukt�ra*/
typedef struct Javitas{
    Datum datum;
    char* tipus;
    int ar;
    char* rendszam;
    int tulaj;
    struct Javitas *kov;
} Javitas;
/*jav�t�sokat tartalmazni tud� strukt�ra*/

typedef struct Auto {
    char *rendszam;
    char *tipus;
    Datum erv;
    int tulaj;
    struct Auto *kov;
} Auto;
/*aut�kat tartalmazni tud� strukt�ra*/

typedef struct Ugyfel {
    int azonosito;
    char *nev;
    char *tel;
    struct Ugyfel *kov;
} Ugyfel;
/*�gyfeleket tartalmazni tud� strukt�ra*/

#endif // STRUKTURAK_H_INCLUDED

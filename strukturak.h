#ifndef STRUKTURAK_H_INCLUDED
#define STRUKTURAK_H_INCLUDED



typedef struct Datum{
    int ev;
    int honap;
    int nap;
} Datum;
/*dátumokat tartalmazni tudó struktúra*/
typedef struct Javitas{
    Datum datum;
    char* tipus;
    int ar;
    char* rendszam;
    int tulaj;
    struct Javitas *kov;
} Javitas;
/*javításokat tartalmazni tudó struktúra*/

typedef struct Auto {
    char *rendszam;
    char *tipus;
    Datum erv;
    int tulaj;
    struct Auto *kov;
} Auto;
/*autókat tartalmazni tudó struktúra*/

typedef struct Ugyfel {
    int azonosito;
    char *nev;
    char *tel;
    struct Ugyfel *kov;
} Ugyfel;
/*ügyfeleket tartalmazni tudó struktúra*/

#endif // STRUKTURAK_H_INCLUDED

#include <stdio.h>
#include "strukturak.h"
#include "debugmalloc.h"
#include "ugyfel_fuggvenyek.h"
#include "auto_fuggvenyek.h"
#include "javitas_fuggvenyek.h"

char *sortBeolvas(FILE *bemenet) {
    char *sor = (char*) malloc(64 * sizeof(char));
    if (!fgets(sor, 64, bemenet)) {
        free(sor);
        return NULL;
    }

    while (sor[strlen(sor) - 1] != '\n') {
        sor = (char*) realloc(sor, (strlen(sor) + 65) * sizeof(char));
        char tmp[65];
        fgets(tmp, 65, bemenet);
        strcat(sor, tmp);
    }

    sor[strlen(sor) - 1] = '\0';
    return sor;
}

Ugyfel *ugyfelBe(char *fajlNev) {
    FILE *mutato = fopen(fajlNev, "rt");
    if (mutato == NULL) {
        perror("A fajlt nem sikerult megnyitni");
        return NULL;
    }

    Ugyfel *listaFej = NULL;
    char *sor = sortBeolvas(mutato);
    while (sor != NULL) {
        int azonosito;
        char *nev;
        char *tel;


        char *szovegResz = strtok(sor, ";");
        sscanf(szovegResz, "%d", &azonosito);

        nev = strtok(NULL, ";");
        tel = strtok(NULL,";");
        ugyfelBeszur(&listaFej, azonosito, nev, tel);

        free(sor);
        sor = sortBeolvas(mutato);
    }

    fclose(mutato);
    return listaFej;
}

Auto *autoBe(char *fajlNev) {
    FILE *mutato = fopen(fajlNev, "rt");
    if (mutato == NULL) {
        perror("A fajlt nem sikerult megnyitni");
        return NULL;
    }

    Auto *listaFej = NULL;
    char *sor = sortBeolvas(mutato);
    while (sor != NULL) {
        char *rendszam;
        char *tipus;
        Datum erv;
        int tulaj;

        rendszam = strtok(sor, ";");
        tipus = strtok(NULL,";");
        char *szovegResz=strtok(NULL,";");
        sscanf(szovegResz,"%d.%d.%d.",&erv.ev,&erv.honap,&erv.nap);
        szovegResz = strtok(NULL,";");
        sscanf(szovegResz,"%d",&tulaj);
        autoBeszur(&listaFej,rendszam,tipus,erv,tulaj);
        free(sor);
        sor = sortBeolvas(mutato);
    }

    fclose(mutato);
    return listaFej;
}

Javitas *javitasBe(char *fajlNev){
FILE *mutato = fopen(fajlNev, "rt");
    if (mutato == NULL) {
        perror("A fajlt nem sikerult megnyitni");
        return NULL;
    }

    Javitas *listaFej = NULL;
    char *sor = sortBeolvas(mutato);
    while (sor != NULL) {
        Datum datum;
        char* tipus;
        int ar;
        char* rendszam;
        int tulaj;

        char *szovegResz=strtok(sor,";");
        sscanf(szovegResz,"%d.%d.%d.",&datum.ev,&datum.honap,&datum.nap);
        tipus = strtok(NULL,";");
        szovegResz = strtok(NULL,";");
        sscanf(szovegResz,"%d",&ar);
        rendszam = strtok(NULL, ";");
        szovegResz = strtok(NULL, ";");
        sscanf(szovegResz,"%d",&tulaj);

        javitasBeszurDatum(&listaFej,datum,tipus,ar,rendszam,tulaj);
        free(sor);
        sor = sortBeolvas(mutato);
    }

    fclose(mutato);
    return listaFej;
}


void javitasMentes(char *fajlNev,Javitas *listaFej){
    FILE *mutato = fopen(fajlNev, "wt");
        for (Javitas *mozgo = listaFej; mozgo != NULL; mozgo = mozgo->kov) {
            fprintf(mutato,"%5d.%02d.%02d.;%s;%d;%s;%04d\n",mozgo->datum.ev,mozgo->datum.honap,mozgo->datum.nap,mozgo->tipus,mozgo->ar,mozgo->rendszam,mozgo->tulaj);
        }
    fclose(mutato);
}

void autoMentes(char *fajlNev, Auto *listaFej) {
    FILE *mutato = fopen(fajlNev, "wt");
        for (Auto *mozgo = listaFej; mozgo != NULL; mozgo = mozgo->kov) {
            fprintf(mutato,"%s;%s;%5d.%02d.%02d.;%04d\n",mozgo->rendszam,mozgo->tipus,mozgo->erv.ev,mozgo->erv.honap,mozgo->erv.nap,mozgo->tulaj);
        }
    fclose(mutato);
}

void UgyfelMentes(char *fajlNev, Ugyfel *listaFej) {
    FILE *mutato = fopen(fajlNev, "wt");
        for (Ugyfel *mozgo = listaFej; mozgo != NULL; mozgo = mozgo->kov) {
            fprintf(mutato,"%04d;%s;%s\n",mozgo->azonosito,mozgo->nev,mozgo->tel);
        }
    fclose(mutato);
}

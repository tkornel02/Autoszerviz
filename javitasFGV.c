#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

#include "strukturak.h"
#include <string.h>
#include "seged_fuggvenyek.h"
#include "javitas_fuggvenyek.h"
#include "auto_fuggvenyek.h"

Javitas *ujJavitas(Datum datum, char *tipus, int ar, char *rendszam, int tulaj) {
    Javitas *ujJavitas = (Javitas*) malloc(sizeof(Javitas));

    ujJavitas->datum=datum;
    ujJavitas->tipus = (char*) malloc((strlen(tipus) + 1) * sizeof(char));
    strcpy(ujJavitas->tipus,tipus);
    ujJavitas->ar=ar;
    ujJavitas->rendszam = (char*) malloc((strlen(rendszam) + 1) * sizeof(char));
    strcpy(ujJavitas->rendszam, rendszam);
    ujJavitas->tulaj=tulaj;
    ujJavitas->kov = NULL;

    return ujJavitas;
}
void javitasFelszab(Javitas *javitas){
    free(javitas->tipus);
    free(javitas->rendszam);
    free(javitas);
}
void javitasListaFelszab(Javitas *listaFej){
    while (listaFej != NULL){
        Javitas *kov = listaFej->kov;
        javitasFelszab(listaFej);
        listaFej = kov;

    }
}
void javitasBeszurAzon(Javitas** listaFej,Datum datum, char *tipus, int ar, char* rendszam, int tulaj){
    Javitas *javitas = ujJavitas(datum,tipus, ar, rendszam, tulaj);

        if (*listaFej == NULL) {
            *listaFej = javitas;
        }
        else if ((*listaFej)->tulaj > javitas->tulaj) {
            javitas->kov = *listaFej;
            *listaFej = javitas;
        }
        else {
            Javitas *eredmeny = *listaFej;
            while ((*listaFej)->tulaj < javitas->tulaj
                && (*listaFej)->kov != NULL
                && (*listaFej)->kov->tulaj <= javitas->tulaj) {
                    *listaFej = (*listaFej)->kov;
                }

            javitas->kov = (*listaFej)->kov;
            (*listaFej)->kov = javitas;
            *listaFej = eredmeny;
        }
}
void javitasBeszurDatum(Javitas** listaFej,Datum datum, char *tipus, int ar, char* rendszam, int tulaj){
    Javitas *javitas = ujJavitas(datum,tipus, ar, rendszam, tulaj);

        if (*listaFej == NULL) {
            *listaFej = javitas;
        }
        else if (datumHasonlit((*listaFej)->datum,javitas->datum)==-1){
            javitas->kov = *listaFej;
            *listaFej = javitas;
        }
        else {
            Javitas *eredmeny = *listaFej;
            while  (datumHasonlit((*listaFej)->datum,javitas->datum)==1
                && (*listaFej)->kov != NULL
                && (datumHasonlit((*listaFej)->kov->datum,javitas->datum)==1 || datumHasonlit((*listaFej)->kov->datum,javitas->datum)==0)
                ) {
                    *listaFej = (*listaFej)->kov;
                }

            javitas->kov = (*listaFej)->kov;
            (*listaFej)->kov = javitas;
            *listaFej = eredmeny;
        }
}
void javitasKiir(Javitas *javitas){
    printf("%-30s  %-9s  %4d.%02d.%02d.  %8d Ft  %04d\n",javitas->tipus,javitas->rendszam,javitas->datum.ev,javitas->datum.honap,javitas->datum.nap, javitas->ar, javitas->tulaj);
}
void javitasListaKiir(Javitas *listaFej){
    if (listaFej!=NULL){
        printf("Javitasok:\n--------------------------\n");

            //printf("%-30s  %-9s  %-9s  %15s  %s\n","Tipus","Rendszam","Datum","Ar","ID");
            while (listaFej != NULL){
                javitasKiir(listaFej);
                if ((listaFej->kov !=NULL && datumHasonlit(listaFej->datum,listaFej->kov->datum)!=0) || listaFej->kov==NULL)
                    printf("--------------------------\n");
                listaFej = listaFej->kov;
            }
    }
    else
    printf("Nincsenek javitasaink.\n");
}
void szervizTortenet(Javitas *listaFej,char *rendszam){
    while (listaFej != NULL){
        if (strcmp(listaFej->rendszam,rendszam)==0){
            javitasKiir(listaFej);
        }
        listaFej=listaFej->kov;
    }
}


void inputJavitasBeszur(Javitas **ListaFej,Auto **autolista,Ugyfel**ugyfListaFej){
        Datum mikor;
        char *tipus = (char*) malloc(sizeof(char)*26);
        char *rendszam = (char*) malloc(sizeof(char)*16);
        int ar;
        printf("Javitott auto rendszama: ");
        getchar();
        scanf("%[^\n]",rendszam);
        if (autoKeresRendszam(*autolista,rendszam)==NULL){
            printf("Nincs ilyen rendszamu auto adatbazisunkban. Szeretne hozzaadni?(i/n)");
            char valasz;
            getchar();
            scanf("%c",&valasz);
            if (valasz == 'i' || valasz == 'I'){
                inputAutoBeszur(autolista,ugyfListaFej); //ebben a rendszamot jol kell megadni kulonben crashel a program
            }
            else if (valasz=='n'||valasz=='N'){
                while (autoKeresRendszam(*autolista,rendszam)==NULL){
                printf("Javitott auto rendszama ujra: (fomenu: 0)");
                getchar();
                scanf("%[^\n]",rendszam);
                if (strcmp(rendszam,"0")==0){system("cls");return;}
                }
            }
        }
        printf("Javitas datuma: (ev honap nap): ");scanf("%d%d%d",&mikor.ev,&mikor.honap,&mikor.nap); getchar();
        printf("Javitas tipusa: ");scanf("%[^\n]",tipus);
        printf("Javitas ara: ");scanf("%d",&ar);
        Auto *seged = autoKeresRendszam(*autolista,rendszam);
        javitasBeszurDatum(ListaFej,mikor,tipus,ar,rendszam,seged->tulaj);
        free(tipus);
        free(rendszam);
        system("cls");
        printf("Adatok hozzaadva.\n");

}


void inputSzerviztortenet(Javitas *ListaFej){
    char *rendszam = (char*) malloc(16*sizeof(char));
    printf("Melyik rendszamu auto szerviztortenetere van szukseg (vissza: 0): ");
    scanf("%s",rendszam);
    if (strcmp(rendszam,"0")==0) {system("cls"); free(rendszam); return;}
    printf("A(z) %s rendszamu auto szerviztortenete:\n",rendszam);
    szervizTortenet(ListaFej,rendszam);
    free(rendszam);


}



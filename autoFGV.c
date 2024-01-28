#include <stdio.h>
#include "strukturak.h"
#include "debugmalloc.h"
#include "seged_fuggvenyek.h"
#include "ugyfel_fuggvenyek.h"
#include "auto_fuggvenyek.h"
Auto *ujAuto(char *rendszam, char *tipus, Datum ervenyesseg,int tulaj) {
    Auto *ujAuto = (Auto*) malloc(sizeof(Auto));

    ujAuto->rendszam = (char*) malloc((strlen(rendszam) + 1) * sizeof(char));
    strcpy(ujAuto->rendszam, rendszam);
    ujAuto->tipus = (char*) malloc((strlen(tipus) + 1) * sizeof(char));
    strcpy(ujAuto->tipus,tipus);
    ujAuto->erv=ervenyesseg;
    ujAuto->tulaj=tulaj;
    ujAuto->kov = NULL;

    return ujAuto;
}
void autoFelszab(Auto *aut) {
    free(aut->rendszam);
    free(aut->tipus);
    free(aut);
}
void autoListaFelszab(Auto *listaFej) {
    while (listaFej != NULL) {
        Auto *kov = listaFej->kov;
        autoFelszab(listaFej);
        listaFej = kov;
    }
}
void autoBeszur(Auto **listaFej,char *rendszam, char *tipus, Datum ervenyesseg,int tulaj) {
    Auto *aut = ujAuto(rendszam, tipus, ervenyesseg,tulaj);

    if (*listaFej == NULL) {
        *listaFej = aut;
    }
    else if ((*listaFej)->tulaj > aut->tulaj) {
        aut->kov = *listaFej;
        *listaFej = aut;
    }
    else {
        Auto *eredmeny = *listaFej;
        while ((*listaFej)->tulaj < aut->tulaj
            && (*listaFej)->kov != NULL
            && (*listaFej)->kov->tulaj <= aut->tulaj) {
                *listaFej = (*listaFej)->kov;
            }

        aut->kov = (*listaFej)->kov;
        (*listaFej)->kov = aut;
        *listaFej = eredmeny;
    }
}
void autoKiir(Auto* aut){
    printf("%-10s  %-25s  %5d.%02d.%02d.  %04d\n",aut->rendszam,aut->tipus,aut->erv.ev,aut->erv.honap,aut->erv.nap,aut->tulaj);

}
void autoListaKiir(Auto *listaFej){
    printf("Autoink:\n");
    while (listaFej!=NULL){
        autoKiir(listaFej);
        listaFej = listaFej->kov;
    }
}
void autoKeresOsszes(Auto *listaFej,int kit){
    if (autoKeresID(listaFej,kit)==NULL){
        printf("Nincs regisztralt autoja az ugyfelnek.\n");
    }
    else{
        printf("Az ugyfel autoi:\n");
        while (listaFej!=NULL){
            if (listaFej->tulaj==kit){
                autoKiir(listaFej);
            }
            listaFej = listaFej->kov;
        }
    }
}

Auto *autoKeresID(Auto *listaFej,int azon){
while (listaFej!=NULL){
        if (listaFej->tulaj==azon){
            return listaFej;
        }
        listaFej = listaFej->kov;
    }
    return NULL;
}
Auto *autoKeresRendszam(Auto *listaFej,char *rendszam){
while (listaFej!=NULL){
        if (strcmp(listaFej->rendszam,rendszam)==0){
            return listaFej;
        }
        listaFej = listaFej->kov;
    }

    return NULL;
}
void autoTorolID(Auto **listaFej,int azonosito){
Auto *torlendo = autoKeresID(*listaFej,azonosito);
    if (torlendo==NULL){}
    else if (torlendo==*listaFej){
        Auto *ujlistaFej=torlendo->kov;
        torlendo->kov=NULL;
        autoFelszab(torlendo);
        *listaFej = ujlistaFej;
    }
    else{
        Auto *lemarado = NULL;
        Auto *mozgo = *listaFej;
        while (mozgo!=torlendo){
            lemarado=mozgo;
            mozgo=mozgo->kov;
        }
        lemarado->kov = mozgo->kov;
        autoFelszab(mozgo);


    }
}

void ugyfelAutoTorol(Auto **listaFej,int azonosito){ //meg lehet csinalni egy ciklussal mert az autok adatai azonositok alapjan rendezve vannak.
    if (autoKeresID(*listaFej,azonosito)!=NULL){
        Auto *mozgo = *listaFej;
        while (mozgo->tulaj!=azonosito){
            mozgo = mozgo->kov;
        }
        while (mozgo!=NULL && mozgo->tulaj==azonosito){
            mozgo=mozgo->kov;
            autoTorolID(listaFej,azonosito);


        }
    }
}
void autoTorolRendszam(Auto **listaFej,char *rendszam){
Auto *torlendo = autoKeresRendszam(*listaFej,rendszam);
    if (torlendo==NULL){}
    else if (torlendo==*listaFej){
        Auto *ujlistaFej=torlendo->kov;
        torlendo->kov=NULL;
        autoFelszab(torlendo);
        *listaFej = ujlistaFej;
    }
    else{
        Auto *lemarado = NULL;
        Auto *mozgo = *listaFej;
        while (mozgo!=torlendo){
            lemarado=mozgo;
            mozgo=mozgo->kov;
        }
        lemarado->kov = mozgo->kov;
        autoFelszab(mozgo);


    }
}

void lejarok(Auto *ListaFej){
    printf("6 honapon belul lejaro muszaki vizsgas autok:\n"
           "-----------------------------------------------\n");
    while (ListaFej!=NULL){
        if (hatHonaponBelul(ListaFej->erv)!=1){
            autoKiir(ListaFej);
        }
            ListaFej = ListaFej->kov;
    }

}

void inputAutoBeszur(Auto** ListaFej,Ugyfel **ugyfListaFej){
        int tulaj;
        char *rendszam = (char*) malloc(sizeof(char)*16);
        char *tipus = (char*) malloc(sizeof(char)*26);
        Datum ervenyesseg;
        getchar(); printf("Uj auto rendszama: "); scanf("%[^\n]",rendszam);
        printf("Uj auto tipusa: "); getchar(); scanf("%[^\n]",tipus);
        printf("Uj auto muszaki vizsgajanak ervenyesseg hatarideje (ev honap nap): "); scanf("%d%d%d",&ervenyesseg.ev,&ervenyesseg.honap,&ervenyesseg.nap);
        printf("Uj auto tulajdonosanak azonositoja: "); scanf("%d",&tulaj);

        if (ugyfelKeres(*ugyfListaFej,tulaj)==NULL){
            printf("Nincs ilyen ugyfelunk. Szeretne hozzaadni? (i/n)");
            char valasz; getchar(); scanf("%c",&valasz);

            if (valasz == 'i' || valasz == 'I'){
                inputUgyfelBeszur(ugyfListaFej);
            }
            else if (valasz=='n'||valasz=='N'){
                while (ugyfelKeres(*ugyfListaFej,tulaj)==NULL){
                printf("Ugyfelazonosito ujra: (fomenu: 0)");
                scanf("%d",&tulaj);
                if (tulaj==0){system("cls");return;}
                }
            }
        }
        autoBeszur(ListaFej,rendszam,tipus,ervenyesseg,tulaj);
        free(rendszam);
        free(tipus);
        system("cls"); printf("Adatok hozzaadva.\n");
}

void inputAutoTorol(Auto **ListaFej){
    char *rendszam = (char*) malloc(16*sizeof(char));
    printf("Torlendo auto rendszama: ");
    scanf("%s",rendszam);
    if (autoKeresRendszam(*ListaFej,rendszam)==NULL){
        printf("Nincs ilyen rendszamu auto.\n");
        system("cls");
    }
    else{
    autoTorolRendszam(ListaFej,rendszam);
    }
    free(rendszam);
}

void inputAutoKeresID(Auto *ListaFej){
    int azonosito;
    printf("Keresendo auto tulajdonosanak az azonositoja: ");
    scanf("%d",&azonosito);
    Auto *keresendo = autoKeresID(ListaFej,azonosito);
    if (keresendo==NULL){
        printf("Nincs ilyen tulajdonosu auto.\n");
    }
    else {
        autoKeresOsszes(ListaFej,azonosito);
    }
}

void inputAutoKeresRendszam(Auto *ListaFej){
    char *rendszam = (char*) malloc(16*sizeof(char));
    printf("Keresendo auto rendszama: ");
    scanf("%s",rendszam);
    Auto *talalat = autoKeresRendszam(ListaFej,rendszam);
    if (talalat==NULL){
        printf("Nincs ilyen rendszamu auto.\n");
    }
    else{
    autoKiir(talalat);
    }
    free(rendszam);

}



#include <stdio.h>
#include "debugmalloc.h"
#include "ugyfel_fuggvenyek.h"
#include "auto_fuggvenyek.h"

Ugyfel *ujUgyfel(int azonosito, char *nev, char *tel) {
    Ugyfel *ujUgyfel = (Ugyfel*) malloc(sizeof(Ugyfel));

    ujUgyfel->azonosito = azonosito;

    ujUgyfel->nev = (char*) malloc((strlen(nev) + 1) * sizeof(char));
    strcpy(ujUgyfel->nev, nev);
    ujUgyfel->tel = (char*) malloc((strlen(tel) + 1) * sizeof(char));
    strcpy(ujUgyfel->tel,tel);
    ujUgyfel->kov = NULL;

    return ujUgyfel;
}
void ugyfelFelszab(Ugyfel *ugyfel) {
    free(ugyfel->tel);
    free(ugyfel->nev);
    free(ugyfel);
}
void ugyfelListaFelszab(Ugyfel *listaFej) {
    while (listaFej != NULL) {
        Ugyfel *kov = listaFej->kov;
        ugyfelFelszab(listaFej);
        listaFej = kov;
    }
}
void ugyfelBeszur(Ugyfel **listaFej, int azonosito, char *nev, char *elerhetoseg) {

    Ugyfel *ugyfel = ujUgyfel(azonosito, nev, elerhetoseg);

    if (*listaFej == NULL) {
        *listaFej = ugyfel;
    }
    else if ((*listaFej)->azonosito > ugyfel->azonosito) {
        ugyfel->kov = *listaFej;
        *listaFej = ugyfel;
    }
    else {
        Ugyfel *eredmeny = *listaFej;
        while ((*listaFej)->azonosito < ugyfel->azonosito
            && (*listaFej)->kov != NULL
            && (*listaFej)->kov->azonosito <= ugyfel->azonosito) {
                *listaFej = (*listaFej)->kov;
            }

        ugyfel->kov = (*listaFej)->kov;
        (*listaFej)->kov = ugyfel;
        *listaFej = eredmeny;
    }
}
void ugyfelKiir(Ugyfel *ugyfel){
    if (ugyfel!=NULL)
        printf("%04d  %-30s  %-15s\n",ugyfel->azonosito,ugyfel->nev,ugyfel->tel);
}
void ugyfelListaKiir(Ugyfel *listaFej){
    if (listaFej!=NULL){
    printf("Ugyfeleink:\n");
        while (listaFej!=NULL){
            ugyfelKiir(listaFej);
            listaFej = listaFej->kov;
        }
    }
    else printf("Nincsenek ugyfelek regisztralva.\n");
}
Ugyfel *ugyfelKeres(Ugyfel *listaFej,int azonosito){
    while (listaFej!=NULL){
        if (listaFej->azonosito==azonosito){
            return listaFej;
        }
        listaFej = listaFej->kov;
    }
    return NULL;
}
void ugyfelTorol(Ugyfel **listaFej,int azonosito){
    Ugyfel *torlendo = ugyfelKeres(*listaFej,azonosito);
    if (torlendo==NULL){}
    else if (torlendo==*listaFej){
        Ugyfel *ujlistaFej=torlendo->kov;
        torlendo->kov=NULL;
        ugyfelFelszab(torlendo);
        *listaFej = ujlistaFej;
    }
    else{
        Ugyfel *lemarado = NULL;
        Ugyfel* mozgo = *listaFej;
        while (mozgo!=torlendo){
            lemarado=mozgo;
            mozgo=mozgo->kov;
        }
        lemarado->kov = mozgo->kov;
        ugyfelFelszab(mozgo);


    }
}

void ugyfelKeresNev(Ugyfel *listaFej,Auto *autolista){
    char *nev = (char*) malloc(26*sizeof(char));
    printf("Milyen nevre szeretne keresni? ");
    getchar(); scanf("%[^\n]",nev);
    while (listaFej!=NULL){
        if (strcmp(listaFej->nev,nev)==0){
            ugyfelKiir(listaFej);
            autoKeresOsszes(autolista,listaFej->azonosito);
        }
        listaFej = listaFej->kov;
    }
    free(nev);
}


void inputUgyfelBeszur(Ugyfel** Listafej){
        int azon;
        char *telszam = (char*) malloc(sizeof(char)*16);
        char *nev = (char*) malloc(sizeof(char)*26);
        printf("Uj ugyfel azonositoja: ");
        scanf("%d",&azon);
        while (ugyfelKeres(*Listafej,azon)!=NULL){
            printf("Letezo azonosito.\nAzonosito ujra: ");
            scanf("%d",&azon);
        }

        printf("Uj ugyfel neve: ");
        getchar();
        scanf("%[^\n]",nev);
        printf("Uj ugyfel telefonszama: ");
        getchar();
        scanf("%[^\n]",telszam);
        ugyfelBeszur(Listafej,azon,nev,telszam);
        free(telszam);
        free(nev);
        system("cls");
        printf("Adatok hozzaadva.\n");


}

void inputUgyfelTorol(Ugyfel **ugyfListaFej,Auto **autListaFej){
    int torlendo;
    printf("Torlendo ugyfel azonositoja: ");
    scanf("%d",&torlendo);
    if (ugyfelKeres(*ugyfListaFej,torlendo)==NULL) printf("Nincs ilyen ugyfel.\n");
    else{
        ugyfelTorol(ugyfListaFej,torlendo);
        ugyfelAutoTorol(autListaFej,torlendo);
    }
}

void inputUgyfelKeresID(Ugyfel* ListaFej,Auto *autListaFej){
    int azonosito;
    printf("Keresendo ugyfel azonositoja: ");
    scanf("%d",&azonosito);
    Ugyfel *ugyfel = ugyfelKeres(ListaFej,azonosito);
    if (ugyfel == NULL) printf("Nincs talalat.\n");
    else {
    printf("Talalat:\n");
    ugyfelKiir(ugyfel);
    autoKeresOsszes(autListaFej,azonosito);
    }
}


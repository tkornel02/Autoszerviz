#include <stdio.h>
#include "strukturak.h"
#include <time.h>

int datumHasonlit(Datum d2, Datum d1){
    if ((d1.ev > d2.ev)
    ||  (d1.ev == d2.ev && d1.honap > d2.honap)
    ||  (d1.ev == d2.ev && d1.honap == d2.honap && d1.nap > d2.nap))
        return -1;
    else if ((d1.ev < d2.ev)
    ||  (d1.ev == d2.ev && d1.honap < d2.honap)
    ||  (d1.ev == d2.ev && d1.honap == d2.honap && d1.nap < d2.nap))
        return 1;
    return 0;
}
int hatHonaponBelul(Datum d1){
    int nap, honap, ev;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    nap = local->tm_mday;
    honap = local->tm_mon+1;
    ev = local->tm_year+1900;

    if (honap>=6){
        honap = honap-6;
        ev++;
    }
    else {
        honap = honap+6;
    }
    Datum d2 = {ev,honap,nap};
    int teszt = datumHasonlit(d1,d2);

    return teszt;

}

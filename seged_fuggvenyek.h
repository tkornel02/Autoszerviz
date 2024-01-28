#ifndef SEGED_FUGGVENYEK_H_INCLUDED
#define SEGED_FUGGVENYEK_H_INCLUDED

int datumHasonlit(Datum d2, Datum d1);
/* két dátumot hasonlít össze, 0 a visszatérési érték, ha ugyanaz a két dátum,
  ha d1 később van akkor -1, ha d2 van késõbb akkor pedig 1 */
int hatHonaponBelul(Datum d1);
/*paramétere egy dátum, melyről eldönti hogy 6 hónapon belül van-e az aznapi dátumtól,
visszatér 0-val ha egy napon vannak,
visszatér 1-gyel ha hat hónapon kívül van az adott dátum,
 -1-gyel ha a dátum korábbi az aznapi dátumnál vagy 6 hónapon belül van */

#endif // SEGED_FUGGVENYEK_H_INCLUDED

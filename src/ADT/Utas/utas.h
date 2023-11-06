//utas.h

#ifndef __UTAS_H__
#define __UTAS_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../Mesin-Kata/wordmachine.h"
#include "../Kicau/tweet.h"

// Deklarasi fungsi
typedef struct {
    int id;
    Word nama;
    time_t tanggal;
    Word isi;
} Utas;

Utas createUtas(Word isi, Word nama);
void utas(Utas thread);

#endif

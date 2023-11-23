//utas.h

#ifndef __UTAS_H__
#define __UTAS_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../Mesin-Kata/wordmachine.h"
#include "../Kicau/tweet.h"

// Deklarasi fungsi

typedef struct nodeUtas* Address;

typedef struct nodeUtas {
    Kicauan tweet;
    Address next;
} NodeUtas;

typedef struct {
    Address first;
    int IDUtas;          // ID dari Utas
    Kicauan* mainTweet;  // Pointer ke kicauan utama
    int tweetCount;      // Jumlah kicauan dalam Utas
} Utas;

typedef struct {
    Utas Utas[100];
    int length;
} ListUtas;

#define IDUtas(U) ((U).IDUtas)
#define IDKicau(L) ((L)->mainTweet.IDKicau)
#define countTweet(U) ((U).tweetCount)
#define INFO(P) ((P)->tweet)
#define NEXT(P) ((P)->next)




Utas createUtas(Word isi, Word nama);
void utas(Utas thread);

#endif

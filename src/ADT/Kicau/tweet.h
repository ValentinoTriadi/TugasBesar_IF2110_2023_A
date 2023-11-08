/* File : tweet.h */


#ifndef tweet_H
#define tweet_H

#include <stdio.h>
#include "../Mesin-Kata/wordmachine.h"
#include "../Time/datetime.h"


typedef struct {
    int id;
    Word text;
    int like;
    Word author;
    DATETIME datetime;
} Kicauan;

typedef struct
{
    Kicauan* kicau;
    int nEff;
    int capacity;
} ListKicau;

boolean IsKicauValid(Word textKicauan);
void kicau(ListKicau *listKicau, Word currentUser);
void kicauan(ListKicau listKicau, Word currentUser);
void ubah_kicauan(ListKicau *listKicau, Word currentUser, int id);
void suka_kicauan(ListKicau *listKicau, Word currentUser, int id);

#endif
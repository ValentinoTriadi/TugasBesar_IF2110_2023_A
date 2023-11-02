/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */


#ifndef tweet_H
#define tweet_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "wordmachine.h"


typedef struct {
    int id;
    char text[280];
    int like;
    char author[50];
    time_t datetime;
} Kicauan;


Kicauan createKicauan(char* text, char* author);
void kicau(Kicauan kicauan);

#endif
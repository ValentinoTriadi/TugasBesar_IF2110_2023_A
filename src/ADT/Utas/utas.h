//utas.h

#ifndef __UTAS_H__
#define __UTAS_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../Time/datetime.h"
#include "../Mesin-Kata/wordmachine.h"

typedef struct utas* AddressUtas;

typedef struct utas{
    Word isi;
    DATETIME time;
    AddressUtas next;
} Utas;

typedef struct{
    int idKicauUtama;
    Utas pertama;
}UtasUtama;

typedef struct{
    UtasUtama utasUtama[100];
    int neffUtas;
}ListUtas;

void UTAS(int idKicau);
boolean isEmpty(ListUtas *l);
void CreateList(ListUtas *l);
void cetakUtas(int IDUtas);
AddressUtas newNode(Word isi);
int findIdxbyID(int ID);

#endif

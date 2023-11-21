#ifndef TEMAN_H
#define TEMAN_H

#include "../PrioQueue/prioqueueReq.h"
#include "../Graf/graf.h"
#include "../Matrix/matrix.h"
#include "../Mesin-Kata/wordmachine.h"
// #include "../Database/db.h"


typedef struct Teman
{
    Graf dataTeman;
    Matrix saveReq;
} Teman;

#define matReq(T) ((T).saveReq);

void createTeman(Teman *teman);

void daftarTeman(Graf graph,Word currentUser);

void hapusTeman(Graf *graph,Word currentUser);

void sentTeman(Word currentUser, Teman *teman);

void printReqMatrix(Matrix saveReq);

void printRequest(PrioQueueReq Q, Word currentUser);

void acceptRequest(Teman *teman,Word currentUser);

#endif
#include "..\..\ADT\PriorityQueue\prioqueueReq.h"
#include "..\..\ADT\Graf\graf.h"
#include "..\..\ADT\Matrix\matrix.h"
#include "..\..\ADT\WordMachine\wordmachine.h"

#ifndef TEMAN_H
#define TEMAN_H

typedef struct Teman
{
    Graf dataTeman;
    Matrix saveReq;
} Teman;

#define matReq(T) ((T).saveReq)
#define Graph(T)  ((T).dataTeman)

void createTeman(Teman *teman);

void daftarTeman(Teman teman,Word currentUser);

void hapusTeman(Teman *teman,Word currentUser);

void sentReq(Word currentUser, Teman *teman);

void printReqMatrix(Matrix saveReq);

void printRequest(PrioQueueReq Q, Word currentUser);

void acceptRequest(Teman *teman,Word currentUser);

#endif
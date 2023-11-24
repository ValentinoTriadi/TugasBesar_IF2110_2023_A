#include "../PrioQueue/prioqueueReq.h"
#include "../Graf/graf.h"
#include "../Matrix/matrix.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../Database/db.h"


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

void printRequest(Word currentUser);

void acceptRequest(Teman *teman,Word currentUser);

Word getWord(int idx);

boolean isFollowing(int idCurrent, int idCheck);

#endif
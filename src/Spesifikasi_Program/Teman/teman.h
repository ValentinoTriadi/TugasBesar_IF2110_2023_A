#include "..\..\ADT\PriorityQueue\prioqueueReq.h"
#include "..\..\ADT\Graf\graf.h"
#include "..\..\ADT\Matrix\matrix.h"
#include "..\..\ADT\WordMachine\wordmachine.h"


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
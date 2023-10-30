#include "..\..\ADT\PriorityQueue\prioqueueReq.h"
#include "..\..\ADT\Graf\graf.h"
#include "..\..\ADT\Matrix\matrix.h"
#include "..\..\ADT\WordMachine\wordmachine.h"


typedef struct Teman
{
    Graf dataTeman;
    Matrix saveReq;
} Teman;

void createTeman(Teman *teman);

void daftarTeman(Graf graph,Word currentUser);

void hapusTeman(Graf *graph,Word currentUser);
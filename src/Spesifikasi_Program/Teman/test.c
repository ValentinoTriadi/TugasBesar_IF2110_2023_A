#include <stdio.h>
#include "teman.h"
#include "..\..\ADT\PriorityQueue\prioqueueReq.c"
#include "..\..\ADT\Graf\graf.c"
#include "..\..\ADT\Matrix\matrix.c"
#include "..\..\ADT\WordMachine\wordmachine.c"

int main() {
    // Initialize your Teman object
    Teman teman;
    createTeman(&teman);

    // Define users
    Word currentUser = {"asep", 4};
    Word friend1 = {"ujang", 5};
    Word friend2 = {"marcelo", 7};

    // Add users to the graph
    addVertex(&(teman.dataTeman), currentUser);
    addVertex(&(teman.dataTeman), friend1);
    addVertex(&(teman.dataTeman), friend2);

    // Add edges to represent friendships
    addEdge(&(teman.dataTeman), currentUser, friend1);
    addEdge(&(teman.dataTeman), currentUser, friend2);

    // Test daftarteman
    daftarTeman(teman.dataTeman, currentUser);

    // Test hapusTeman
    hapusTeman(&(teman.dataTeman), currentUser);
    daftarTeman(teman.dataTeman, currentUser);

    return 0;
}


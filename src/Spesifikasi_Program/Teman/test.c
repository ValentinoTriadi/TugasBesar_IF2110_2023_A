#include <stdio.h>
#include "teman.h"
#include "..\..\ADT\PriorityQueue\prioqueueReq.c"
#include "..\..\ADT\Graf\graf.c"
#include "..\..\ADT\Matrix\matrix.c"
#include "..\..\ADT\WordMachine\wordmachine.c"




int main() {
    Teman teman;
    createTeman(&teman);

    Word currentUser = {"asep", 4};
    Word friend1 = {"ujang", 5};
    Word friend2 = {"marcelo", 7};

    addVertex(&(teman.dataTeman), currentUser);
    addVertex(&(teman.dataTeman), friend1);
    addVertex(&(teman.dataTeman), friend2);

    addEdge(&(teman.dataTeman), currentUser, friend1);
    addEdge(&(teman.dataTeman), currentUser, friend2);

    // Test daftarteman
    printf("Daftar Teman Awal:\n");
    daftarTeman(teman.dataTeman, currentUser);

    // Test hapusTeman
    hapusTeman(&(teman.dataTeman), currentUser);
    printf("\nSetelah Menghapus Teman:\n");
    daftarTeman(teman.dataTeman, currentUser);

    // Test tambahTeman
    Word newFriend = {"joko", 4};
    addVertex(&(teman.dataTeman),newFriend);
    tambahTeman(&(teman.dataTeman), currentUser, &teman);
    printf("\nSetelah Menambah Teman Baru:\n");
    daftarTeman(teman.dataTeman, currentUser);

   

    return 0;
}   
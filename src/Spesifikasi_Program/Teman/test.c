#include <stdio.h>
#include "teman.h"
#include "teman.c"
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

    addVertex(&Graph(teman), currentUser);
    addVertex(&Graph(teman), friend1);
    addVertex(&Graph(teman), friend2);

    addEdge(&Graph(teman), currentUser, friend1);
    addEdge(&Graph(teman), currentUser, friend2);

    // Test daftarteman
    printf("Daftar Teman Awal:\n");
    daftarTeman(teman,currentUser);

    // Test hapusTeman
    hapusTeman(&teman ,currentUser);
    daftarTeman(teman,currentUser);

    // Test tambahTeman
    Word friend3 = {"joko", 4};
    Word friend4 = {"zaki", 4};
    printReqMatrix(matReq(teman));
    addVertex(&Graph(teman), friend3);
    addVertex(&Graph(teman), friend4);
    printf("asep ngirim teman\n");
    sentReq(currentUser,&teman);
    printf("zaki ngirim teman\n");
    sentReq(friend3,&teman);
    printReqMatrix(matReq(teman));
    printf("joko accept teman\n");
    acceptRequest(&teman,friend3);
    printf("Daftar teman joko.\n");
    daftarTeman(teman,currentUser);
    printReqMatrix(matReq(teman));

   


    
    return 0;
}   
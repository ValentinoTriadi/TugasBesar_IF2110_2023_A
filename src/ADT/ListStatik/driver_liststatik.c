#include "liststatik.c"
#include <stdio.h>

int main(){
    ListStatik L1, L2;
    CreateListStatik(&L1);
    CreateListStatik(&L2);
    
    //isi L1
    insertFirst_ListStatik(&L1, 40);
    insertAt_ListStatik(&L1, 50, 1);
    insertAt_ListStatik(&L1, 60, 2);
    insertLast_ListStatik(&L1, 70);

    //print L1
    printf("L1: ");
    printList_ListStatik(L1);
    printf("\n");

    //isi L2
    int a, b, c, d;
    printf("Insert first L2: ");
    scanf("%d", &a);
    insertFirst_ListStatik(&L2, a);
    printf("Insert element at L2: ");
    scanf("%d %d", &b, &c);
    insertAt_ListStatik(&L2, b, c);
    printf("Insert last L2: ");
    scanf("%d", &d);
    insertLast_ListStatik(&L2, d);

    //print L2
    printf("L2: ");
    printList_ListStatik(L2);

    //panjang L1 dan L2
    printf("\n Panjang L1: %d", listLength_ListStatik(L1));
    printf("\n Panjang L2: %d", listLength_ListStatik(L2));

    //delete L1
    int e, f;
    printf("\n Delete element at L1: ");
    scanf("%d %d", &e, &f);
    deleteAt_ListStatik(&L1, &e, f);

    //print L1
    printf("L1: ");
    printList_ListStatik(L1);

    //panjang L1 baru
    printf("\n Panjang L1: %d", listLength_ListStatik(L1));

    //delete L2
    deleteFirst_ListStatik(&L2, &a);
    deleteLast_ListStatik(&L2, &d);

    //print L2
    printf("\nL2: ");
    printList_ListStatik(L2);

    //panjang L2 baru
    printf("\n Panjang L2: %d", listLength_ListStatik(L2));

    //concat L1 dan L2
    ListStatik L3;
    CreateListStatik(&L3);
    L3 = concat_ListStatik(L1, L2);
    printf("\nL3: ");
    printList_ListStatik(L3);

    //remove duplicate L3
    removeDuplicate_ListStatik(&L3);
    printf("\nL3: ");
    printList_ListStatik(L3);

    //sort L3
    printf("\n Sorted L3: ");
    sortList_ListStatik(&L3, true);
    printList_ListStatik(L3);
}
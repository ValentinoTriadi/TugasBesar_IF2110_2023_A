#include "liststatik.h"
#include <stdio.h>

int main(){
    ListStatik L1, L2, L3;
    ListStatik_ElType val;
    boolean isFull, isEmpty, isEqual, asc;
    int idx, max, min;

    // Inisialisasi List L1 dan L2
    CreateListStatik(&L1);
    CreateListStatik(&L2);

    // Isi L1
    insertLast_ListStatik(&L1, 10);
    insertLast_ListStatik(&L1, 20);
    insertLast_ListStatik(&L1, 30);
    insertLast_ListStatik(&L1, 40);
    insertLast_ListStatik(&L1, 50);

    // Print L1
    printList_ListStatik(L1);
    printf("\n");

    // Isi L2 dengan membaca dari input
    readList_ListStatik(&L2);

    // Print L2
    printList_ListStatik(L2);
    printf("\n");

    // Cek apakah L1 penuh
    isFull = isFull_ListStatik(L1);

    // Cek apakah L2 kosong
    isEmpty = isEmpty_ListStatik(L2);

    // Cari elemen dengan index 30 di L1
    idx = indexOf_ListStatik(L1, 30);

    // Bandingkan L1 dan L2
    isEqual = isListEqual_ListStatik(L1, L2);

    // Gabungkan L1 dan L2 menjadi L3
    L3 = concat_ListStatik(L1, L2);
    printList_ListStatik(L3);
    printf("\n");

    // Hapus elemen yang sama di L3
    removeDuplicates(&L3);
    printList_ListStatik(L3);
    printf("\n");

    // Urutkan L3 secara ascending
    asc = true;
    sortList_ListStatik(&L3, asc);
    printList_ListStatik(L3);
    printf("\n");

    // Urutkan L3 secara descending
    asc = false;
    sortList_ListStatik(&L3, asc);
    printList_ListStatik(L3);
    printf("\n");

    // Dapatkan nilai ekstrem dari L3
    extremeValues_ListStatik(L3, &max, &min);

    // Hapus elemen pertama dan terakhir dari L1
    deleteFirst_ListStatik(&L1, &val);
    printList_ListStatik(L1);

    deleteLast_ListStatik(&L1, &val);
    printList_ListStatik(L1);

    return 0;
}

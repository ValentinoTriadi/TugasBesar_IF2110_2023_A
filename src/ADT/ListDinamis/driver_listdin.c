#include "listdin.h"
#include <stdio.h>

int main() {
    ListDin ld;
    int capacity = 10; 
    int value;

    // Membuat list dinamis kosong dengan kapasitas tertentu
    CreateListDin(&ld, capacity);

    // Mengisi list dengan beberapa elemen
    for (int i = 0; i < 5; i++) {
        insertLast_ListDin(&ld, i + 1);
    }

    // Mencetak list
    printList_ListDin(ld);
    printf("\n");

    // Menghapus elemen terakhir
    deleteLast_ListDin(&ld, &value);

    // Mencetak list
    printList_ListDin(ld);
    printf("\n");

    // Mencari elemen
    int searchedVal = 3;
    int index = indexOf_ListDin(ld, searchedVal);
    if (index != IDX_UNDEF) {
        printf("Elemen %d ditemukan pada index: %d\n", searchedVal, index);
    } else {
        printf("Elemen %d tidak ditemukan.\n", searchedVal);
    }

    // Menambah kapasitas list
    expandList_ListDin(&ld, 5);  // Menambah kapasitas sebanyak 5 elemen

    // Mencetak kapasitas baru list
    printf("Kapasitas baru list: %d\n", LISTDIN_CAPACITY(ld));

    // Mengurangi kapasitas list
    printf("Mengurangi kapasitas list...\n");
    shrinkList_ListDin(&ld, 3);  // Mengurangi kapasitas sebanyak 3 elemen

    // Mencetak kapasitas baru list
    printf("Kapasitas baru list: %d\n", LISTDIN_CAPACITY(ld));

    // Mengompresi list
    printf("Mengompresi list...\n");
    compressList_ListDin(&ld);

    // Mencetak list setelah kompresi
    printList_ListDin(ld);
    printf("\n");

    // Mencari nilai ekstrem
    ListDin_ElType max, min;
    extremeValues_ListDin(ld, &max, &min);
    printf("Nilai maksimum: %d\n", max);
    printf("Nilai minimum: %d\n", min);

    // Melakukan sorting ascending
    sort_ListDin(&ld, true);
    printList_ListDin(ld);
    printf("\n");

    // Membaca list dari input
    readList_ListDin(&ld);

    // Mencetak list setelah pembacaan
    printList_ListDin(ld);
    printf("\n");

    // Menghitung jumlah kemunculan suatu nilai dalam list
    searchedVal = 3;
    int count = countVal_ListDin(ld, searchedVal);

    // Deallocate list
    dealocateList_ListDin(&ld);

    return 0;
}

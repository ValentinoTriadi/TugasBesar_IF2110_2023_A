#include "liststatik.h"
#include <stdio.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan LISTMARK */
{
    int i;
    for (i = 0; i < CAPACITY; i++){
        LISTELMT(*l, i) = LISTMARK;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength_ListStatik(ListStatik l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
    int i, count;
    count = 0;
    for (i = 0 ; i < CAPACITY ; i++){
        if (LISTELMT(l, i) != LISTMARK)
            count++;
    }
    return count;
}

/* *** Selektor INDEKS *** */
ListStatik_IdxType getFirstIdx_ListStatik(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}

ListStatik_IdxType getLastIdx_ListStatik(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return listLength_ListStatik(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListStatik(ListStatik l, ListStatik_IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= IDX_MIN && i <= CAPACITY-1);
}

boolean isIdxEff_ListStatik(ListStatik l, ListStatik_IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
    return (i >= 0 && i <= listLength_ListStatik(l)-1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty_ListStatik(ListStatik l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
{
    return (listLength_ListStatik(l) == 0);
}

/* *** Test List penuh *** */
boolean isFull_ListStatik(ListStatik l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return (listLength_ListStatik(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList_ListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
    int n, i;
    CreateListStatik(l);
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY) {
        scanf("%d", &n);
    }
    for (i = 0; i < n; i++){
        scanf("%d", &LISTELMT(*l, i));
    }
}

void printList_ListStatik(ListStatik l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
    int i;
    printf("[");
    for (i = 0; i < listLength_ListStatik(l); i++) {
        printf("%d", LISTELMT(l, i));
        if (i < listLength_ListStatik(l) - 1)
            printf(",");
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList_ListStatik(ListStatik l1, ListStatik l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
{
    ListStatik l;
    int i;
    CreateListStatik(&l);
    for (i = 0; i < listLength_ListStatik(l1); i++) {
        if (plus)
            LISTELMT(l, i) = LISTELMT(l1, i) + LISTELMT(l2, i);
        else
            LISTELMT(l, i) = LISTELMT(l1, i) - LISTELMT(l2, i);
    }
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual_ListStatik(ListStatik l1, ListStatik l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{

    boolean equal = true;
    int i = 0;
    if (listLength_ListStatik(l1) != listLength_ListStatik(l2)) {
        equal = false;
    } else {
        while (equal && i < listLength_ListStatik(l1)) {
            if (LISTELMT(l1, i) != LISTELMT(l2, i)) {
                equal = false;
            }
            i++;
        }
    }
    return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf_ListStatik(ListStatik l, ListStatik_ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan LISTELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
    int i = 0;
    boolean found = false;
    while (!found && i < listLength_ListStatik(l)) {
        if (LISTELMT(l, i) == val) {
            found = true;
        } else {
            i++;
        }
    }
    if (found) {
        return i;
    } else {
        return IDX_UNDEF;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValues_ListStatik(ListStatik l, ListStatik_ElType *max, ListStatik_ElType *min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
{
    int i;
    *max = LISTELMT(l, 0);
    *min = LISTELMT(l, 0);
    for (i = 1; i < listLength_ListStatik(l); i++) {
        if (LISTELMT(l, i) > *max) {
            *max = LISTELMT(l, i);
        }
        if (LISTELMT(l, i) < *min) {
            *min = LISTELMT(l, i);
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst_ListStatik(ListStatik *l, ListStatik_ElType val)
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
{
    int i;
    for (i = listLength_ListStatik(*l); i > 0; i--) {
        LISTELMT(*l, i) = LISTELMT(*l, i - 1);
    }
    LISTELMT(*l, 0) = val;
}

void insertAt_ListStatik(ListStatik *l, ListStatik_ElType val, ListStatik_IdxType idx)
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
{
    int i;
    for (i = listLength_ListStatik(*l); i > idx; i--) {
        LISTELMT(*l, i) = LISTELMT(*l, i - 1);
    }
    LISTELMT(*l, idx) = val;
}

void insertLast_ListStatik(ListStatik *l, ListStatik_ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    LISTELMT(*l, listLength_ListStatik(*l)) = val;
}


/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst_ListStatik(ListStatik *l, ListStatik_ElType *val)
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    int i;
    if (!isEmpty_ListStatik(*l)){
        *val = LISTELMT(*l, 0);
        for (i = 0; i < listLength_ListStatik(*l) - 1; i++){
            LISTELMT(*l, i) = LISTELMT(*l, i + 1);
            }
        }
        LISTELMT(*l, listLength_ListStatik(*l) - 1) = LISTMARK;
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAt_ListStatik(ListStatik *l, ListStatik_ElType *val, ListStatik_IdxType idx)
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
{
    int i;
    if (!isEmpty_ListStatik(*l)){
        *val = LISTELMT(*l, idx);
        for (i = idx; i < listLength_ListStatik(*l) - 1; i++){
            LISTELMT(*l, i) = LISTELMT(*l, i + 1);
            }
        }
        LISTELMT(*l, listLength_ListStatik(*l) - 1) = LISTMARK;
}

void deleteLast_ListStatik(ListStatik *l, ListStatik_ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    if (!isEmpty_ListStatik(*l)){
        *val = LISTELMT(*l, listLength_ListStatik(*l) - 1);
        LISTELMT(*l, listLength_ListStatik(*l) - 1) = LISTMARK;
    }
}

/* ********** SORTING ********** */
void sortList_ListStatik(ListStatik *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int i, j;
    ListStatik_ElType temp;
    for (i = 0; i < listLength_ListStatik(*l) - 1; i++) {
        for (j = i + 1; j < listLength_ListStatik(*l); j++) {
            if (asc) {
                if (LISTELMT(*l, i) > LISTELMT(*l, j)) {
                    temp = LISTELMT(*l, i);
                    LISTELMT(*l, i) = LISTELMT(*l, j);
                    LISTELMT(*l, j) = temp;
                }
            } else {
                if (LISTELMT(*l, i) < LISTELMT(*l, j)) {
                    temp = LISTELMT(*l, i);
                    LISTELMT(*l, i) = LISTELMT(*l, j);
                    LISTELMT(*l, j) = temp;
                }
            }
        }
    }
}

ListStatik concat_ListStatik(ListStatik l1, ListStatik l2){
    ListStatik l3;
    int i;
    CreateListStatik(&l3);
    for (i = 0; i < listLength_ListStatik(l1); i++){
        insertLast_ListStatik(&l3, LISTELMT(l1, i));
    }
    for (i = 0; i < listLength_ListStatik(l2); i++){
        insertLast_ListStatik(&l3, LISTELMT(l2, i));
    }
    return l3;
}

void removeDuplicates(ListStatik *l){
    int i, j;
    for (i = 0; i < listLength_ListStatik(*l); i++){
        for (j = i + 1; j < listLength_ListStatik(*l); j++){
            if (LISTELMT(*l, i) == LISTELMT(*l, j)){
                deleteAt_ListStatik(l, &LISTELMT(*l, j), j);
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int LISTDIN_CAPACITY)
/* I.S. l sembarang, LISTDIN_CAPACITY > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas LISTDIN_CAPACITY */
{
    BUFFER(*l) = (int*) malloc(LISTDIN_CAPACITY*sizeof(int));
    NEFF(*l) = 0;
    LISTDIN_CAPACITY(*l) = LISTDIN_CAPACITY;
}

void dealocateList_ListDin(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, LISTDIN_CAPACITY(l)=0; NEFF(l)=0 */
{
    free(BUFFER(*l));
    LISTDIN_CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int listLength_ListDin(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
ListDin_IdxType getFirstIdx_ListDin(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return 0;
}

ListDin_IdxType getLastIdx_ListDin(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListDin(ListDin l, ListDin_IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= 0 && i < LISTDIN_CAPACITY(l));
}

boolean isIdxEff_ListDin(ListDin l, ListDin_IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list l */
/* yaitu antara 0..NEFF(l) */
{
    return (i >= 0 && i < NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty_ListDin(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return (NEFF(l) == 0);
}

/* *** Test list penuh *** */
boolean isFull_ListDin(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return (NEFF(l) == LISTDIN_CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList_ListDin(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= LISTDIN_CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= LISTDIN_CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    int n,i;
    // Baca banyaknya elemen dan divalidasi
    scanf("%d", &n);
    while (n < 0 || n > LISTDIN_CAPACITY(*l)) {
        scanf("%d", &n);
    }
    NEFF(*l) = n;

    // Baca elemen
    if (n != 0){ // List akan dibaca hanya jika list tidak kosong
        for (i = 0; i < n; i++) {
            scanf("%d", &ELMT(*l, i));
        }
    }
}

void printList_ListDin(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    int i;
    printf("[");
    if (listLength_ListDin(l) != 0) {
        for (i = 0; i < listLength_ListDin(l) - 1; i++) {
            printf("%d,", ELMT(l, i));
        }
        printf("%d", ELMT(l, i));
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList_ListDin(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    ListDin l3;
    int i;
    CreateListDin(&l3, LISTDIN_CAPACITY(l1));
    NEFF(l3) = NEFF(l1);
    for (i = 0; i < listLength_ListDin(l1); i++) {
        if (plus) {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        } else {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual_ListDin(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
   int i = 0;
   if (listLength_ListDin(l1) == listLength_ListDin(l2)){
      while (ELMT(l1, i) == ELMT(l2, i) && i != listLength_ListDin(l1)){
          i++;
      }
      return (i == listLength_ListDin(l1));
   }
   else{
      return false;
   }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
ListDin_IdxType indexOf_ListDin(ListDin l, ListDin_ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    ListDin_IdxType i = 0;
    boolean found = false;
    while (!found && i < NEFF(l)) {
        if (ELMT(l, i) == val) {
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
void extremeValues_ListDin(ListDin l, ListDin_ElType *max, ListDin_ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i = 1; i < NEFF(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList_ListDin(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan LISTDIN_CAPACITY sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
    int i;
    dealocateList_ListDin(lOut);
    CreateListDin(lOut, LISTDIN_CAPACITY(lIn));
    for (i = 0; i < NEFF(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
}

ListDin_ElType sumList_ListDin(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    int i;
    ListDin_ElType sum = 0;
    for (i = 0; i < NEFF(l); i++) {
        sum += ELMT(l, i);
    }
    return sum;
}

int countVal_ListDin(ListDin l, ListDin_ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    int i;
    int count = 0;
    for (i = 0; i < listLength_ListDin(l); i++) {
        if (ELMT(l, i) == val) {
            count++;
        }
    }
    return count;
}

/* ********** SORTING ********** */
void sort_ListDin(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int i, j;
    ListDin_ElType temp;
    for (i = 0; i < NEFF(*l) - 1; i++) {
        for (j = i + 1; j < NEFF(*l); j++) {
            if (asc) {
                if (ELMT(*l, i) > ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            } else {
                if (ELMT(*l, i) < ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast_ListDin(ListDin *l, ListDin_ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
{
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast_ListDin(ListDin *l, ListDin_ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    // if (NEFF(*l) > 0) {
    //     *val = ELMT(*l, NEFF(*l) - 1);
    //     NEFF(*l)--;
    // }
    *val = ELMT(*l, NEFF(*l)-1);
    NEFF(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList_ListDin(ListDin *l, int num)
/* Proses : Menambahkan LISTDIN_CAPACITY l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    ListDin temp;
    CreateListDin(&temp, LISTDIN_CAPACITY(*l));
    copyList_ListDin(*l, &temp);
    int tempNeff = NEFF(*l);
    dealocateList_ListDin(l);
    CreateListDin(l, LISTDIN_CAPACITY(temp) + num);
    NEFF(*l) = tempNeff;
   
    int i;
    for (i = 0; i < listLength_ListDin(temp); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}

void shrinkList_ListDin(ListDin *l, int num)
/* Proses : Mengurangi LISTDIN_CAPACITY sebanyak num */
/* I.S. List sudah terdefinisi, ukuran LISTDIN_CAPACITY > num, dan nEff < LISTDIN_CAPACITY - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    ListDin temp;
    CreateListDin(&temp, LISTDIN_CAPACITY(*l));
    copyList_ListDin(*l, &temp);
    int tempNeff = NEFF(*l);

    CreateListDin(l, LISTDIN_CAPACITY(temp) - num);

    NEFF(*l) = tempNeff;
    if(LISTDIN_CAPACITY(temp) - num < NEFF(*l)){
        NEFF(*l) = LISTDIN_CAPACITY(temp) - num;
    }
   
    int i;
    for (i = 0; i < listLength_ListDin(temp); i++) {
      ELMT(*l, i) = ELMT(temp, i);
    }
}

void compressList_ListDin(ListDin *l)
/* Proses : Mengubah LISTDIN_CAPACITY sehingga nEff = LISTDIN_CAPACITY */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = LISTDIN_CAPACITY */
{
    shrinkList_ListDin(l, LISTDIN_CAPACITY(*l)-NEFF(*l));
}
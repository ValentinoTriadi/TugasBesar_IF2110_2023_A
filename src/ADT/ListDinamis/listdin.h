#ifndef LISTDIN_H
#define LISTDIN_H

#include "../boolean.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ListDin_ElType; /* type elemen list */
typedef int ListDin_IdxType;
typedef struct
{
    ListDin_ElType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int listdin_capacity;   /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..listdin_capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.listdin_capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define LISTDIN_CAPACITY(l) (l).listdin_capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int listdin_capacity);
/* I.S. l sembarang, listdin_capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas listdin_capacity */

void dealocateList_ListDin(ListDin *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, listdin_capacity(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength_ListDin(ListDin l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
ListDin_IdxType getFirstIdx_ListDin(ListDin l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
ListDin_IdxType getLastIdx_ListDin(ListDin l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListDin(ListDin l, ListDin_IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff_ListDin(ListDin l, ListDin_IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty_ListDin(ListDin l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull_ListDin(ListDin l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList_ListDin(ListDin *l);
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= listdin_capacity(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= listdin_capacity(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList_ListDin(ListDin l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList_ListDin(ListDin l1, ListDin l2, boolean plus);
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual_ListDin(ListDin l1, ListDin l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
ListDin_IdxType indexOf_ListDin(ListDin l, ListDin_ElType val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ListDin_ElType *max, ListDin_ElType *min);
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList_ListDin(ListDin lIn, ListDin *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan listdin_capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ListDin_ElType sumList_ListDin(ListDin l);
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal_ListDin(ListDin l, ListDin_ElType val);
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort_ListDin(ListDin *l, boolean asc);
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast_ListDin(ListDin *l, ListDin_ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast_ListDin(ListDin *l, ListDin_ElType *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList_ListDin(ListDin *l, int num);
/* Proses : Menambahkan listdin_capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList_ListDin(ListDin *l, int num);
/* Proses : Mengurangi listdin_capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran listdin_capacity > num, dan nEff < listdin_capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList_ListDin(ListDin *l);
/* Proses : Mengubah listdin_capacity sehingga nEff = listdin_capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = listdin_capacity */

#endif
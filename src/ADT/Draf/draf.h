#ifndef DRAF_H
#define DRAF_H

#include "../boolean.h"
#include "../Time/datetime.h"
#include "../Mesin-Kata/wordmachine.h"

#define Nil -1
#define MaxElDraf 100
/* Nil adalah stack dengan elemen kosong . */
typedef struct
{
    Word text; // Menggunakan Word dari wordmachine.h
    DATETIME timestamp;
} Draft;

typedef Draft infotypeDraf;
typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
    infotypeDraf T[MaxElDraf]; /* tabel penyimpan elemen */
    address TOP;               /* alamat TOP: elemen puncak */
} Stack;

typedef struct
{
    Stack Draf[20];
}ListDraf;


/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxElDraf-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyDraf(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElDraf */
/* jadi indeksnya antara 0.. MaxElDraf */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack *S, infotypeDraf X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack *S, infotypeDraf *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void CreateDraft();
void ViewLastDraft();
void DeleteDraft();
void reverseStack(int idx);

#endif
/* File : prioqueueTeman.h */

#include "prioqueueReq.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty(PrioQueueReq Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}
boolean IsFull(PrioQueueReq Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return MaxEl(Q) == NBElmt(Q);
}
int NBElmt(PrioQueueReq Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q))
    {
        return 0;
    }
    else
    {
        if ((Tail(Q) - Head(Q)) >= 0)
        {
            return Tail(Q) - Head(Q) + 1;
        }
        else
        {
            return MaxEl(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }
}

/* *** Kreator *** */
void MakeEmpty(PrioQueueReq *Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype *)malloc((Max) * sizeof(infotype));
    if ((*Q).T == NULL)
    {
        MaxEl(*Q) = 0;
    }
    else
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueReq *Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueueReq *Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan Jumlah Teman */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    int i, j;
    infotype temp;

    // Jika queue kosong
    if (IsEmpty(*Q))
    {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else
    {
        Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
        InfoTail(*Q) = X;

        i = Tail(*Q);
        j = (i - 1 + MaxEl(*Q)) % MaxEl(*Q);

        // compare dan swap sampai elemen benar
        while (i != Head(*Q) && JumlahTeman(Elmt(*Q, i)) < JumlahTeman(Elmt(*Q, j)))
        {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = (i == 0) ? (MaxEl(*Q) - 1) : (i - 1);
        }
    }
}
void Dequeue(PrioQueueReq *Q, infotype *X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    //Check jika hanya ada satu element
    if (NBElmt(*Q) == 1)
    {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        *X = InfoHead(*Q);

        //Update Head
        if (Head(*Q) == MaxEl(*Q) - 1)
        {
            Head(*Q) = 0;
        }
        else
        {
            Head(*Q) = Head(*Q) + 1;
        }
    }
}

/* Operasi Tambahan */
void PrintPrioQueueTeman(PrioQueueReq Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar */
{
     int i = Head(Q);
    
    // Check if the queue is empty
    if (IsEmpty(Q)) {
        printf("Queue Kosong.\n");
        return;
    }

    printf("List Teman:\n");

    do {
        printf("Nama: %s, Jumlah Teman: %d\n", Nama(Elmt(Q, i)), JumlahTeman(Elmt(Q, i)));
        i = (i + 1) % MaxEl(Q);
    } while (i != (Tail(Q) + 1) % MaxEl(Q));

    printf("\n");
}

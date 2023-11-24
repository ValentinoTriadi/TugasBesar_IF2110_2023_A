#include "../Database/db.h"
#include "utas.h"
#include <stdio.h>
#include <stdlib.h>

extern int CurrentUser;
extern ListUtas DaftarUtas;


AddressUtas newNode(Word isi)
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan AddressUtas p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressUtasnya Last, maka NEXT(Last)=NULL */
{
    AddressUtas p = (AddressUtas)malloc(sizeof(Utas));
    if (p != NULL)
    {
        p->isi = isi;
        p->next = NULL;
        p->time = getLocalTime();
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(ListUtas *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    for (int i = 0; i < 100; i++)
    {
        l->utasUtama[i].pertama.next = NULL;
    }
}

/****************** TEST LIST KOSONG ******************/

boolean isEmpty(ListUtas *l)
{
    return l == NULL;
}

void UTAS(int idKicau)
{
    // Check idKicau
    int idx = findIdxbyID(idKicau);

    if (idx != -1)
    {
        if (CurrentUser == DaftarKicau.kicau[idx].author)
        {
            boolean checkUtas = false;
            for (int i = 0; i < DaftarKicau.nEff; i++)
            {
                if (idKicau == DaftarUtas.utasUtama[i].idKicauUtama)
                {
                    checkUtas = true;
                    break;
                }
            }

            if (!checkUtas)
            {
                DaftarUtas.utasUtama[DaftarUtas.neffUtas].idKicauUtama = idKicau;
                printf("Masukkan Kicauan : ");
                STARTINPUT();
                Utas utas;
                AddressUtas p = newNode(currentSentence);
                DaftarUtas.utasUtama[DaftarUtas.neffUtas].pertama.next = p;
                printWord(DaftarUtas.utasUtama[DaftarUtas.neffUtas].pertama.isi);

                DaftarUtas.neffUtas++;
                printf("Utas Berhasil Dibuat\n");
                boolean stopUtas = false;
                while (!stopUtas)
                {
                    printf("Apakah anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
                    STARTINPUT();
                    if (isEqualWordStr(currentSentence, "YA"))
                    {
                        printf("Masukkan Kicauan : \n");
                        STARTINPUT();
                        AddressUtas temp = newNode(currentSentence);
                        p->next = temp;
                        p = p->next;
                    }
                    else
                    {
                        stopUtas = true;
                    }
                }
            }
            else
            {
                printf("Gagal membuat utas dari sebuah utas\n");
            }
        }
        else
        {
            printf("Utas ini bukan milik anda\n");
        }
    }
    else
    {
        printf("Kicauan tidak ditemukan\n");
    }
}

void cetakUtas(int IDUtas)
{
    int idKicau = DaftarUtas.utasUtama[IDUtas].idKicauUtama;
    // printf("ID KICAU = %d\n", DaftarUtas.utasUtama[IDUtas].idKicauUtama);

    PrintTweet(DaftarKicau.kicau[findIdxbyID(idKicau)]);

    AddressUtas p = DaftarUtas.utasUtama[IDUtas].pertama.next;
    int idx = 1;
    while (p != NULL)
    {
        printf("\n");
        printf("  | Index = %d\n", idx);
        printf("  | ");
        printWord(DaftarPengguna.pengguna[DaftarKicau.kicau[findIdxbyID(idKicau)].author].nama);
        printf("\n  | ");
        TulisDATETIME(p->time);
        printf("\n  | ");
        printWord(p->isi);
        printf("\n");
        idx++;

        p = p->next;
    }
}

void hapusUtas(int IDUtas, int idx)
{
    // Check IDutas valid atau tidak
    if (IDUtas > DaftarUtas.neffUtas)
    {
        printf("Utas Tidak ditemukan\n");
        return;
    }
    int idKicau = DaftarUtas.utasUtama[IDUtas].idKicauUtama;
    
    // Check Author Utas
    if (CurrentUser != (DaftarKicau.kicau[DaftarUtas.utasUtama[IDUtas].idKicauUtama].author))
    {
        printf("Utas ini bukan milik anda\n");
        return;
    }
    else
    {
        if (idx != 0)
        {
            AddressUtas p = DaftarUtas.utasUtama[IDUtas].pertama.next;
            int i = 1;
            while (i < idx-1 && p != NULL)
            {
                p = p->next;
                i++;
            }
            if (p == NULL)
            {
                printf("Kicauan sambungan dengan index %d, tidak ditemukan pada utas!\n",idx);
                return;
            }
           else if (DaftarUtas.utasUtama[IDUtas].pertama.next->next == NULL)
            {
                // Hanya satu node tersisa dalam linked list
                AddressUtas temp = DaftarUtas.utasUtama[IDUtas].pertama.next;
                DaftarUtas.utasUtama[IDUtas].pertama.next = NULL; // Mengatur kepala linked list menjadi NULL
                free(temp);
                printf("Utas Berhasil Dihapus\n");
            }
            else
            {
                // Lebih dari satu node dalam linked list
            
                AddressUtas temp = p->next;
                p->next = p->next->next;
                //DaftarUtas.utasUtama[IDUtas].pertama.next = temp->next;
                free(temp);
                printf("Utas Berhasil Dihapus\n");
            }
        }else{
            printf("Anda tidak bisa menghapus kicauan utama\n");
        }
    }
}

void sambungUtas(int IDUtas, int idx)
{

    // Check IDutas valid atau tidak
    if (IDUtas > DaftarUtas.neffUtas)
    {
        printf("Utas Tidak ditemukan\n");
        return;
    }

    // Check Author Utas
    if (CurrentUser != (DaftarKicau.kicau[DaftarUtas.utasUtama[IDUtas].idKicauUtama].author))
    {
        printf("Utas ini bukan milik anda\n");
        return;
    }
    else
    {
        // loop idx
        AddressUtas p = DaftarUtas.utasUtama[IDUtas].pertama.next;
        int i = 1;
        while (i < idx - 1 && p != NULL)
        {
            p = p->next;
            i++;
        }
        if (p == NULL)
        {
            printf("Index terlalu tinggi\n");
            return;
        }
        else
        {
            printf("Masukkan Kicauan : ");
            STARTINPUT();
            AddressUtas temp = newNode(currentSentence);
            temp->next = p->next;
            p->next = temp;
            printf("Utas Berhasil Dibuat\n");
        }
    }
}
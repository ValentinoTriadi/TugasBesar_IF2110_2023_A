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
    for (int i = 0; i < 100; i++){
        l->utasUtama[i].pertama.next = NULL;
    }
}

/****************** TEST LIST KOSONG ******************/

boolean isEmpty(ListUtas *l){
    return l==NULL;
}

void UTAS(int idKicau){
    //Check idKicau
    int idx = findIdxbyID(idKicau);

    if(idx != -1){
        if(CurrentUser == DaftarKicau.kicau[idx].author){
            boolean checkUtas = false;
            for(int i =0; i < DaftarKicau.nEff;i++){
                if(idKicau == DaftarUtas.utasUtama[i].idKicauUtama){
                    checkUtas = true;
                    break;
                }
            }

            if(!checkUtas){
                DaftarUtas.utasUtama[DaftarUtas.neffUtas].idKicauUtama = idKicau;
                printf("Masukkan Kicauan : ");
                STARTINPUT();
                Utas utas;
                AddressUtas p = newNode(currentSentence);
                DaftarUtas.utasUtama[DaftarUtas.neffUtas].pertama.next = p;
                printWord(DaftarUtas.utasUtama[DaftarUtas.neffUtas].pertama.isi);
                if(DaftarUtas.utasUtama[DaftarUtas.neffUtas].pertama.next == NULL){
                    printf("gagal");
                }
                DaftarUtas.neffUtas++;
                printf("Utas Berhasil Dibuat\n");
                boolean stopUtas = false;
                while(!stopUtas){
                    printf("Apakah anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
                    STARTINPUT();
                    if(isEqualWordStr(currentSentence,"YA")){
                        printf("Masukkan Kicauan : \n");
                        STARTINPUT();
                        AddressUtas temp = newNode(currentSentence);
                        p = p->next;
                        p = temp;
                    }
                    else{
                        stopUtas = true;
                    }
                }  
            }else{
                printf("Gagal membuat utas dari sebuah utas\n");
            }
        }else{
            printf("Utas ini bukan milik anda\n");
        }
    }else{
        printf("Kicauan tidak ditemukan\n");
    }
}

void cetakUtas(int IDUtas){
    int idKicau = DaftarUtas.utasUtama[IDUtas].idKicauUtama;
    printf("ID KICAU = %d\n", DaftarUtas.utasUtama[IDUtas].idKicauUtama);
    
    PrintTweet(DaftarKicau.kicau[findIdxbyID(idKicau)]);

    AddressUtas p = DaftarUtas.utasUtama[IDUtas].pertama.next;
    while(p != NULL){
        printf("| ID = \n");
        printf("| ");
        printWord(DaftarPengguna.pengguna[DaftarKicau.kicau[idKicau].author].nama);
        printf("\n| ");
        TulisDATETIME(p->time);
        printf("\n| ");
        printWord(p->isi);

        p = p->next;
    }
}




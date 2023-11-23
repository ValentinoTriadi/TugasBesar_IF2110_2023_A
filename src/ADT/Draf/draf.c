#include "../Kicau/tweet.h"
#include "../Database/db.h"
#include "draf.h"
#include <stdio.h>

#define Nil -1 // stack dengan elemen kosong
#define MaxElDraf 100

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

void CreateEmptyDraf(Stack *S)
{
    Top(*S) = Nil;
}

boolean IsEmpty(Stack S)
{
    return Top(S) == Nil;
}

boolean IsFull(Stack S)
{
    return Top(S) == MaxElDraf - 1;
}

void Push(Stack *S, infotypeDraf X)
{
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotypeDraf *X) // Menghapus X dari Stack S.
{
    *X = InfoTop(*S);
    Top(*S)--;
}

void CreateDraft() {
    Draft D;
    printf("Masukkan draf:\n");
    STARTINPUT();
    D.text = currentSentence;     // Menyalin ke struktur Draft
    D.timestamp = getLocalTime(); // Mencatat waktu saat ini
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    
    STARTINPUT();
    if (isEqualWordStr(currentSentence, "HAPUS")){
        printf("Draf telah berhasil dihapus!\n");

    } else if (isEqualWordStr(currentSentence, "SIMPAN")) {
        Push(&Draf, D);
        printf("Draf telah berhasil disimpan!\n");

    } else if (isEqualWordStr(currentSentence, "TERBIT")) {
        currentSentence = D.text;
        if (cekInputValid()){
            Kicauan k;
            k.id = GenerateID(); 
            Word temp = currentSentence;
            temp.Length = (temp.Length > 280)? 280 : temp.Length;
            k.text = temp;
            k.like = 0;
            k.author = CurrentUser;
            k.datetime = getLocalTime();

            printf("\nSelamat! Draf kicauan telah diterbitkan!\nDetil kicauan:\n");
            PrintTweet(k);
            AddTweetToList(k);
        }
    }
}

void ViewLastDraft() {
    Draft D;
    if (IsEmpty(Draf)) {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
        return;
    } else {
        D = InfoTop(Draf);
        printf("Ini draf terakhir anda:\n| %02d/%02d/%04d %02d:%02d:%02d\n| ",
               D.timestamp.DD, D.timestamp.MM, D.timestamp.YYYY, Hour(D.timestamp.T),
               Minute(D.timestamp.T), Second(D.timestamp.T));
        printWord(D.text);
        printf("\n");
    }

    printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
    STARTINPUT();

    if (isEqualWordStr(currentSentence, "HAPUS")){
        DeleteDraft();
    } else if (isEqualWordStr(currentSentence, "UBAH")) {
        printf("Masukkan draf:\n");
        STARTINPUT();
        D.text = currentSentence;     // Menyalin ke struktur Draft
        D.timestamp = getLocalTime(); // Mencatat waktu saat ini
        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
        STARTINPUT();

    } else if (isEqualWordStr(currentSentence, "TERBIT")) {
        currentSentence = D.text;
        if (cekInputValid()){
            Kicauan k;
            k.id = GenerateID(); 
            Word temp = currentSentence;
            temp.Length = (temp.Length > 280)? 280 : temp.Length;
            k.text = temp;
            k.like = 0;
            k.author = CurrentUser;
            k.datetime = getLocalTime();
            printf("\nSelamat! Draf kicauan telah diterbitkan!\nDetil kicauan:\n");
            PrintTweet(k);
            AddTweetToList(k);
        }
    }
}

void DeleteDraft()
{
    Draft D;
    if (!IsEmpty(Draf))
    {
        Pop(&Draf, &D);
        printf("Draf telah berhasil dihapus!\n");
    }
    else
    {
        printf("Tidak ada draf yang dapat dihapus.\n");
    }
}
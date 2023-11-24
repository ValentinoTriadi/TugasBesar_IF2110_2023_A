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
    return (Top(S) == Nil);
}

boolean IsFull(Stack S)
{
    return Top(S) == MaxElDraf - 1;
}

void Push(Stack *S, infotypeDraf X)
{
    if (IsEmpty(*S)){
        Top(*S) = 0;
    } else {
        Top(*S)++;
    }   
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotypeDraf *X) // Menghapus X dari Stack S.
{
    *X = InfoTop(*S);
    if (Top(*S) == 0){
        CreateEmptyDraf(S);
    } else {
        Top(*S)--;
    }
}

void CreateDraft() {
    Draft D;
    printf("Masukkan draf:\n");
    STARTINPUT();
    if (!cekInputValid()){
        printf("\nDraf tidak boleh hanya berisi spasi!\n");
    } else {
        D.text = currentSentence;     // Menyalin ke struktur Draft
        D.timestamp = getLocalTime(); // Mencatat waktu saat ini
        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini? (HAPUS/SIMPAN/TERBIT)\n");
        
        STARTINPUT();
        if (isEqualWordStr(currentSentence, "HAPUS")){
            printf("Draf telah berhasil dihapus!\n");

        } else if (isEqualWordStr(currentSentence, "SIMPAN")) {
            Push(&Draf.Draf[CurrentUser], D);
            printf("Draf telah berhasil disimpan!\n");

        } else if (isEqualWordStr(currentSentence, "TERBIT")) {
            Kicauan k;
            k.id = GenerateID(); 
            D.text.Length = (D.text.Length > 280)? 280 : D.text.Length;
            k.text = D.text;
            k.like = 0;
            k.author = CurrentUser;
            k.datetime = D.timestamp;

            printf("\nSelamat! Draf kicauan telah diterbitkan!\nDetil kicauan:\n");
            PrintTweet(k);
            AddTweetToList(k);
        }
    }
}

void ViewLastDraft() {
    Draft D;
    if (IsEmpty(Draf.Draf[CurrentUser])) {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
        return;
    } else {
        D = InfoTop(Draf.Draf[CurrentUser]);
        printf("Ini draf terakhir anda:\n| %02d/%02d/%04d %02d:%02d:%02d\n| ",
               D.timestamp.DD, D.timestamp.MM, D.timestamp.YYYY, Hour(D.timestamp.T),
               Minute(D.timestamp.T), Second(D.timestamp.T));
        printWord(D.text);
        printf("\n");
    }

    printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI/HAPUS/UBAH/TERBIT)\n");
    STARTINPUT();

    if (isEqualWordStr(currentSentence, "HAPUS")){
        DeleteDraft();

    } else if (isEqualWordStr(currentSentence, "UBAH")) {
        printf("Masukkan draf:\n");
        STARTINPUT();
        if (cekInputValid()){
            D.text = currentSentence;     // Menyalin ke struktur Draft
            D.timestamp = getLocalTime(); // Mencatat waktu saat ini

            printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
            STARTINPUT();

            if (isEqualWordStr(currentSentence, "HAPUS")){
                DeleteDraft();

            } else if (isEqualWordStr(currentSentence, "SIMPAN")) {
                InfoTop(Draf.Draf[CurrentUser]) = D;
                printf("Draf telah berhasil disimpan!\n");

            } else if (isEqualWordStr(currentSentence, "TERBIT")) {
                Kicauan k;
                k.id = GenerateID(); 
                D.text.Length = (D.text.Length > 280)? 280 : D.text.Length;
                k.text = D.text;
                k.like = 0;
                k.author = CurrentUser;
                k.datetime = D.timestamp;
                Draft DD;
                Pop(&Draf.Draf[CurrentUser], &D);

                printf("\nSelamat! Draf kicauan telah diterbitkan!\nDetil kicauan:\n");
                PrintTweet(k);
                AddTweetToList(k);
            }
        } else {
            printf("\nDraf tidak boleh hanya berisi spasi!\nDraf tidak berhasil diubah!\n");
        }

    } else if (isEqualWordStr(currentSentence, "TERBIT")) {
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
        Draft DD;
        Pop(&Draf.Draf[CurrentUser], &DD);
    }
}

void DeleteDraft()
{
    Draft D;
    if (!IsEmpty(Draf.Draf[CurrentUser]))
    {
        Pop(&Draf.Draf[CurrentUser], &D);
        printf("top %d\n", Top(Draf.Draf[CurrentUser]));
        if(IsEmpty(Draf.Draf[CurrentUser])) CreateEmptyDraf(&Draf.Draf[CurrentUser]);
        printf("Draf telah berhasil dihapus!\n");
    }
    else
    {
        printf("Tidak ada draf yang dapat dihapus.\n");
    }
}

void reverseStack (int idx){
    Stack rev;
    CreateEmptyDraf(&rev);
    infotypeDraf x;
    while (!IsEmpty(Draf.Draf[idx])){
        Pop(&Draf.Draf[idx],&x);
        Push(&rev, x);
    }
    Draf.Draf[idx] = rev;
}
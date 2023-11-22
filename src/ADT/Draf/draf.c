#include "draf.h"
#include "../Database/db.h"
#include <stdio.h>


void CreateDraft()
{
    Draft D;
    printf("Masukkan draf:\n");
    STARTINPUT();
    CopyInput();
    D.text = currentSentence; // Menyalin ke struktur Draft
    D.timestamp = getLocalTime(); // Mencatat waktu saat ini
    Push(&Draf, D);
}

void ViewLastDraft()
{
    if (IsEmpty(Draf))
    {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
    else
    {
        Draft D = InfoTop(Draf);
        printf("Ini draf terakhir anda:\n| %02d/%02d/%04d %02d:%02d:%02d\n| ",
               D.timestamp.DD, D.timestamp.MM, D.timestamp.YYYY, Hour(D.timestamp.T),
               Minute(D.timestamp.T), Second(D.timestamp.T));
        printWord(D.text);
        printf("\n");
    }
}

void UpdateDraft()
{
    if (!IsEmpty(Draf))
    {
        Draft D;
        Pop(&Draf, &D); // Menghapus draf lama
        printf("Masukkan draf yang baru:\n");
        STARTINPUT();              // Menggunakan mesin kata untuk membaca input
        D.text = currentSentence; // Menyalin ke struktur Draft
        D.timestamp = getLocalTime(); // Mencatat waktu saat ini
        Push(&Draf, D);               // Menyimpan draf baru ke stack
    }
    else
    {
        printf("Tidak ada draf yang dapat diperbarui.\n");
    }
}

void DeleteDraft()
{
    Draft D;
    if (!IsEmpty(Draf))
    {
        Pop(&Draf, &D); // Menghapus draf dari stack
        printf("Draf telah berhasil dihapus!\n");
    }
    else
    {
        printf("Tidak ada draf yang dapat dihapus.\n");
    }
}

void PublishDraft()
{
    Draft D;
    if (!IsEmpty(Draf))
    {
        Pop(&Draf, &D); // Mengambil draf dari stack
        // Logika untuk menerbitkan draf
        Kicauan k;
        CreateTweet(&k);
        k.author = CurrentUser;
        k.datetime = D.timestamp;
        k.text = D.text;
        printf("Selamat! Draf kicauan telah diterbitkan!\nDetil kicauan:\n| ID = 11\n| John Doe\n| %02d/%02d/%04d %02d:%02d:%02d\n| ",
               D.timestamp.DD, D.timestamp.MM, D.timestamp.YYYY, Hour(D.timestamp.T),
               Minute(D.timestamp.T), Second(D.timestamp.T));
        printWord(D.text);
        printf("\n| Disukai: 0\n");
    }
    else
    {
        printf("Tidak ada draf yang dapat diterbitkan.\n");
    }
}

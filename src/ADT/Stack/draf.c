#include "draft.h"
#include <stdio.h>
int main()
{
    Stack S;
    Draft D;
    CreateEmpty(&S);

    // Contoh penggunaan
    // CreateDraft(&S, &D); // Membuat draf baru
    // ViewLastDraft(S); // Melihat draf terakhir
    // UpdateDraft(&S, &D); // Mengedit draf
    // DeleteDraft(&S); // Menghapus draf
    // PublishDraft(&S); // Menerbitkan draf

    return 0;
}

extern Word currentSentence;

void CreateDraft(Stack *S, Draft *D)
{
    printf("Masukkan draf:\n");
    STARTINPUT();
    CopyInput();
    D->text = currentSentence; // Menyalin ke struktur Draft
    BacaTIME(&(D->timestamp)); // Mencatat waktu saat ini
    Push(S, *D);
}

void ViewLastDraft(Stack S)
{
    if (IsEmpty(S))
    {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
    else
    {
        Draft D = InfoTop(S);
        printf("Ini draf terakhir anda:\n| %02d/%02d/%02d %02d:%02d:%02d\n| ",
               D.timestamp.HH, D.timestamp.MM, D.timestamp.SS, Hour(D.timestamp),
               Minute(D.timestamp), Second(D.timestamp));
        printWord(D.text);
        printf("\n");
    }
}

void UpdateDraft(Stack *S, Draft *D)
{
    if (!IsEmpty(*S))
    {
        Pop(S, D); // Menghapus draf lama
        printf("Masukkan draf yang baru:\n");
        STARTINPUT();              // Menggunakan mesin kata untuk membaca input
        CopyInput();               // Menyalin input ke currentSentence
        D->text = currentSentence; // Menyalin ke struktur Draft
        BacaTIME(&(D->timestamp)); // Mencatat waktu saat ini
        Push(S, *D);               // Menyimpan draf baru ke stack
    }
    else
    {
        printf("Tidak ada draf yang dapat diperbarui.\n");
    }
}

void DeleteDraft(Stack *S)
{
    Draft D;
    if (!IsEmpty(*S))
    {
        Pop(S, &D); // Menghapus draf dari stack
        printf("Draf telah berhasil dihapus!\n");
    }
    else
    {
        printf("Tidak ada draf yang dapat dihapus.\n");
    }
}

void PublishDraft(Stack *S)
{
    Draft D;
    if (!IsEmpty(*S))
    {
        Pop(S, &D); // Mengambil draf dari stack
        // Logika untuk menerbitkan draf
        printf("Selamat! Draf kicauan telah diterbitkan!\nDetil kicauan:\n| ID = 11\n| John Doe\n| %02d/%02d/%02d %02d:%02d:%02d\n| ",
               D.timestamp.HH, D.timestamp.MM, D.timestamp.SS, Hour(D.timestamp),
               Minute(D.timestamp), Second(D.timestamp));
        printWord(D.text);
        printf("\n| Disukai: 0\n");
    }
    else
    {
        printf("Tidak ada draf yang dapat diterbitkan.\n");
    }
}

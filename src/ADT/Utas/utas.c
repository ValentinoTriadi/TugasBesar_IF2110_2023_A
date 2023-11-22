#include "tweet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur Utas
typedef struct
{
    int IDUtas;         // ID dari Utas
    Kicauan *mainTweet; // Pointer ke kicauan utama
    int tweetCount;     // Jumlah kicauan dalam Utas
} Utas;

// Fungsi untuk membuat utas baru
void UTAS(Utas *u, Kicauan *mainTweet)
{
    static int currentID = 1; // Variable statis untuk melacak ID berikutnya
    u->IDUtas = currentID++;
    u->mainTweet = mainTweet;
    u->tweetCount = 1; // Memulai dengan satu kicauan (kicauan utama)
    printf("Utas berhasil dibuat!\\n");
}

// Fungsi untuk menambahkan kicauan ke dalam utas
void SAMBUNG_UTAS(Utas *u, Kicauan *tweet, int index)
{
    if (index < 0 || index > u->tweetCount)
    {
        printf("Index terlalu tinggi!\\n");
        return;
    }

    Kicauan *current = u->mainTweet;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }

    tweet->next = current->next;
    current->next = tweet;
    u->tweetCount++;

    printf("Kicauan berhasil ditambahkan.\\n");
}

// Fungsi untuk menghapus kicauan dari utas
void HAPUS_UTAS(Utas *u, int index)
{
    if (index < 0 || index >= u->tweetCount)
    {
        printf("Index tidak ditemukan pada utas!\\n");
        return;
    }
    if (index == 0)
    {
        printf("Anda tidak bisa menghapus kicauan utama!\\n");
        return;
    }

    Kicauan *current = u->mainTweet;
    Kicauan *toDelete = NULL;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }

    toDelete = current->next;
    current->next = toDelete->next;
    free(toDelete);
    u->tweetCount--;

    printf("Kicauan sambungan berhasil dihapus!\\n");
}

// Fungsi untuk mencetak utas
void CETAK_UTAS(const Utas *u)
{
    printf("Utas ID: %d\\n", u->IDUtas);
    Kicauan *current = u->mainTweet;
    int index = 0;
    while (current != NULL)
    {
        printf("| INDEX = %d\\n| %s\\n", index, current->text);
        current = current->next;
        index++;
    }
}

// Fungsi utama untuk menguji ADT Utas
int main()
{
    // Implementasi uji coba fungsi Utas
    return 0;
}

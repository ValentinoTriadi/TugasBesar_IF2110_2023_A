#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "boolean.h"
#include "matrix.h"
#include "wordmachine.h"
#include "pcolor.h"

#define DEFAULT_COLOR 'R'
#define DEFAULT_SYMBOL '*'

typedef struct
{
    char bio[256];
    char no_hp[20];
    char weton[10];
    char jenis_akun[10];     // "publik" atau "privat"
    char foto_profil[5][5];  // Matriks 5x5
    char warna_profil[5][5]; // Warna matriks 5x5
} Profil;

boolean isValidWeton(const char *weton)
{
    // List dari weton yang valid
    char *validWeton[] = {"pahing", "kliwon", "wage", "pon", "legi"};
    for (int i = 0; i < 5; i++)
    {
        // Mengecek kesamaan string tanpa memperhatikan huruf besar/kecil
        if (strcasecmp(weton, validWeton[i]) == 0)
            return true;
    }
    return false;
}

boolean isValidNoHP(const char *no_hp)
{
    for (int i = 0; i < strlen(no_hp); i++)
    {
        // Memeriksa apakah setiap karakter merupakan digit
        if (!isdigit(no_hp[i]))
            return false;
    }
    return true;
}

void initProfil(Profil *profil)
{
    // Menginisialisasi profil dengan nilai default
    strcpy(profil->bio, "");
    strcpy(profil->no_hp, "");
    strcpy(profil->weton, "");
    strcpy(profil->jenis_akun, "publik");

    // Mengatur foto profil dengan simbol dan warna default
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            profil->foto_profil[i][j] = DEFAULT_SYMBOL;
            profil->warna_profil[i][j] = DEFAULT_COLOR;
        }
    }
}

void ubahProfil(Profil *profil)
{
    char temp[256];
    // Mengubah bio profil
    printf("Masukkan Bio Akun:\n");
    gets(temp);
    if (strcmp(temp, ";") != 0)
        strcpy(profil->bio, temp);

    // Meminta pengguna untuk menginput no. HP sampai mendapatkan input yang valid
    do
    {
        printf("Masukkan No HP:\n");
        gets(temp);
        if (isValidNoHP(temp) || strcmp(temp, ";") == 0)
        {
            strcpy(profil->no_hp, temp);
            break;
        }
        else
        {
            printf("No HP tidak valid. Masukkan lagi yuk!\n");
        }
    } while (true);

    // Meminta pengguna untuk menginput weton sampai mendapatkan input yang valid
    do
    {
        printf("Masukkan Weton:\n");
        gets(temp);
        if (isValidWeton(temp) || strcmp(temp, ";") == 0)
        {
            strcpy(profil->weton, temp);
            break;
        }
        else
        {
            printf("Weton anda tidak valid.\n");
        }
    } while (true);

    printf("Profil Anda sudah berhasil diperbarui!\n");
}

void ubahJenisAkun(Profil *profil)
{
    // Mengubah jenis akun dari publik ke privat atau sebaliknya
    char pilihan[10];
    printf("Saat ini, akun Anda adalah akun %s.\n", profil->jenis_akun);
    printf("Ingin mengubah ke akun %s? (YA/TIDAK) ", (strcmp(profil->jenis_akun, "publik") == 0) ? "Privat" : "Publik");
    gets(pilihan);
    if (strcasecmp(pilihan, "YA") == 0)
    {
        if (strcmp(profil->jenis_akun, "publik") == 0)
        {
            strcpy(profil->jenis_akun, "privat");
        }
        else
        {
            strcpy(profil->jenis_akun, "publik");
        }
        printf("Akun anda sudah diubah menjadi akun %s.\n", profil->jenis_akun);
    }
}

void ubahFotoProfil(Profil *profil)
{
    // Mengubah foto profil dengan meminta input dari pengguna
    printf("Masukkan foto profil yang baru\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            char color, symbol;
            scanf(" %c %c", &color, &symbol);
            profil->warna_profil[i][j] = color;
            profil->foto_profil[i][j] = symbol;
        }
    }
    printf("Foto profil anda sudah berhasil diganti!\n");
}

void tampilkanFotoProfil(const Profil *profil)
{
    // Menampilkan foto profil pengguna ke layar
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c%c ", profil->warna_profil[i][j], profil->foto_profil[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Kode demo untuk menjalankan fungsi di atas
    Profil user;
    initProfil(&user);

    ubahProfil(&user);
    ubahJenisAkun(&user);
    ubahFotoProfil(&user);
    tampilkanFotoProfil(&user);

    return 0;
}

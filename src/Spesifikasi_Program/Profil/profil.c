#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "profil.h"
#include "../boolean.h"

#define DEFAULT_COLOR 'R'
#define DEFAULT_SYMBOL '*'


boolean strEqualsIgnoreCase(Word w1, Word w2)
{
    if (w1.Length != w2.Length)
        return false;

    for (int i = 0; i < w1.Length; i++)
    {
        char c1 = w1.TabWord[i];
        char c2 = w2.TabWord[i];
        if (c1 != c2 && c1 + 32 != c2 && c1 - 32 != c2)
            return false;
    }
    return true;
}

boolean isValidWeton(Word weton)
{
    Word validWeton[5] = {
        {.TabWord = "pahing", .Length = 6},
        {.TabWord = "kliwon", .Length = 6},
        {.TabWord = "wage", .Length = 4},
        {.TabWord = "pon", .Length = 3},
        {.TabWord = "legi", .Length = 4}};

    for (int i = 0; i < 5; i++)
    {
        if (strEqualsIgnoreCase(weton, validWeton[i]))
            return true;
    }
    return false;
}

boolean isValidNoHP(Word no_hp)
{
    for (int i = 0; i < no_hp.Length; i++)
    {
        if (!isdigit(no_hp.TabWord[i]))
            return false;
    }
    return true;
}

void initProfil(Profil *profil)
{
    Word publik = {.TabWord = "publik", .Length = 6};
    profil->bio.Length = 0;
    profil->no_hp.Length = 0;
    profil->weton.Length = 0;
    profil->jenis_akun = publik;
    // Inisialisasi Matrix foto_profil dan warna_profil dengan default
}

// Fungsi untuk menyalin Word
void CopyWord(Word *dest, Word src)
{
    dest->Length = src.Length;
    for (int i = 0; i < src.Length; i++)
    {
        dest->TabWord[i] = src.TabWord[i];
    }
}

void ubahProfil(Profil *profil)
{
    Word temp;

    printf("Masukkan Bio Akun:\n");
    STARTWORD(); // membaca kata
    CopyWord(&temp, currentWord);

    if (!isEqualWord(temp, MakeWord(";")))
    {
        CopyWord(&profil->bio, temp);
    }

    do
    {
        printf("Masukkan No HP:\n");
        STARTWORD();
        CopyWord(&temp, currentWord);

        if (isValidNoHP(temp) || isEqualWord(temp, MakeWord(";")))
        {
            CopyWord(&profil->no_hp, temp);
            break;
        }
        else
        {
            printf("No HP tidak valid. Masukkan lagi yuk!\n");
        }
    } while (true);

    do
    {
        printf("Masukkan Weton:\n");
        STARTWORD();
        CopyWord(&temp, currentWord);

        if (isValidWeton(temp) || isEqualWord(temp, MakeWord(";")))
        {
            CopyWord(&profil->weton, temp);
            break;
        }
        else
        {
            printf("Weton Anda tidak valid.\n");
        }
    } while (true);

    printf("Profil Anda sudah berhasil diperbarui!\n");
}

void ubahJenisAkun(Profil *profil)
{
    Word pilihan;
    Word publik = StrToWord("publik");
    Word privat = StrToWord("privat");
    Word ya = StrToWord("YA");

    printf("Saat ini, akun Anda adalah akun ");
    for (int i = 0; i < profil->jenis_akun.Length; i++)
    {
        printf("%c", profil->jenis_akun.TabWord[i]);
    }
    printf(".\n");

    printf("Ingin mengubah ke akun %s? (YA/TIDAK) ", isEqualWord(profil->jenis_akun, publik) ? "Privat" : "Publik");

    STARTWORD();
    CopyWord(&pilihan, currentWord);

    if (isEqualWord(pilihan, ya))
    {
        if (isEqualWord(profil->jenis_akun, publik))
        {
            CopyWord(&profil->jenis_akun, privat);
        }
        else
        {
            CopyWord(&profil->jenis_akun, publik);
        }

        printf("Akun Anda sudah diubah menjadi akun ");
        for (int i = 0; i < profil->jenis_akun.Length; i++)
        {
            printf("%c", profil->jenis_akun.TabWord[i]);
        }
        printf(".\n");
    }
}

void ubahFotoProfil(Profil *profil)
{
    printf("Masukkan foto profil yang baru\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            char color, symbol;
            scanf(" %c %c", &color, &symbol);
            profil->warna_profil.mem[i][j] = color; // Mengganti .elmt dengan .Mem
            profil->foto_profil.mem[i][j] = symbol; // Mengganti .elmt dengan .Mem
        }
    }
    printf("Foto profil Anda sudah berhasil diganti!\n");
}

void tampilkanFotoProfil(const Profil *profil)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            char color = profil->warna_profil.mem[i][j];
            switch (color)
            {
            case 'R':
                print_red(profil->foto_profil.mem[i][j]);
                break;
            case 'G':
                print_green(profil->foto_profil.mem[i][j]);
                break;
            case 'B':
                print_blue(profil->foto_profil.mem[i][j]);
                break;
            // Anda bisa menambahkan lebih banyak warna jika dibutuhkan
            default:
                printf("%c", profil->foto_profil.mem[i][j]);
                break;
            }
        }
        printf("\n");
    }
}

int main()
{
    Profil user;
    initProfil(&user);

    ubahProfil(&user);
    ubahJenisAkun(&user);
    ubahFotoProfil(&user);
    tampilkanFotoProfil(&user);

    return 0;
}
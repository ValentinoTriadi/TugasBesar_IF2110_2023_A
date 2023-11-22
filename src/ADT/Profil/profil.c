#include <stdio.h>
// #include <string.h>
// #include <ctype.h>
#include "profil.h"

extern Word currentSentence;
extern Word currentWord;

boolean isDigit(char x){
    return ((int) x >= 48 && (int) x <= 57);
}

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
        if (!isDigit(no_hp.TabWord[i]))
            return false;
    }
    return true;
}

void initProfil(Profil *p)
{
    Word publik = {.TabWord = "publik", .Length = 6};
    p->bio.Length = 0;
    p->no_hp.Length = 0;
    p->weton.Length = 0;
    p->jenis_akun = publik;
    // Inisialisasi Matrix foto_profil dan warna_profil dengan default
}

// Fungsi untuk menyalin Word
void SalinKata(Word *dest, Word src)
{
    dest->Length = src.Length;
    for (int i = 0; i < src.Length; i++)
    {
        dest->TabWord[i] = src.TabWord[i];
    }
}

void ubahProfil(Profil *p)
{

    printf("Masukkan Bio Akun:\n");
    STARTINPUT(); // membaca kata
    Word temp = currentSentence;

    if (temp.Length)
    {
        SalinKata(&p->bio, temp);
    }

    do
    {
        printf("Masukkan No HP:\n");
        STARTINPUT();
        SalinKata(&temp, currentSentence);

        if (isValidNoHP(temp) || isEqualWordStr(temp, ";"))
        {
            SalinKata(&p->no_hp, temp);
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
        STARTINPUT();
        SalinKata(&temp, currentSentence);

        if (isValidWeton(temp) || isEqualWordStr(temp, ";"))
        {
            SalinKata(&p->weton, temp);
            break;
        }
        else
        {
            printf("Weton Anda tidak valid.\n");
        }
    } while (true);

    printf("Profil Anda sudah berhasil diperbarui!\n");
}

void ubahJenisAkun(Profil *p)
{
    Word pilihan;
    Word publik = StrToWord("publik");
    Word privat = StrToWord("privat");
    Word ya = StrToWord("YA");

    printf("Saat ini, akun Anda adalah akun ");
    for (int i = 0; i < p->jenis_akun.Length; i++)
    {
        printf("%c", p->jenis_akun.TabWord[i]);
    }
    printf(".\n");

    printf("Ingin mengubah ke akun %s? (YA/TIDAK) ", isEqualWordWord(p->jenis_akun, publik) ? "Privat" : "Publik");

    STARTINPUT();
    SalinKata(&pilihan, currentSentence);

    if (isEqualWordWord(pilihan, ya))
    {
        if (isEqualWordWord(p->jenis_akun, publik))
        {
            SalinKata(&p->jenis_akun, privat);
        }
        else
        {
            SalinKata(&p->jenis_akun, publik);
        }

        printf("Akun Anda sudah diubah menjadi akun ");
        for (int i = 0; i < p->jenis_akun.Length; i++)
        {
            printf("%c", p->jenis_akun.TabWord[i]);
        }
        printf(".\n");
    }
}

void ubahFotoProfil(Profil *p)
{
    printf("Masukkan foto Profil yang baru\n");
    for (int i = 0; i < 5; i++)
    {
        STARTWORD();
        for (int j = 0; j < 5; j++)
        {
            char color, symbol;
            scanf(" %c %c", &color, &symbol);
            p->warna_profil.mem[i][j] = color; // Mengganti .elmt dengan .Mem
            p->foto_profil.mem[i][j] = symbol; // Mengganti .elmt dengan .Mem
        }
    }
    printf("Foto Profil Anda sudah berhasil diganti!\n");
}

void tampilkanFotoProfil(Profil *p)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            char color = p->warna_profil.mem[i][j];
            switch (color)
            {
            case 'R':
                print_red(p->foto_profil.mem[i][j]);
                break;
            case 'G':
                print_green(p->foto_profil.mem[i][j]);
                break;
            case 'B':
                print_blue(p->foto_profil.mem[i][j]);
                break;
            // Anda bisa menambahkan lebih banyak warna jika dibutuhkan
            default:
                printf("%c", p->foto_profil.mem[i][j]);
                break;
            }
        }
        printf("\n");
    }
}
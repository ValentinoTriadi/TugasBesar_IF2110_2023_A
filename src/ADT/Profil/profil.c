#include <stdio.h>
#include "../Database/db.h"
#include "profil.h"


boolean isDigit(char x){
    return ((int) x >= 48 && (int) x <= 57);
}

boolean strEqualsIgnoreCase(Word w1, Word w2)
{
    if (w1.Length != w2.Length) return false;
    for (int i = 0; i < w1.Length; i++) {
        char c1 = w1.TabWord[i];
        char c2 = w2.TabWord[i];
        if (c1 != c2 && c1 + 32 != c2 && c1 - 32 != c2)
            return false;
    }
    return true;
}

boolean isValidWeton(Word weton)
{
    char* validWeton[5] = {"pahing", "kliwon", "wage", "pon", "legi"};

    for (int i = 0; i < 5; i++) {
        if (isEqualWordStr(toLowerCase(weton), validWeton[i])) return true;
    }
    return false;
}

boolean isValidNoHP(Word no_hp)
{
    for (int i = 0; i < no_hp.Length; i++)
    {
        if (!isDigit(no_hp.TabWord[i])) return false;
    }
    return true;
}

void printProfil(Profil p){
    printf(" | Nama: ");
    printWord(p.nama);
    printf("\n | Bio: ");
    printWord(p.bio);
    printf("\n | No HP: ");
    printWord(p.no_hp);
    printf("\n | Weton: ");
    printWord(p.weton);
    printf("\n");
}

void initProfil(Profil *p) {
    p->bio.Length = 0;
    p->no_hp.Length = 0;
    p->weton.Length = 0;
    p->jenis_akun = publik;
    createMatrixFoto(5,5,&p->foto_profil);
    createMatrixWarna(5,5,&p->warna_profil);
}

void ubahProfil() {
    printProfil(DaftarPengguna.pengguna[CurrentUser]);
    
    printf("\nMasukkan Bio Akun:\n");
    currentSentence.Length = 0;
    STARTINPUT(); // membaca kata
    Word temp = currentSentence;
    if (temp.Length) {  
        temp.Length = (temp.Length > 135)? 135 : temp.Length; // Cut jadi 135 char
        DaftarPengguna.pengguna[CurrentUser].bio = temp;
    }

    do {
        printf("Masukkan No HP:\n");
        currentSentence.Length = 0;
        STARTINPUT();
        temp = currentSentence;

        if (!temp.Length) break;
        if (isValidNoHP(temp)){
            DaftarPengguna.pengguna[CurrentUser].no_hp = temp;
            break;
        } else {
            printf("No HP tidak valid. Masukkan lagi yuk!\n");
        }
    } while (true);

    do {
        printf("Masukkan Weton:\n");
        currentSentence.Length = 0;
        STARTINPUT();
        temp = currentSentence;

        if (!temp.Length) break;
        if (isValidWeton(temp)) {
            DaftarPengguna.pengguna[CurrentUser].weton = toLowerCase(temp);
            break;
        } else {
            printf("Weton Anda tidak valid.\n");
        }
    } while (true);

    printf("\nProfil Anda sudah berhasil diperbarui!\n");
}

void lihatProfile(Word nama){
    int idx = findIndexUser(nama);
    if (idx == -1){
        printf("\n\nWah, akun ");
        printWord(nama);
        printf(" tidak ditemukan!\n");
        return;
    }
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    // ISFOLLOWING NYA KURANG
    if (!DaftarPengguna.pengguna[idx].jenis_akun){
        printf("\nWah, akun ");
        printWord(nama);
        printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
        printWord(nama);
        printf("!\n\n");
    } else {
        printf("\n");
        printProfil(DaftarPengguna.pengguna[idx]);
        printf("\nFoto profil akun ");
        printWord(DaftarPengguna.pengguna[idx].nama);
        printf(":\n");
        tampilkanFotoProfil(DaftarPengguna.pengguna[idx]);
    }
}

void ubahJenisAkun() {
    Word pilihan;

    printf("Saat ini, akun Anda adalah akun ");
    if (DaftarPengguna.pengguna[CurrentUser].jenis_akun){
        printf("Publik");
    } else {
        printf("Privat");
    }
    printf(".\n");

    printf("Ingin mengubah ke akun %s? (YA/TIDAK) ", (DaftarPengguna.pengguna[CurrentUser].jenis_akun) ? "Privat" : "Publik" );

    STARTINPUT();
    pilihan = currentSentence;

    if (isEqualWordStr(toLowerCase(pilihan), "ya")) {
        if (DaftarPengguna.pengguna[CurrentUser].jenis_akun) {
            DaftarPengguna.pengguna[CurrentUser].jenis_akun = private;
        } else {
            DaftarPengguna.pengguna[CurrentUser].jenis_akun = publik;
        }

        printf("Akun Anda sudah diubah menjadi akun ");
        if (DaftarPengguna.pengguna[CurrentUser].jenis_akun){
            printf("Publik");
        } else {
            printf("Privat");
        }
        printf(".\n");
    }
}

void ubahFotoProfil() {
    printf("\nFoto profil Anda saat ini adalah");
    tampilkanFotoProfil(DaftarPengguna.pengguna[CurrentUser]);
    printf("\nMasukkan foto Profil yang baru\n");
    STARTINPUT();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            DaftarPengguna.pengguna[CurrentUser].warna_profil.mem[i][j] = currentSentence.TabWord[i*20 + j*4]; // Mengganti .elmt dengan .Mem
            DaftarPengguna.pengguna[CurrentUser].foto_profil.mem[i][j] = currentSentence.TabWord[i*20 + j*4 + 2]; // Mengganti .elmt dengan .Mem
        }
    }
    printf("Foto Profil Anda sudah berhasil diganti!\n");
}

void tampilkanFotoProfil(Profil p) {
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            char color = p.warna_profil.mem[i][j];
            switch (color){
                case 'R':
                    print_red(p.foto_profil.mem[i][j]);
                    break;
                case 'G':
                    print_green(p.foto_profil.mem[i][j]);
                    break;
                case 'B':
                    print_blue(p.foto_profil.mem[i][j]);
                    break;
                default:
                    printf("%c", p.foto_profil.mem[i][j]);
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

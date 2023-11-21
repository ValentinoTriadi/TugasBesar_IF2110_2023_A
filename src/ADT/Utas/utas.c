#include <stdio.h>
#include <stdlib.h>
#include "thread.h"

//KAYAKNYA MASIH BANYAK SALAH2

int bandingKata()
{
    STARTINPUT();
    char x = "YA";
    char y = "Ya";
    char z = "ya";
    int j = 0; //COUNTER YANG MENINGKAT KALAU KARAKTER YANG DARI START INPUT = KARAKTER DI X, Y, ATAU Z
    for(int i = 0; i <= currentWord.Length; i++){ //LOOPING UNTUK MENGECEK YANG DIINPUT YA, Ya, ATAU ya
        if(currentWord.TabWord[i] != x[i] && currentWord.TabWord[i] != y[i] && currentWord.TabWord[i] != z[i]){
            j++;
        }
        else{
            j = 0;
        }
    }
    if(j == 2){ //KALAU SEMUA KARAKTER INPUT DAN KARAKTER X, Y, Z SAMA
        return 1;
    }
    else{
        return 0;
    }
}

void buatUtas(int idkicau) {
    boolean found = false;
    int id = 0;
    FILE *file = fopen("db.c", "r"); //PLACEHOLDER. NIATANKU BACA DATABASE BUAT NYARI ID KICAU
    while(fread(&kicau, sizeof(kicau), 1, file) == 1) {//PLACEHOLDER. CARI ID KICAU DAN FOUND = TRUE KALAU KETEMU
        if(kicau.id == idkicau) {
            found = true;
        }
    }
    while(fread(&Utas, sizeof(Utas), 1, file) == 1) { //PLACEHOLDER. CARI ID UTAS
        if(Utas.id != NULL) { //PLACEHOLDER. KALAU KETEMU ID UTAS APAPUN, COUNTER ID BERTAMBAH
            id++;
        }
    }
    if(kicau.user != currentUser){  //PLACEHOLDER. CEK APAKAH USER YANG MENULIS KICAU SAMA DENGAN USER SEKARANG
        printf("Utas ini bukan milik anda!");
    }
    else if(found == false){ //PLACEHOLDER. CEK APAKAH ID KICAU DITEMUKAN DI DATABASE ATAU TIDAK
        printf("Kicauan tidak ditemukan");
    }
    else{
        int idx = 0;
        int Utas.id = id + 1; //ID UTAS YANG DITULIS MENGIKUTI AUTO INCREMENT DARI UTAS LAIN YANG MUNGKIN ADA DI DATABASE
        do {
            printf("Masukkan kicauan:\n");
            STARTINPUT();
            Word Utas.isi;
            Utas.index = idx++;
            List Utas.utasan[idx] = Word Utas.isi;
            printf("Apakah anda ingin melanjutkan utas ini?\n");
            bandingKata();
        } while (bandingKata()); //LOOPING SELAMA KATA YANG DIINPUT YA, Ya, ATAU ya
    }
}

void sambungUtas(int idutas, int idx)
{
    boolean found = false;
    Address p = Utas.utasan; //PLACEHOLDER. INISIALISASI UNTUK NGECEK BERAPA BANYAK KICAUAN SAMBUNGAN PADA UTASAN
    int length = 0
    while(INFO(p) != NULL){ //PLACEHOLDER. NGECEK BERAPA BANYAK KICAUAN SAMBUNGAN PADA UTASAN
        p = NEXT(p);
        length++;
    }
    FILE *file = fopen("db.c", "r"); //PLACEHOLDER. BACA DATABASE BUAT NYARI DAFTAR ID UTAS YANG ADA
    while(fread(&Utas, sizeof(Utas), 1, file) == 1) {
        if(Utas.id == idutas) {
            found = true;
        }
    }
    if(idx > length + 1){ //PLACEHOLDER. CEK APAKAH INDEX BISA DISAMBUNGKAN PADA UTAS
        printf("Index terlalu tinggi!");
    }
    else if(found == false){
        printf("Utas tidak ditemukan!");
    }
    else if(Utas.nama != currentUser){ //PLACEHOLDER. CEK APAKAH ID UTAS DIMILIKI USER SEKARANG
        printf("Anda tidak bisa menyambung utas ini");
    }
    else{
        printf("Masukkan kicauan:\n");
        STARTWORD();
        Utas.isi = Utas.utasan[idx]; //PLACEHOLDER. MEMASUKKAN INPUTAN WORD KE DALAM LIST DAFTAR KICAUAN PADA SUATU UTASAN
        Utas.index = idx++;
    }
}

void hapusUtas(int Utas.id, int idx)
{
    int cnt = 0;
    Address loc = Utas.utasan;

    boolean found = false;
    Address p = Utas.id;
    FILE *file = fopen("db.c", "r");
    while (fread(&Utas, sizeof(Utas), 1, file) == 1) {
        if(Utas.id == idutas) {
            found = true;
        }
    }
    if(idx == 0){ //PLACEHOLDER. CEK APAKAH INDEX BISA DISAMBUNGKAN PADA UTAS
        printf("Anda tidak bisa menghapus kicauan utama!");
    }
    else if(found == false){
        printf("Utas tidak ditemukan!");
    }
    else if(Utas.pengguna != currentUser){ //PLACEHOLDER. CEK APAKAH ID UTAS DIMILIKI USER SEKARANG
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!");
    }
    else if(Utas.utasan[idx] == NULL){
        printf("Kicauan sambungan dengan index 3 tidak ditemukan pada utas!");
    }
    else{
        //PLACEHOLDER. RENCANANYA PAKAI ALGORITMA DELETE AT DI LISTLINIER
        while(cnt < idx-1){
            cnt++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

void cetakUtas(int Utas.id)
{
    int idx = 0
    Address p = Utas.utasan;
    printf("| ID = %d\n", Utas.id);
    printf("| %s\n", Utas.nama);
    printf("| %s\n", Utas.tanggal);
//AKU BINGUNG INI PRINT TANGGAL GIMANA JADI INI PLACEHOLDER
    printf("| %s\n", Utas.utasan[idx]);
    while(INFO(p) != NULL){
        idx++;
        printf("    | INDEX = %d\n", Utas.index);
        printf("    | %s\n", Utas.nama);
        printf("    | %s\n", Utas.tanggal);
    //AKU BINGUNG INI PRINT TANGGAL GIMANA JADI INI PLACEHOLDER
        printf("    | %s\n", Utas.utasan[idx]);
    }
}

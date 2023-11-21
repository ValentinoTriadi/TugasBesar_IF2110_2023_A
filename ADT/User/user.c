#include "user.h"

// Word* current;

void signUp() {
    Listuser l;
    int i, idx;
    boolean found;
    // CreateListStatik(&l);


    Word * current;
    Word namaIn, sandiIn;
    printf("Masukkan nama:\n");
    STARTWORD();
    ADVWORD();
    CCopyWord(current, namaIn);

    printf("Masukkan kata sandi:\n");
    STARTWORD();
    ADVWORD();
    CCopyWord(current, sandiIn);


    
    i = 0 ;
    found = false;
    while (i<CAPACITY && !found){
        if (isEqualWordWord(namaIn, l.Users[i].nama)){
            found = true;
        } else {
            i++;
        }
    }
    if (found == true){
        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
        signIn();
    }
}

void signIn() {
    Listuser l;
    int i, idx;
    boolean found ;
    
    Word * current;
    Word namaIn, sandiIn;
    printf("Masukkan nama:\n");
    STARTWORD();
    ADVWORD();
    CCopyWord(current, namaIn);

    printf("Masukkan kata sandi:\n");
    STARTWORD();
    ADVWORD();
    CCopyWord(current, sandiIn);

    i = 0 ;
    found = false;
    while (i<CAPACITY && !found){
        if (!isEqualWordWord(namaIn, l.Users[i].nama)){
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
            i++;
        } 
        else if (!isEqualWordWord(sandiIn, l.Users[i].sandi)) {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            i++;
        }
        else if (isEqualWordWord(namaIn, l.Users[i].nama) && isEqualWordWord(sandiIn, l.Users[i].sandi)){
            found = true;
            
        }
    }

    if( found == true) {
        printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", l.Users[i].nama);
        insertLastLISTSTATIK(&l, l.Users[i]);

    }
}

void signOut() {
    ListStatik l;
    Word nama, sandi;
    int i = 0;
    boolean found = false;
    while (i<CAPACITY && !found){
        if (isEqualWordWord(nama, l.Users[i].nama)){
            found = true;
        } else {
            i++;
        }
    }
    if (/* condition */found == true)
    {
        /* code */printf("Anda sudah keluar. Terima kasih untuk menggunakan layanan BurBir!\n");
    }
    
    // if (currentUser.nama[0] == '\0') {
    //     printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    // } else {
    //     currentUser.nama[0] = '\0';
    //     currentUser.sandi[0] = '\0';
    //     
    // }
}

void exitProgram() {
        printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    exit(0);
}

int main(){
    printf("hello");
    return 0;
}




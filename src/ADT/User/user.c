#include "user.h"

extern Profil currentUser;
extern userlist daftarUser;


void signUp(){
    Word username, password;
    printf("Masukkan nama:\n");
    STARTWORD();
    currentUser.nama = currentWord;
    printf("Masukkan kata sandi:\n");
    STARTWORD();
    currentUser.sandi = currentWord;

    
    printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    printf("Wah, sayang sekali nama tersebut telah diambil.\n");
    printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    
}

void signIn() {
    printf("Masukkan nama:\n");
    STARTWORD();
    Word inputNama = currentWord;
    printf("Masukkan kata sandi:\n");
    STARTWORD();
    Word inputSandi = currentWord;

    boolean userFound = false;
    boolean sandiTrue = false;
    int userCount;

    FILE *file = fopen("../../Konfigurasi_Program/pengguna.config", "r");
    if (file) {
        fscanf(file, "%d", &userCount); 
        for (int i = 0; i < userCount; i++) {
            Word username, password;
            // Membaca informasi pengguna dari konfigurasi
            STARTWORD();
            username = currentWord;
            STARTWORD();
            password = currentWord;

            if (isEqualWord(username, inputNama)) {
                userFound = true;
                if (isEqualWord(password, inputSandi)) {
                    sandiTrue = true;
                    break;
                }
            }
            // Melompati bagian bio, nomor HP, dan lainnya untuk pengguna berikutnya
            for (int j = 0; j < 7; j++) {
                STARTWORD();
            }
        }
        fclose(file);
    } 

    if (!userFound) {
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
    } else if (!sandiTrue) {
        printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
    } else {
        printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", inputNama.TabWord);
    }
    printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
}

void signOut(){
    boolean isLogin = (currentUser.nama.Length != 0);
    if(!isLogin){
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    } else {
        currentUser.nama.Length = 0;
        currentUser.sandi.Length = 0;
        printf("Anda sudah keluar. Terima kasih untuk menggunakan layanan BurBir!\n");
    }
}

void exitProgram(){
    printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.");
    exit(0);
}

int main(){
       printf("Hello World!\n");
       return 0;
}
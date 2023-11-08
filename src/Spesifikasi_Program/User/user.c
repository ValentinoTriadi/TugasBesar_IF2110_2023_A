#include "user.h"

void signUp() {
    printf("Masukkan nama:\n");
    STARTWORD();
    CopyWord(currentUser.pengguna->nama, currentWord);
    // CopyWord(currentUser.pengguna->sandi, currentWord);
    currentUser.pengguna->nama[strcspn(currentUser.pengguna->nama, "\n")] = 0; // Menghapus karakter newline
    printf("Masukkan kata sandi:\n");
    fgets(currentUser.sandi, MAX_PASSWORD_LENGTH, stdin);
    currentUser.sandi[strcspn(currentUser.sandi, "\n")] = 0; // Menghapus karakter newline
    printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
}

void signIn() {
    printf("Masukkan nama:\n");
    char tempNama[MAX_USERNAME_LENGTH];
    fgets(tempNama, MAX_USERNAME_LENGTH, stdin);
    tempNama[strcspn(tempNama, "\n")] = 0; // Menghapus karakter newline

    printf("Masukkan kata sandi:\n");
    char tempSandi[MAX_PASSWORD_LENGTH];
    fgets(tempSandi, MAX_PASSWORD_LENGTH, stdin);
    tempSandi[strcspn(tempSandi, "\n")] = 0; // Menghapus karakter newline

    if (strcmp(currentUser.nama, tempNama) == 0 && strcmp(currentUser.sandi, tempSandi) == 0) {
        printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", currentUser.nama);
    } else if (strcmp(currentUser.nama, tempNama) != 0) {
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
    } else {
        printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
    }
}

void signOut() {
    if (currentUser.nama[0] == '\0') {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    } else {
        currentUser.nama[0] = '\0';
        currentUser.sandi[0] = '\0';
        printf("Anda sudah keluar. Terima kasih untuk menggunakan layanan BurBir!\n");
    }
}

void exitProgram() {
    printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    exit(0);
}

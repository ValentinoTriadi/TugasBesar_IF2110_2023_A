#include "user.h"
#include "../Database/db.h"
#include <stdlib.h>
#include <stdio.h>

extern Teman DataTeman;

boolean isExists(Word name){
    for (int i = 0; i < DaftarPengguna.total; i++){
        if (isEqualWordWord(DaftarPengguna.pengguna[i].nama, name)) return true;
    }
    return false;
}

boolean checkPassword (Word nama, Word pass){
    for (int i = 0; i < DaftarPengguna.total; i++){
        if (isEqualWordWord(DaftarPengguna.pengguna[i].nama, nama)) {
            return (isEqualWordWord(DaftarPengguna.pengguna[i].sandi, pass));
        }
    }
    return false;
}

int findIndexUser(Word nama){
    for (int i = 0; i < DaftarPengguna.total; i++){
        if (isEqualWordWord(DaftarPengguna.pengguna[i].nama, nama)) {
            return i;
        }
    }
    return -1;
}

void daftar(){
    if (CurrentUser != -1){
        printf("\nWah Anda sudah masuk. Keluar dulu yuk!\n\n");
        return;
    }
    if (DaftarPengguna.total == 20){
        printf("\nWah Pengguna Sudah Penuh. Anda tidak dapat mendaftar lagi! :(\n\n");
        return;
    }
    Word username, password;
    boolean exists = true;
    while (exists){
        printf("\nMasukkan nama:\n");
        STARTINPUT();
        username = currentSentence;
        exists = false;
        if (isExists(username)){
            exists = true;
            printf("\nWah, sayang sekali nama tersebut telah diambil.\n");
        }
    }

    printf("\nMasukkan kata sandi:\n");
    STARTINPUT();
    password = currentSentence;

    if (username.Length > MAX_LENGTH) username.Length = MAX_LENGTH;
    if (password.Length > MAX_LENGTH) password.Length = MAX_LENGTH;
    Profil newUser;
    newUser.nama = username;
    newUser.sandi = password;
    initProfil(&newUser);

    DaftarPengguna.pengguna[DaftarPengguna.total] = newUser;
    DaftarPengguna.total++;
    addVertex(&DataTeman.dataTeman, username);
    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    delay(2);
}

void masuk() {
    if (CurrentUser != -1){
        printf("\nWah Anda sudah masuk. Keluar dulu yuk!\n\n");
        return;
    }
    boolean exists = false;
    Word inputNama, inputSandi;
    while (!exists){
        printf("\nMasukkan nama:\n");
        STARTINPUT();
        inputNama = currentSentence;
        exists = isExists(inputNama);
        if (!exists){
            printf("\nWah, nama yang Anda cari tidak ada.\nMasukkan nama lain!\n");
        }
    }

    boolean isValid = false;
    while (!isValid){
        printf("Masukkan kata sandi:\n");
        STARTINPUT();
        inputSandi = currentSentence;
        isValid = checkPassword(inputNama, inputSandi);
        if (!isValid) printf("\nWah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
    }

    CurrentUser = findIndexUser(inputNama);
    printf("\nAnda telah berhasil masuk dengan nama pengguna ");
    printWord(inputNama);
    printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
    delay(2);
}

void keluar(){
    if(CurrentUser == -1){
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
    } else {
        CurrentUser = -1;
        printf("\nAnda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n\n");
    }
    delay(2);
}

void tutupProgram(){
    printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    exit(0);
}

void printUser(){
    for (int i = 0; i < DaftarPengguna.total; i++){
        printf("User %d:\n", i+1);
        printWord(DaftarPengguna.pengguna[i].nama);
        printf("\n");
        printWord(DaftarPengguna.pengguna[i].sandi);
        printf("\n");
    }
    delay(2);
}
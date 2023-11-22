#include "user.h"
#include <stdlib.h>
#include <stdio.h>

extern Profil CurrentUser;
extern userlist DaftarPengguna;
extern Word currentSentence;

boolean isExists(Word name){\
    boolean found = false;
    int i = 0;
    while(!found && i < DaftarPengguna.total){
        if (isEqualWordWord(DaftarPengguna.pengguna[i].nama, name)) found = true;
        i++;
    }
    return found;
}

boolean checkPassword (Word nama, Word pass){
    boolean found = false;
    int i = 0;
    while(!found && i < DaftarPengguna.total){
        if (isEqualWordWord(DaftarPengguna.pengguna[i].nama, nama)){
            found = true;
        } 
        i++;
    }
    if(found==true){
        return isEqualWordWord(DaftarPengguna.pengguna[i-1].sandi, pass);
    }

    return found;
}

int findIndexUser(Word nama){
    boolean found = false;
    int i = 0;
    while(!found && i < DaftarPengguna.total){
        if (isEqualWordWord(DaftarPengguna.pengguna[i].nama, nama)){
            found = true;
            
        } 
        i++;
    }
    if (found==true){
        return i;
    } else {
        return 9999;
    }
    
}

void daftar(){
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

    if (username.Length > 20) username.Length = 20;
    if (password.Length > 20) password.Length = 20;
    Profil newUser;
    newUser.nama = username;
    newUser.sandi = password;

    DaftarPengguna.pengguna[DaftarPengguna.total] = newUser;
    DaftarPengguna.total++;
    
    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    delay(10);
}

void masuk() {
    if (CurrentUser.nama.Length != 0){
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

    CurrentUser = DaftarPengguna.pengguna[findIndexUser(inputNama)];
    printf("Anda telah berhasil masuk dengan nama pengguna ");
    printWord(inputNama);
    printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
    delay(10);
}

void keluar(){
    if(!CurrentUser.nama.Length != 0){
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
    } else {
        CurrentUser.nama.Length = 0;
        printf("\nAnda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n\n");
        Profil newProfil;
        initProfil(&newProfil);
        newProfil.nama.Length = 0;
        newProfil.sandi.Length = 0;
        CurrentUser = newProfil;
    }
    delay(10);
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
    delay(10);
}
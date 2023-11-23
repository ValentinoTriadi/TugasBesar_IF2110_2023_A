#include <stdio.h>
#include <sys/stat.h>
#include "muat.h"
#include "../Database/db.h"


void loadPengguna(){
    READFILE("pengguna.config");
    int n = wordToInt(currentSentence);
    for (int i = 0; i<n; i++){
        ADVSENTENCE();
        NAMA(DaftarPengguna.pengguna[i]) = currentSentence;
        ADVSENTENCE();
        SANDI(DaftarPengguna.pengguna[i]) = currentSentence;
        ADVSENTENCE();
        BIO(DaftarPengguna.pengguna[i]) = currentSentence;
        ADVSENTENCE();
        HP(DaftarPengguna.pengguna[i]) = currentSentence;
        ADVSENTENCE();
        WETON(DaftarPengguna.pengguna[i]) = currentSentence;
        ADVSENTENCE();

        if (isEqualWordStr(currentSentence, "Publik")){
            JENISAKUN(DaftarPengguna.pengguna[i]) = publik;
        } else {
            JENISAKUN(DaftarPengguna.pengguna[i]) = private;
        }
        for (int j = 0; j<5;j++){
            ADVSENTENCE();
            for (int k = 0; k<5; k++){
                DaftarPengguna.pengguna[i].warna_profil.mem[j][k] = currentSentence.TabWord[(k*4)];
                DaftarPengguna.pengguna[i].foto_profil.mem[j][k] = currentSentence.TabWord[(k*4)+2];
            }
        }
    }
    for(int i=0; i<n; i++){
        ADVSENTENCE();
        for (int j = 0; j < n; j++){
            DataTeman.dataTeman.adjacencyMatrix[i][j] = charToInt(currentSentence.TabWord[(2*j)]);
        }
    }
    ADVSENTENCE();
    n = wordToInt(currentSentence);
    for(int i=0; i<n; i++){
        
    }
}

void muat(){
    if (CurrentUser != 0){
        printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
    } else {
        printf("Masukkan nama folder yang hendak dimuat: ");
        STARTINPUT();
        Word NamaFile = currentSentence;
        load (NamaFile);
    }
}

void load(Word NamaFile){
    boolean isExists;
    struct stat st = {0};
    char FullPath[100]= "./Config/";
    int len = Strlen(FullPath);
    for (int i = 0; i <NamaFile.Length; i++){
        FullPath[len+i] = NamaFile.TabWord[i];

    }


    if (stat(FullPath, &st) == -1) {
        isExists = false;
        printf("Tidak ada folder yang dimaksud!\n");
    } else {
        isExists = true;
        
        printf("Anda akan melakukan pemuatan dari ");
        printWord(NamaFile);
        printf(".\n\nMohon tunggu...\n");
        delay(2);
        printf("1...\n");
        delay(2);
        printf("2...\n");
        delay(2);
        printf("3...\n");
        delay(2);
        printf("Pemuatan selesai!\n");
        loadPengguna();   
    }
}
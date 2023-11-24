/* File: tweet.c */
#include "tweet.h"
#include <stdio.h>
#include "../Database/db.h"


void CreateListKicau(int cap){
    DaftarKicau.nEff = 0;
    DaftarKicau.capacity = cap;
    DaftarKicau.kicau = (Kicauan*) malloc (cap*sizeof(Kicauan));
}

int GenerateID() {
    if (DaftarKicau.nEff == 0) {
        return 1;
    } else {
        return DaftarKicau.kicau[DaftarKicau.nEff - 1].id + 1;
    }
}

void AddTweetToList(Kicauan k) {
    if (DaftarKicau.nEff < DaftarKicau.capacity) {
        DaftarKicau.kicau[DaftarKicau.nEff] = k;
        DaftarKicau.nEff++;
    } else {
        ListKicau new, temp;
        new.kicau = (Kicauan*) malloc (DaftarKicau.capacity*2*sizeof(Kicauan));
        new.capacity = DaftarKicau.capacity*2;
        new.nEff = DaftarKicau.nEff + 1;
        IdxType i;
        for (i=0; i<DaftarKicau.nEff; i++) {
            new.kicau[i] = DaftarKicau.kicau[i];
        }
        new.kicau[i] = k;
        temp = DaftarKicau;
        DaftarKicau = new;
        free(temp.kicau);
    }
}

boolean cekInputValid(){
    Word temp = currentSentence;
    for (int i = 0; i < temp.Length; i++){
        if (temp.TabWord[i] != ' ') return true;
    }
    return false;
}

void CreateTweet() {
    Kicauan k;
    printf("\nMasukkan kicauan:\n");
    STARTINPUT();
    printf("%d\n",DaftarKicau.nEff);
    if (cekInputValid()){
        k.id = GenerateID(); 
        Word temp = currentSentence;
        temp.Length = (temp.Length > 280)? 280 : temp.Length;
        k.text = temp;
        k.like = 0;
        k.author = CurrentUser;
        k.datetime = getLocalTime();
        printf("\nSelamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
        PrintTweet(k);
        AddTweetToList(k);
    } else {
        printf("\nKicauan tidak boleh hanya berisi spasi!\n");
    }
}


void PrintTweet(Kicauan k) {
    printf("| ID = %d\n", k.id);
    printf("| ");
    printWord(DaftarPengguna.pengguna[k.author].nama);
    printf("\n| ");
    TulisDATETIME(k.datetime);
    printf("\n| ");
    printWord(k.text);
    printf("\n| Disukai: %d\n\n", k.like);
}


void ShowTweets() {
    printf("\n");
    for (int i = DaftarKicau.nEff - 1; i >= 0; i--) {
        if (DaftarKicau.kicau[i].author == CurrentUser || isFollowing(CurrentUser, DaftarKicau.kicau[i].author)) {
            PrintTweet(DaftarKicau.kicau[i]);
        }
    }
}

int findIdxbyID(int ID){
    boolean found = false;
    int i = 0;
    while(i < DaftarKicau.nEff && !found){
        if (DaftarKicau.kicau[i].id == ID){
            found = true;
        }
        i++;
    }
    if (found) return i-1;
    return -1;
}

void LikeTweet(int id) {
    for (int i = 0; i < DaftarKicau.nEff; i++) {
        if (DaftarKicau.kicau[i].id == id) {
            if (!DaftarPengguna.pengguna[DaftarKicau.kicau[i].author].jenis_akun && !isFollowing(CurrentUser, DaftarKicau.kicau[i].author)){
                printf("\nWah, akun ");
                printWord(DaftarPengguna.pengguna[DaftarKicau.kicau[i].author].nama);
                printf(" diprivat nih. Ikuti dulu yuk untuk bisa menyukai kicauan ");
                printWord(DaftarPengguna.pengguna[DaftarKicau.kicau[i].author].nama);
                printf("!\n\n");
            } else {
                DaftarKicau.kicau[i].like++;
                printf("\nSelamat! kicauan telah disukai!\nDetil kicauan:\n");
                PrintTweet(DaftarKicau.kicau[i]);
            }
            return;
        }
    }
    printf("\nTidak ditemukan kicauan dengan ID = %d;\n", id);
}


void UpdateTweet(int id) {
    int i;  
    for (i = 0; i < DaftarKicau.nEff; i++) {
        if (DaftarKicau.kicau[i].id == id){
            if (DaftarKicau.kicau[i].author == CurrentUser) {
                printf("\nMasukkan kicauan baru:\n");
                STARTINPUT();
                Word newText = currentSentence;
                newText.Length = (newText.Length > 280)? 280 : newText.Length;
                DaftarKicau.kicau[i].text = newText;
                PrintTweet(DaftarKicau.kicau[i]);
                return;
            }
            printf("Kicauan dengan ID = %d bukan milikmu!\n",id);
            return;
        }
    }
    printf("Kicauan dengan ID = %d tidak ditemukan!\n", id);
}

int findIdxbyID(int ID){
    boolean found = false;
    int i = 0;
    while(i < DaftarKicau.nEff && !found){
        if (DaftarKicau.kicau[i].id == ID){
            found = true;
        }
        i++; 
    }
    if (found) return i-1;
    return -1;
}
/* File: tweet.c */
#include "tweet.h"
#include "../Database/db.h"
#include <stdio.h>
#include <string.h>

extern Profil CurrentUser;
extern Word currentSentence;
extern ListKicau DaftarKicau;

int GenerateID(ListKicau *lk) {
    if (lk->nEff == 0) {
        return 1;
    } else {
        return lk->kicau[lk->nEff - 1].id + 1;
    }
}

void CreateTweet(Kicauan *k) {
    k->id = GenerateID(&DaftarKicau); 
    k->text = currentSentence;
    k->like = 0;
    k->author = CurrentUser;
    k->datetime = getLocalTime();
    PrintTweet(*k);
}


void PrintTweet(Kicauan k) {
    printf("| ID = %d\n", k.id);
    printf("| ");
    printWord(k.author.nama);
    printf("\n| ");
    TulisDATETIME(k.datetime);
    printf("\n| ");
    printWord(k.text);
    printf("\n| Disukai: %d\n\n", k.like);
}


void ShowTweets(ListKicau lk) {
    for (int i = lk.nEff - 1; i >= 0; i--) {
        if (isEqualWordWord(lk.kicau[i].author.nama, CurrentUser.nama)) {
            PrintTweet(lk.kicau[i]);
        }
    }
}


void LikeTweet(ListKicau *lk, int id) {
    for (int i = 0; i < lk->nEff; i++) {
        if (lk->kicau[i].id == id) {
            lk->kicau[i].like++;
            PrintTweet(lk->kicau[i]);
            return;
        }
    }
    printf("Tidak ditemukan kicauan dengan ID = %d;\n", id);
}


void UpdateTweet(ListKicau *lk, int id, Word newText) {
    for (int i = 0; i < lk->nEff; i++) {
        if (lk->kicau[i].id == id && isEqualWordWord(lk->kicau[i].author.nama, CurrentUser.nama)) {
            lk->kicau[i].text = newText;
            PrintTweet(lk->kicau[i]);
            return;
        }
    }
    printf("Kicauan dengan ID = %d bukan milikmu atau tidak ditemukan!\n", id);
}
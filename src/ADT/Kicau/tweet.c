/* File: tweet.c */
#include "tweet.h"
#include "../Database/db.h"
#include <stdio.h>
#include <string.h>

extern Profil currentUser;
extern Word currentSentence;

int GenerateID(ListKicau *lk) {
    if (lk->nEff == 0) {
        return 1;
    } else {
        return lk->kicau[lk->nEff - 1].id + 1;
    }
}

void AddTweetToList(ListKicau *lk, Kicauan k) {
    if (lk->nEff < MAX_TWEETS) {
        lk->kicau[lk->nEff] = k;
        lk->nEff++;
    } else {
        printf("List kicauan penuh, tidak dapat menambahkan kicauan baru.\n");
    }
}

void CreateTweet(ListKicau *lk, Kicauan *k) {
    k->id = GenerateID(lk); 
    k->text = currentSentence;
    k->like = 0;
    k->author = currentUser;
    k->datetime = getLocalTime();
    PrintTweet(*k);
    AddTweetToList(lk, *k);
}

void PrintTweet(Kicauan k) {
    printf("| ID = %d\n", k.id);
    printf("| ");
    printWord(k.author);
    printf("\n| ");
    TulisDATETIME(k.datetime);
    printf("\n| ");
    printWord(k.text);
    printf("\n| Disukai: %d\n\n", k.like);
}


void ShowTweets(ListKicau lk) {
    for (int i = lk.nEff - 1; i >= 0; i--) {
        if (isEqualWordWord(lk.kicau[i].author.nama, currentUser.nama)) {
            PrintTweet(lk.kicau[i]);
        }
    }
}


void LikeTweet(ListKicau *lk, int id) {
    for (int i = 0; i < lk->nEff; i++) {
        if (lk->kicau[i].id == id) {
            if (lk->kicau[i].author.isPublic) {
                lk->kicau[i].like++;
                printf("Selamat! kicauan telah disukai!\n");
                PrintTweet(lk->kicau[i]);
            } else {
                printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
            }
            return;
        }
    }
    printf("Tidak ditemukan kicauan dengan ID = %d;\n", id);
}



void UpdateTweet(ListKicau *lk, int id, Word newText) {
    for (int i = 0; i < lk->nEff; i++) {
        if (lk->kicau[i].id == id && isEqualWordWord(lk->kicau[i].author.nama, currentUser.nama)) {
            lk->kicau[i].text = newText;
            PrintTweet(lk->kicau[i]);
            return;
        }
    }
    printf("Kicauan dengan ID = %d bukan milikmu atau tidak ditemukan!\n", id);
}
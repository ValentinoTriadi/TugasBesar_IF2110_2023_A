/* File: tweet.h */
#ifndef TWEET_H
#define TWEET_H

#include "../boolean.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../Time/datetime.h"


#define MAX_TWEETS 1000

typedef struct {
    int id;
    Word text;
    int like;
    Profil author;
    DATETIME datetime;
} Kicauan;

typedef struct {
    Kicauan* kicau;
    int nEff;
    int capacity;
} ListKicau;

int GenerateID(ListKicau *lk);
void CreateTweet(ListKicau *lk, Kicauan *k);
void ShowTweets(ListKicau lk);
void LikeTweet(ListKicau *lk, int id);
void UpdateTweet(ListKicau *lk, int id, Word newText);
void PrintTweet(Kicauan k);
void AddTweetToList(ListKicau *lk, Kicauan k);


#endif

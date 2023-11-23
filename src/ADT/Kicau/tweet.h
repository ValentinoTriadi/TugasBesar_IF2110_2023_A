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
    int author; //id profil
    DATETIME datetime;
} Kicauan;

typedef struct {
    Kicauan* kicau;
    int nEff;
    int capacity;
} ListKicau;

void CreateListKicau(int cap);
int GenerateID();
boolean cekInputValid();
void CreateTweet();
void ShowTweets();
void LikeTweet(int id);
void UpdateTweet(int id);
void PrintTweet(Kicauan k);
void AddTweetToList(Kicauan k);


#endif

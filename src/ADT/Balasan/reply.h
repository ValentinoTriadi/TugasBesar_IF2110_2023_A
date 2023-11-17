#ifndef REPLY_H_
#define REPLY_H_

#include "../boolean.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../Time/datetime.h"
#include "../Profil/profil.h"
#include "tree.h"

typedef struct {
    int id;                
    Word text;           
    Profil author;        
    DATETIME datetime;  
    Tree replies;       
} Balasan;

void CreateReply(Balasan *reply, Profil author);
void AddReplyToTweet(Tree *tweetReplies, Balasan *reply, int tweetId);
void AddReplyToReply(Tree *tweetReplies, Balasan *reply, int parentId);
void ShowReplies(Tree tweetReplies, int tweetId);
void DeleteReply(Tree *tweetReplies, int replyId);
void PrintReply(Balasan reply);
void CascadeDelete(Tree *tweetReplies, int parentId);

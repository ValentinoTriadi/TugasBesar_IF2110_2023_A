#ifndef REPLY_H
#define REPLY_H

#include "../boolean.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../Time/datetime.h"
#include "../Tree/tree.h"

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

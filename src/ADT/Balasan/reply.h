#ifndef REPLY_H_
#define REPLY_H_

#include <stdio.h>
#include "../boolean.h"
#include "../Mesin-Kata/wordmachine.h"
#include "tree.h"
#include "../Time/datetime.h"
#include "../Profil/profil.h"

typedef struct {
    int id;                
    Word text;           
    int author;        
    DATETIME datetime;  
    Tree replies;       
} Balasan;

void CreateReply(Balasan *reply);
void PrintReply(Balasan reply);
void Replies(int IDKicau, int IDBalasan);
void AddReplyToTweet(Tree *tweetReplies, Balasan *reply, int IDKicau);
void AddReplyToReply(Tree *tweetReplies, Balasan *reply, int IDParent);
void ShowReplies(Tree tweetReplies, int IDKicau);
void DeleteReply(Tree *tweetReplies, int IDBalasan);
void CascadeDelete(Tree *tweetReplies, int IDParent);
boolean tweetExists(int IDKicau);
boolean replyExist(addressTree root, int IDBalasan);
boolean canReplyToTweet(int IDKicau);
boolean canReplyToReply(Tree tweetReplies, int IDKicau, int IDBalasan);

#endif
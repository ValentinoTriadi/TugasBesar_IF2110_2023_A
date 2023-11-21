#include "reply.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern Profil currentUser;
extern Word currentSentence;

void CreateReply(Balasan *reply, Profil author) {
    static int nextID = 0; 
    reply->id = ++nextID;
    reply->text = currentSentence;
    reply->author = author;
    reply->datetime = getLocalTime();
    CreateTree(&(reply->replies));
}

void AddReplyToTweet(Tree *tweetReplies, Balasan *reply, int tweetId) {
    addressTree tweetNode = getAddress(Root(*tweetReplies), tweetId);
    if (tweetNode) {
        addressTree newReplyNode = Alokasi(reply->id);
        newReplyNode->data = (int)reply;
        AddChild(&tweetNode, newReplyNode);
    } else {
        printf("Tweet with ID %d not found.\n", tweetId);
    }
}

void AddReplyToReply(Tree *tweetReplies, Balasan *reply, int parentId) {
    addressTree parentNode = getAddress(Root(*tweetReplies), parentId);
    if (parentNode) {
        addressTree newReplyNode = Alokasi(reply->id);
        newReplyNode->data = (int)reply;
        AddChild(&parentNode, newReplyNode);
    } else {
        printf("Reply with ID %d not found.\n", parentId);
    }
}

void ShowReplies(Tree tweetReplies, int tweetId) {
    addressTree tweetNode = getAddress(Root(tweetReplies), tweetId);
    if (tweetNode) {
        printTree(tweetNode, 0);
    } else {
        printf("Tweet with ID %d has no replies.\n", tweetId);
    }
}

void DeleteReply(Tree *tweetReplies, int replyId) {
    addressTree replyNode = getAddress(Root(*tweetReplies), replyId);
    if (replyNode) {
        CascadeDelete(tweetReplies, replyId);
    } else {
        printf("Reply with ID %d not found.\n", replyId);
    }
}

void PrintReply(Balasan reply) {
    printf("| ID = %d\n", reply.id);
    printf("| ");
    printWord(reply.author);
    printf("\n| ");
    TulisDATETIME(reply.datetime);
    printf("\n| ");
    printWord(reply.text);
    printf("\n");
}

void CascadeDelete(Tree *tweetReplies, int parentId) {
    addressTree parentNode = getAddress(Root(*tweetReplies), parentId);
    if (parentNode) {
        addressTree child = FirstChild(parentNode);
        while (child) {
            CascadeDelete(tweetReplies, Data(child));
            addressTree temp = child;
            child = NextSibling(child);
            Dealokasi(temp);
        }
        addressTree parent = getParent(Root(*tweetReplies), parentNode);
        if (parent) {
            if (FirstChild(parent) == parentNode) {
                FirstChild(parent) = NextSibling(parentNode);
            } else {
                addressTree sibling = FirstChild(parent);
                while (NextSibling(sibling) != parentNode) {
                    sibling = NextSibling(sibling);
                }
                NextSibling(sibling) = NextSibling(parentNode);
            }
        } else {
            *tweetReplies = (Tree){NULL};
        }
        Dealokasi(parentNode);
    }
}

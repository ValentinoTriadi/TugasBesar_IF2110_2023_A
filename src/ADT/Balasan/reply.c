#include "reply.h"
#include <stdio.h>
#include "../boolean.h"
#include <stdlib.h>
#include "../Database/db.h"

extern Tree tweetReplies;

static int nextID = 0;
void CreateReply(Balasan *reply) {
    reply->id = ++nextID;
    reply->text = currentSentence;
    reply->author = (CurrentUser);
    reply->datetime = getLocalTime();
    CreateTree(&(reply->replies));
}

void PrintReply(Balasan reply) {
    printf("| ID = %d\n", reply.id);
    printf("| ");
    printWord(DaftarPengguna.pengguna[reply.author].nama);
    printf("\n| ");
    TulisDATETIME(reply.datetime);
    printf("\n| ");
    printWord(reply.text);
    printf("\n");
}

boolean tweetExists(int IDKicau){
    if (findIdxbyID(IDKicau) != -1) return true;
    return false;
}

boolean replyExist(addressTree root, int IDBalasan) {
    if (root == NULL) {
        return false;
    }
    if (Data(root) == IDBalasan) {
        return true;
    }
    return replyExist(FirstChild(root), IDBalasan) || replyExist(NextSibling(root), IDBalasan);
}


boolean canReplyToTweet(int IDKicau) {
    if (DaftarPengguna.pengguna[DaftarKicau.kicau[findIdxbyID(IDKicau)].author].jenis_akun) {
        return true;
    } else
    return false;
}


boolean canReplyToReply(Tree tweetReplies, int IDKicau, int IDBalasan) {
    addressTree replyNode = getAddress(Root(tweetReplies), IDBalasan);

    if (replyNode == NULL) {
        return false;
    } else {
        int authorID = CurrentUser;

        if (!DaftarPengguna.pengguna[authorID].jenis_akun) {
            return isFollowing(CurrentUser, authorID);
        } else {
            return true;
        }
    }
}


void Replies(int IDKicau, int IDBalasan) {
    if (!tweetExists(IDKicau)) { 
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }
    if (IDBalasan != -1 && !replyExist(tweetReplies.root, IDBalasan)) { 
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
        return;
    }
    if (IDBalasan != -1 && !canReplyToTweet(IDKicau)) { 
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
        return;
    }
    printf("\nMasukkan balasan:\n");
    STARTINPUT(); 
    Balasan newReply;
    CreateReply(&newReply); 
    if (IDBalasan == -1) {
        AddReplyToTweet(&tweetReplies, &newReply, IDKicau); 
    } else {
        AddReplyToReply(&tweetReplies, &newReply, IDBalasan);
    }
    printf("\nSelamat! balasan telah diterbitkan!\nDetil balasan:\n");
    PrintReply(newReply);
}



void AddReplyToTweet(Tree *tweetReplies, Balasan *reply, int IDKicau) {
    addressTree tweetNode = getAddress(Root(*tweetReplies), IDKicau);
    if (tweetNode) {
        addressTree newReplyNode = Alokasi(reply->id);
        newReplyNode->data = reply->id;
        AddChild(&tweetNode, newReplyNode);
    } else {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!");
    }
}


void AddReplyToReply(Tree *tweetReplies, Balasan *reply, int IDParent) {
    addressTree parentNode = getAddress(Root(*tweetReplies), IDParent);
    if (parentNode) {
        addressTree newReplyNode = Alokasi(reply->id);
        newReplyNode->data = reply->id;
        AddChild(&parentNode, newReplyNode);
    } else {
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!");
    }
}


void ShowReplies(Tree tweetReplies, int IDKicau) {
    addressTree tweetNode = getAddress(Root(tweetReplies), IDKicau);
    if (tweetNode) {
        printTree(tweetNode, 0);
    } else {
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!");
    }
}


void DeleteReply(Tree *tweetReplies,int IDBalasan) {
    addressTree replyNode = getAddress(Root(*tweetReplies), IDBalasan);
    if (replyNode) {
        CascadeDelete(tweetReplies, IDBalasan);
    } else {
        printf("Balasan tidak ditemukan");
    }
}


void CascadeDelete(Tree *tweetReplies, int IDParent) {
    addressTree parentNode = getAddress(Root(*tweetReplies), IDParent);
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
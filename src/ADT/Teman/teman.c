#include "teman.h"
#include "../Database/db.h"
#include <stdio.h>
#include <stdlib.h>

extern Word currentWord;
extern Teman DataTeman;

void createTeman(Teman *teman)
{
    MakeEmptyPrio(&teman->dataTeman.vertex->friendReq, 20);
    CreateGraph(&(teman->dataTeman));
    createMatrix(20, 3, &(teman->saveReq));
}

void daftarTeman(Teman teman,Word currentUser)
{
    int index = -1;
    int i, j;

    // check index dari currentuser
    for (i = 0; i < NeffGraf(Graph(teman)); i++)
    {
        if (isEqualWordWord(Vertex(Graph(teman), i).nama, currentUser))
        {
            index = i;
            break;
        }
    }
    printf("index : %d\n", index);
    if (index != -1)
    {
        // hitung berapa teman
        int count = countEdges(&Graph(teman), currentUser);

        printf("%s ", currentUser.TabWord);
        if (count > 0)
        {
            printf("memiliki %d teman\n", count);
            printf("Daftar teman ");
            printWord(currentUser);
            printf("\n");

            for (j = 0; j < NeffGraf(Graph(teman)); j++)
            {
                if (Edge(Graph(teman), index, j) == 1)
                {
                    printf(" | ");
                    printWord(Vertex(Graph(teman), j).nama);
                    printf("\n");
                    //printf("| %s\n", Vertex(Graph(teman), j).nama.TabWord);
                }
            }
        }
        else
        {
            printf("belum mempunyai teman\n");
        }
    }
}

void hapusTeman(Teman *teman,Word currentUser)
{
    int i;
    int currentUserIndex = -1;
    int idxToDelete = -1;

    printf("Masukkan nama pengguna:\n");
    STARTWORD();

  
    Word userToDelete = currentWord;

    // check index dari currentuser
    for (i = 0; i < NeffGraf(Graph(*teman)); i++)
    {
        if (isEqualWordWord(Vertex(Graph(*teman), i).nama, currentUser))
        {
            currentUserIndex = i;
            break;
        }
    }

    if (currentUserIndex != -1)
    {
        for (int i = 0; i < NeffGraf(Graph(*teman)); i++)
        {
            if (Edge(Graph(*teman), currentUserIndex, i) == 1 && isEqualWordWord(Vertex(Graph(*teman), i).nama, userToDelete))
            {
                idxToDelete = i;
                break;
            }
        }
    }
    if (idxToDelete != -1)
    {
        //printf("Apakah anda yakin ingin menghapus %s dari daftar teman anda? (YA/TIDAK) ", userToDelete.TabWord);
        printf("Apakah anda yakin ingin menghapus ");
        printWord(userToDelete);
        printf("dari daftar teman anda? (YA/TIDAK) ");

        STARTWORD();
       

        Word Ya = {"YA", 2};
        if (isEqualWordWord(currentWord, Ya))
        {
            removeEdge(&Graph(*teman), currentUser, userToDelete);
        }
        else
        {
            printf("Penghapusan teman dibatalkan.\n");
        }
    }
    else
    {
        //printf("%s bukan teman Anda.\n", userToDelete.TabWord);
        printWord(userToDelete);
        printf("bukan teman Anda.\n");
    }
}

void sentReq(Word currentUser, Teman *teman)
{
    int i, j;
    int currentUserIndex = -1;
    int newFriendIdx = -1;

    // Check apakah bisa mengirim req pertemanan
    boolean flag = false;

    printf("Masukkan nama pengguna:\n");
    STARTWORD();

    // check index dari currentuser
    for (i = 0; i < NeffGraf(teman->dataTeman); i++)
    {
        if (isEqualWordWord(Vertex(teman->dataTeman, i).nama, currentUser))
        {
            currentUserIndex = i;
            break;
        }
    }

    // check apakah ada request pertemanan
    if (IsEmptyPrio(Vertex(teman->dataTeman, i).friendReq))
    {
        // check index dari currentWord (teman yang akan ditambah)
        for (i = 0; i < NeffGraf(teman->dataTeman); i++)
        {
            if (isEqualWordWord(Vertex(teman->dataTeman, i).nama, currentWord))
            {
                newFriendIdx = i;
                break;
            }
        }
        if(newFriendIdx == currentUserIndex){
            printf("tidak valid.\n");
            return;
        }
        if (newFriendIdx != -1)
        {
            // check matrix sudah berteman atau belum
            for (i = 0; i < NeffGraf(teman->dataTeman); i++)
            {
                if (Edge(teman->dataTeman, currentUserIndex, newFriendIdx) == 0)
                {
                    flag = true;
                    break;
                }
            }

            // Check di matrix reqSave apakah sudah meminta request pertemanan
            if (flag == true)
            {
                for (i = 0; i < teman->saveReq.rowEff; i++)
                {
                    if ((charToInt((ELMTMTRX(teman->saveReq, i, 0))) == currentUserIndex && charToInt(ELMTMTRX(teman->saveReq, i, 1)) == newFriendIdx) ||
                        ((charToInt((ELMTMTRX(teman->saveReq, i, 0))) == newFriendIdx && charToInt(ELMTMTRX(teman->saveReq, i, 1)) == currentUserIndex)))
                    {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag == true)
            {
                // add ke prioqueue
                infotype newFriend;
                newFriend.jumlahTeman = countEdges(&teman->dataTeman, currentUser);
                newFriend.nama.Length = currentUser.Length;
                SalinWord(currentUser, &newFriend.nama);

                EnqueuePrio(&Vertex(teman->dataTeman, newFriendIdx).friendReq, newFriend);

                // add ke savereq
                // cari matrix yang available
                int idxAvail;
                for (i = 0; i < teman->saveReq.rowEff; i++)
                {
                    if (charToInt((ELMTMTRX(teman->saveReq, i, 0))) == 0 && charToInt((ELMTMTRX(teman->saveReq, i, 1))) == 0)
                    {
                        idxAvail = i;
                        break;
                    }
                }

                // masukan data ke matrix save req
                ELMTMTRX(teman->saveReq, i, 0) = intToChar(currentUserIndex);
                ELMTMTRX(teman->saveReq, i, 1) = intToChar(newFriendIdx);
                ELMTMTRX(teman->saveReq, i, 2) = intToChar(newFriend.jumlahTeman);

                printf("Permintaan pertemanan kepada "); 
                printWord(currentWord);
                printf("dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
            }
            else
            {
                printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
                printWord(currentWord);
                printf("atau anda sudah berteman.\n");
                
            }
        }
        else
        {
            //printf("Pengguna bernama %s tidak ditemukan.\n", currentWord.TabWord);
            printf("Pengguna bernama ");
            printWord(currentWord);
            printf(" tidak ditemukan.\n");
        }
    }
    else
    {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
}



void printRequest(Word user)
{
    int j;
    int idx;
    for (j = 0; j < NeffGraf(DataTeman.dataTeman); j++)
    {
        if (isEqualWordWord(Vertex(DataTeman.dataTeman, j).nama, user))
        {
            idx = j;
            break;
        }
    }
    
    if (IsEmptyPrio(DataTeman.dataTeman.vertex[idx].friendReq))
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
        return;
    }
    int i = Head(DataTeman.dataTeman.vertex[idx].friendReq);
    printf("Terdapat %d permintaan pertemanan untuk Anda.\n", NBElmtPrio(DataTeman.dataTeman.vertex[idx].friendReq));

    do
    {
        //printf(" | %s\n", Nama(Elmt(Q, i)).TabWord);
        printf(" | ");
        printWord(Nama(Elmt(DataTeman.dataTeman.vertex[idx].friendReq, i)));
        printf("\n");

        printf(" | Jumlah teman: %d\n", JumlahTeman(Elmt(DataTeman.dataTeman.vertex[idx].friendReq, i)));
        i = (i + 1) % MaxEl(DataTeman.dataTeman.vertex[idx].friendReq);
    } while (i != (Tail(DataTeman.dataTeman.vertex[idx].friendReq) + 1) % MaxEl(DataTeman.dataTeman.vertex[idx].friendReq));
}

void printReqMatrix(Matrix saveReq)
{
    int i, j;
    printf("SaveReq Matrix:\n");
    for (i = 0; i < saveReq.rowEff; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d", charToInt(ELMTMTRX(saveReq, i, j)));
        }
        printf("\n");
    }
}

Word getWord(int idx){
    return DataTeman.dataTeman.vertex[idx].nama;
}



void acceptRequest(Teman *teman, Word currentUser)
{
    infotype temp;
    int idx, i, idxToRemove;
    // check index dari currentuser
    for (i = 0; i < NeffGraf(teman->dataTeman); i++)
    {
        if (isEqualWordWord(Vertex(teman->dataTeman, i).nama, currentUser))
        {
            idx = i;
            break;
        }
    }
    if (!IsEmptyPrio(Vertex(teman->dataTeman, idx).friendReq))
    {
        //printf("Permintaan pertemanan teratas dari %s\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama.TabWord);
        printf("Permintaan pertemanan teratas dari ");
        printWord(InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama);
        printf("\n");

        //printf(" | %s\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama.TabWord);
        printf(" | ");
        printWord(InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama);
        printf("\n");

        printf(" | Jumlah teman: %d\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).jumlahTeman);

        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) \n");
        STARTWORD();

        Word Ya = {"YA", 2};
        if (isEqualWordWord(currentWord, Ya))
        {
            //printf("Permintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama.TabWord);
            printf("Permintaan pertemanan dari ");
            printWord(InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama);
            printf("telah disetujui. Selamat! Anda telah berteman dengan ");
            printWord(InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama);
            printf(".\n");


            addEdge(&teman->dataTeman, currentUser, InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama);
        }
        else
        {
            // decline request
            //printf("Permintaan pertemanan dari %s telah ditolak.\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama.TabWord);
            printf("Permintaan pertemanan dari ");
            printWord(InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama);
            printf(" telah ditolak.\n");


            
        }
        DequeuePrio(&teman->dataTeman.vertex[idx].friendReq, &temp);

        //idx dari matrix
        for (i = 0; i < teman->saveReq.rowEff; i++)
        {
            if (charToInt((ELMTMTRX(teman->saveReq, i, 0))) == idx || charToInt((ELMTMTRX(teman->saveReq, i, 1))) == idx)
            {
                ELMTMTRX(teman->saveReq, i, 0) = '0';
                ELMTMTRX(teman->saveReq, i, 1) = '0';
                ELMTMTRX(teman->saveReq, i, 2) = '0';
                break;
            }
        }

        //update matrix
        shiftMatrix(&teman->saveReq);
    }
}

boolean isFollowing(int idCurrent, int idCheck)
{
    if (Edge(DataTeman.dataTeman, idCurrent, idCheck) == 0)
        {
            return false;
        }
        else{
            return true;
        }
}
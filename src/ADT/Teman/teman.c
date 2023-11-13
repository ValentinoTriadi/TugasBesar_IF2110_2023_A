#include "teman.h"
#include <stdio.h>
#include <stdlib.h>

extern Word currentWord;

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

    if (index != -1)
    {
        // hitung berapa teman
        int count = countEdges(&Graph(teman), currentUser);

        printf("%s ", currentUser.TabWord);
        if (count > 0)
        {
            printf("memiliki %d teman\n", count);
            printf("Daftar teman %s\n", currentUser.TabWord);

            for (j = 0; j < NeffGraf(Graph(teman)); j++)
            {
                if (Edge(Graph(teman), index, j) == 1)
                {
                    printf("| %s\n", Vertex(Graph(teman), j).nama.TabWord);
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
        printf("Apakah anda yakin ingin menghapus %s dari daftar teman anda? (YA/TIDAK) ", userToDelete.TabWord);

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
        printf("%s bukan teman Anda.\n", userToDelete.TabWord);
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
                    if (charToInt((ELMTMTRX(teman->saveReq, i, 0)) == currentUserIndex && charToInt(ELMTMTRX(teman->saveReq, i, 1)) == newFriendIdx) ||
                        (charToInt((ELMTMTRX(teman->saveReq, i, 0)) == newFriendIdx && charToInt(ELMTMTRX(teman->saveReq, i, 1)) == currentUserIndex)))
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

                printf("Permintaan pertemanan kepada %s telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n", currentWord);
            }
            else
            {
                printf("Anda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.\n", currentWord);
            }
        }
        else
        {
            printf("Pengguna bernama %s tidak ditemukan.\n", currentWord.TabWord);
        }
    }
    else
    {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
}

// void tambahTeman(Teman *teman, Word currentUser)
// {
//     int idx, i;
//     // check index dari currentuser
//     for (i = 0; i < NeffGraf(teman->dataTeman); i++)
//     {
//         if (isEqualWord(Vertex(teman->dataTeman, i).nama, currentUser))
//         {
//             idx = i;
//             break;
//         }
//     }
// }

void printRequest(PrioQueueReq Q, Word user)
{
    int i = Head(Q);

    if (IsEmptyPrio(Q))
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
        return;
    }

    printf("Terdapat %d permintaan pertemanan untuk Anda.\n", NBElmtPrio(Q));

    do
    {
        printf(" | %s\n", Nama(Elmt(Q, i)).TabWord);
        printf(" | Jumlah teman: %d\n", JumlahTeman(Elmt(Q, i)));
        i = (i + 1) % MaxEl(Q);
    } while (i != (Tail(Q) + 1) % MaxEl(Q));
}

void printReqMatrix(Matrix saveReq)
{
    int i, j;
    printf("SaveReq Matrix:\n");
    for (i = 0; i < saveReq.rowEff; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", charToInt(ELMTMTRX(saveReq, i, j)));
        }
        printf("\n");
    }
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
        printf("Permintaan pertemanan teratas dari %s\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama.TabWord);
        printf(" | %s\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama.TabWord);
        printf(" | Jumlah teman: %d\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).jumlahTeman);

        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) \n");
        STARTWORD();

        Word Ya = {"YA", 2};
        if (isEqualWordWord(currentWord, Ya))
        {
            printf("Permintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama.TabWord);

            addEdge(&teman->dataTeman, currentUser, temp.nama);

            

        }
        else
        {
            // decline request
            printf("Permintaan pertemanan dari %s telah ditolak.\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama.TabWord);

            
        }
        DequeuePrio(&teman->dataTeman.vertex[idx].friendReq, &temp);

        //idx dari matrix
        for (i = 0; i < teman->saveReq.rowEff; i++)
        {
            if (charToInt((ELMTMTRX(teman->saveReq, i, 0)) == idx) || charToInt((ELMTMTRX(teman->saveReq, i, 1)) == idx))
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
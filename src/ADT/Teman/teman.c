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

void daftarTeman(Graf graph, Word currentUser)
{
    int index = -1;
    int i, j;

    // check index dari currentuser
    for (i = 0; i < NeffGraf(graph); i++)
    {
        if (isEqualWordWord(Vertex(graph, i).nama, currentUser))
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        // hitung berapa teman
        int count = countEdges(&graph, currentUser);

        printf("%s ", currentUser.TabWord);
        if (count > 0)
        {
            printf("memiliki %d teman\n", count);
            printf("Daftar teman %s\n", currentUser.TabWord);

            for (j = 0; j < NeffGraf(graph); j++)
            {
                if (Edge(graph, index, j) == 1)
                {
                    printf("| %s\n", Vertex(graph, j).nama.TabWord);
                }
            }
        }
        else
        {
            printf("belum mempunyai teman\n");
        }
    }
}

void hapusTeman(Graf *graph, Word currentUser)
{
    int i;
    int currentUserIndex = -1;
    int idxToDelete = -1;

    printf("Masukkan nama pengguna:\n");
    STARTWORD();

    ADVWORD();
    Word userToDelete = currentWord;

    // check index dari currentuser
    for (i = 0; i < NeffGraf(*graph); i++)
    {
        if (isEqualWordWord(Vertex(*graph, i).nama, currentUser))
        {
            currentUserIndex = i;
            break;
        }
    }

    if (currentUserIndex != -1)
    {
        for (int i = 0; i < NeffGraf(*graph); i++)
        {
            if (Edge(*graph, currentUserIndex, i) == 1 && isEqualWordWord(Vertex(*graph, i).nama, userToDelete))
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
        ADVWORD();

        Word Ya = {"YA", 2};
        if (isEqualWordWord(currentWord, Ya))
        {
            removeEdge(graph, currentUser, userToDelete);
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

    ADVWORD();

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
                    if ((ELMTMTRX(teman->saveReq, i, 0) == currentUserIndex && ELMTMTRX(teman->saveReq, i, 1) == newFriendIdx) ||
                        ((ELMTMTRX(teman->saveReq, i, 0) == newFriendIdx && ELMTMTRX(teman->saveReq, i, 1) == currentUserIndex)))
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
                newFriend.jumlahTeman = countEdges(&teman->dataTeman, currentWord);
                newFriend.nama.Length = currentWord.Length;
                newFriend.nama = currentWord;

                EnqueuePrio(&Vertex(teman->dataTeman, newFriendIdx).friendReq, newFriend);

                // add ke savereq
                // cari matrix yang available
                int idxAvail;
                for (i = 0; i < teman->saveReq.rowEff; i++)
                {
                    if (ELMTMTRX(teman->saveReq, i, 0) == 0 && ELMTMTRX(teman->saveReq, i, 1) == 0)
                    {
                        idxAvail = i;
                        break;
                    }
                }

                // masukan data ke matrix save req
                ELMTMTRX(teman->saveReq, i, 0) = currentUserIndex;
                ELMTMTRX(teman->saveReq, i, 1) = newFriendIdx;
                ELMTMTRX(teman->saveReq, i, 2) = newFriend.jumlahTeman;

                printf("Permintaan pertemanan kepada %s telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.", currentWord);
            }
            else
            {
                printf("Anda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.", currentWord);
            }
        }
        else
        {
            printf("Pengguna bernama %s tidak ditemukan.\n", currentWord.TabWord);
        }
    }
    else
    {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.");
    }
}

void tambahTeman(Teman *teman, Word currentUser)
{
    int idx, i;
    // check index dari currentuser
    for (i = 0; i < NeffGraf(teman->dataTeman); i++)
    {
        if (isEqualWordWord(Vertex(teman->dataTeman, i).nama, currentUser))
        {
            idx = i;
            break;
        }
    }
}

void printRequest(PrioQueueReq Q, Word user)
{
    int i = Head(Q);

    if (IsEmptyPrio(Q))
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
        return;
    }

    printf("Terdapat %d permintaan pertemanan untuk Anda.\n\n", NBElmtPrio(Q));

    do
    {
        printf("| %s\n", Nama(Elmt(Q, i)).TabWord);
        printf("| Jumlah teman: %d\n\n", JumlahTeman(Elmt(Q, i)));
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
            if (ELMTMTRX(saveReq, i, j) == 0 && ELMTMTRX(saveReq, j, i) == 0)
            {
                break;
            }
            printf("%d ", ELMTMTRX(saveReq, i, j));
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
        printf("Permintaan pertemanan teratas dari %s", InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama.TabWord);
        printf("| %s\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).nama.TabWord);
        printf("| Jumlah teman: %d\n", InfoHead(Vertex(teman->dataTeman, idx).friendReq).jumlahTeman);

        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
        STARTWORD();

        Word Ya = {"YA", 2};
        if (isEqualWordWord(currentWord, Ya))
        {
            DequeuePrio(&teman->dataTeman.vertex[idx].friendReq, &temp);
            addEdge(&teman->dataTeman, currentUser, temp.nama);


            // cari idx dari matrix

            /*TO-Do change to module*/
            for (i = 0; i < teman->saveReq.rowEff; i++)
            {
                if ((ELMTMTRX(teman->saveReq, i, 0) == idx) || (ELMTMTRX(teman->saveReq, i, 1) == idx))
                {
                    ELMTMTRX(teman->saveReq, i, 0) = 0;
                    ELMTMTRX(teman->saveReq, i, 1) = 0;
                    ELMTMTRX(teman->saveReq, i, 2) = 0;
                    break;
                }
            }

            //update matrix
        }
        else{
            //decline request

            //update matrix
        }
    }
}

void removeReq();
void updateQueueReq();
void updateMatReq();
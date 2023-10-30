#include "teman.h"
#include <stdio.h>
#include <stdlib.h>

extern Word currentWord;

void createTeman(Teman *teman)
{
    MakeEmptyPrio(&(teman->dataTeman.vertex->friendReq), 20);
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
        if (isEqualWord(Vertex(graph, i).nama, currentUser))
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
        if (isEqualWord(Vertex(*graph, i).nama, currentUser))
        {
            currentUserIndex = i;
            break;
        }
    }

    if (currentUserIndex != -1) {
    for (int i = 0; i < NeffGraf(*graph); i++) {
        if (Edge(*graph, currentUserIndex, i) == 1 && isEqualWord(Vertex(*graph, i).nama, userToDelete)) {
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
        if (isEqualWord(currentWord, Ya))
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

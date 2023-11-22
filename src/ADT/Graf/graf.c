#include <stdio.h>
#include <stdlib.h>
#include "graf.h"

void CreateGraph(Graf *g)
{
    NeffGraf(*g) = 0;
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            Edge(*g, i, j) = 0;
        }
    }
}

void addVertex(Graf *graph, Word vertex)
{
    if (NeffGraf(*graph) < 20)
    {
        int idx, i;
        Vertex(*graph, NeffGraf(*graph)).nama = vertex;

        
        NeffGraf(*graph)++;
        // check index
        for (i = 0; i < NeffGraf(*graph); i++)
        {
            if (isEqualWordWord(Vertex(*graph, i).nama, vertex))
            {
                idx = i;
                break;
            }
        }
        MakeEmptyPrio(&Vertex(*graph,idx).friendReq,20);
    }
    else
    {
        printf("Sudah tidak bisa lagi menambah.\n");
    }
}

void addEdge(Graf *graph, Word vertex1, Word vertex2)
{
    int index1 = -1, index2 = -1;
    int i;
    // Check apakah sudah ada edge
    for (i = 0; i < NeffGraf(*graph); i++)
    {
        if (isEqualWordWord(Vertex(*graph, i).nama, vertex1))
            index1 = i;
        if (isEqualWordWord(Vertex(*graph, i).nama, vertex2))
            index2 = i;
    }
    if (index1 != -1 && index2 != -1)
    {
        // Jika vertex blom terhubung
        if (Edge(*graph, index1, index2) == 0 && Edge(*graph, index2, index1) == 0)
        {
            Edge(*graph, index1, index2) = 1;
            Edge(*graph, index2, index1) = 1;
        }
        // Jika vertex sudah saling terhubung
        else
        {
            printf("Vertex sudah terhubung.\n");
        }
    }
    // Vertex tidak valid
    else
    {
        printf("Salah satu vertex tidak valid.\n");
    }
}

void removeEdge(Graf *graph, Word vertex1, Word vertex2)
{
    int index1 = -1, index2 = -1;
    for (int i = 0; i < NeffGraf(*graph); i++)
    {
        if (isEqualWordWord(Vertex(*graph, i).nama, vertex1))
            index1 = i;
        if (isEqualWordWord(Vertex(*graph, i).nama, vertex2))
            index2 = i;
    }
    if (index1 != -1 && index2 != -1)
    {
        if (Edge(*graph, index1, index2) == 1 && Edge(*graph, index2, index1) == 1)
        {
            Edge(*graph, index1, index2) = 0;
            Edge(*graph, index2, index1) = 0;

            //printf("%s dan %s tidak lagi berteman.\n", vertex1.TabWord, vertex2.TabWord);
            printWord(vertex1);
            printf(" dan ");
            printWord(vertex2);
            printf(" tidak lagi berteman.\n");
        }
        else
        {
            //printf("%s dan %s tidak sedang berteman.\n", vertex1.TabWord, vertex2.TabWord);
            printWord(vertex1);
            printf(" dan ");
            printWord(vertex2);
            printf(" tidak sedang berteman.\n");
        }
    }
    else
    {
        printf("Vertex tidak valid.\n");
    }
}

int countEdges(Graf *graph, Word vertex)
{
    int index = -1;
    for (int i = 0; i < NeffGraf(*graph); i++)
    {
        if (isEqualWordWord(Vertex(*graph, i).nama, vertex))
            index = i;
    }
    if (index != -1)
    {
        int count = 0;
        for (int j = 0; j < NeffGraf(*graph); j++)
        {
            if (Edge(*graph, index, j) == 1)
                count++;
        }
        return count;
    }
    else
    {
        return -1; // Jika tidak ada namanya dalam daftar
    }
}

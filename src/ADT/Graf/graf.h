#include "../boolean.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../PrioQueue/prioqueueReq.h"

#ifndef GRAF_H
#define GRAF_H

typedef struct
{
   Word nama;
   PrioQueueReq friendReq;
} Vertex;

typedef struct{
    Vertex vertex[20]; 
    int adjacencyMatrix[20][20]; //adjacencyMatrix
    int NeffGraf;
} Graf;

#define NeffGraf(graph) ((graph).NeffGraf)
#define Vertex(graph, index) (((graph).vertex[(index)]))
#define Edge(graph, i, j) ((graph).adjacencyMatrix[(i)][(j)])

// Inisialisasi graf
void CreateGraph(Graf *graph);

// Menambahkan teman ke graf
void addVertex(Graf *graph,Word vertex);

// Menambahkan hubungan pertemanan antara dua teman
void addEdge(Graf *graph,Word vertex1,Word vertex2);

//Remove pertemenan
void removeEdge(Graf *graph, Word vertex1, Word vertex2);

int countEdges(Graf *graph, Word vertex);

/*(STILL NOT WORKING)*/
//Word getNamebyId(Graf graph,int idx);

//int getIdbyName(Graf graph,Word Vertex);

#endif
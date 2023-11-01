#include "../boolean.h"
#include "../WordMachine/wordmachine.h"

#ifndef GRAF_H
#define GRAF_H

typedef struct{
    Word nama[20]; //Vertex 
    int adjacencyMatrix[20][20]; //adjacencyMatrix
    int jumlahTeman;
} Teman;

#define JumlahTeman(graph) ((graph).jumlahTeman)
#define NamaTeman(graph, index) ((graph).nama[(index)])
#define HubunganTeman(graph, i, j) ((graph).adjacencyMatrix[(i)][(j)])

// Inisialisasi graf
void CreateGraph(Teman *graph);

// Menambahkan teman ke graf
void addName(Teman *graph,Word friendName);

// Menambahkan hubungan pertemanan antara dua teman
void addFriendship(Teman *graph,Word friend1,Word friend2);

// Menampilkan daftar teman-teman seorang teman
void showFriends(Teman *graph,Word friendName);

//Remove pertemenan
void removeFriendship(Teman *graph, Word friend1, Word friend2);

int countFriends(Teman *graph, Word friendName);

#endif
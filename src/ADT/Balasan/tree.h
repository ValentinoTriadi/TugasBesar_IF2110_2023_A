#ifndef TREE_H
#define TREE_H

#include "../boolean.h"
#include "../ListStatik/liststatik.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../matrix/matrix.h"

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */

/* Definisi Type Data */
typedef struct tNode *addressTree;
typedef struct tNode {
    int data;
    addressTree firstChild;
    addressTree nextSibling;
} Node;

typedef struct {
    addressTree root;
} Tree;

typedef Tree ListTreeStatik_ElType;
typedef int ListTreeStatik_IdxType;
typedef struct {
    ListTreeStatik_ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListTreeStatik;


#define Data(P) (P)->data
#define FirstChild(P) (P)->firstChild
#define NextSibling(P) (P)->nextSibling
#define Root(T) (T).root
#define LISTELMT(l, i) (l).contents[(i)]

/* Definisi Pohon : */
/* Pohon kosong : P = Nil */
/* Setiap elemen dengan addressTree P dapat diacu Info(P), FirstChild(P), NextSibling(P) */
/* Elemen terakhir pohon : jika NextSibling(P) = Nil, maka P adalah elemen terakhir pohon */

void CreateTree(Tree *T);

addressTree Alokasi(int X);

void Dealokasi(addressTree P);

void AddChild(addressTree *P, addressTree C);

void AddSibling(addressTree *P, addressTree S);

void printSiblings(addressTree P);

void printChild(addressTree P);

void printTree (addressTree P, int h);

boolean isTreeElmt (addressTree P, int X);

addressTree getAddress (addressTree P, int X);

int Treemachine(char string[], Matrix *m);

void matrixToTree (Matrix m, int N, Tree *T);

addressTree getParent(addressTree root,addressTree C);

ListStatik getChild(addressTree parent);

ListStatik getAllNodes(addressTree parent);

void CreateListTreeStatik(ListTreeStatik *l);

int listLength_ListTreeStatik(ListTreeStatik l);

boolean isEmpty_ListTreeStatik(ListTreeStatik l);

void insertLast_ListTreeStatik(ListTreeStatik *l, ListTreeStatik_ElType val);

void printList_ListTreeStatik(ListTreeStatik l);

#endif
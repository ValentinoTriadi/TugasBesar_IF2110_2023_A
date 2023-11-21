#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*KONSTRUKTOR*/
void CreateTree(Tree *T){
    (*T).root = NULL;
}

/* *** Manajemen Memory *** */
addressTree Alokasi(int X){
    addressTree P = (addressTree) malloc(sizeof(Node));
    if(P != NULL){
        Data(P) = X;
        FirstChild(P) = NULL;
        NextSibling(P) = NULL;
    }
    return P;
}

void Dealokasi(addressTree P){
    free(P);
}


void AddChild(addressTree *P, addressTree C){
    if(*P == NULL){
        *P = C;
    }else{
        addressTree Q = *P;
        while(FirstChild(Q) != NULL){
            Q = FirstChild(Q);
        }
        FirstChild(Q) = C;
    }
}

void AddSibling(addressTree *P, addressTree S){
    if(*P == NULL){
        *P = S;
    }else{
        addressTree Q = *P;
        while(NextSibling(Q) != NULL){
            Q = NextSibling(Q);
        }
        NextSibling(Q) = S;
    }
}

void printSiblings(addressTree P){
    if(P != NULL){
        printf("%d ", Data(P));
        printSiblings(NextSibling(P));
    }
}

void printChild(addressTree P){
    if(P != NULL){
        printf("%d ", Data(P));
        printChild(FirstChild(P));
        printSiblings(NextSibling(P));
    }
}

void printTree (addressTree P, int h){
    if(P != NULL){
        int i;
        for(i = 0; i < h; i++){
            printf("    ");
        }
        printf("%d\n", Data(P));
        printTree(FirstChild(P), h+1);
        printTree(NextSibling(P), h);
    }
}

boolean isTreeElmt (addressTree P, int X){
    if(P != NULL){
        if(Data(P) == X){
            return true;
        }else{
            return isTreeElmt(FirstChild(P), X) || isTreeElmt(NextSibling(P), X);
        }
    }else{
        return false;
    }
}

// int to addressTree
addressTree getAddress (addressTree P, int X){
// I.S. P terdefinisi
// F.S. mengembalikan addressTree dengan data X
    if(P != NULL){
        if(Data(P) == X){
            return P;
        }else{
            addressTree Q = getAddress(FirstChild(P), X);
            if(Q != NULL){
                return Q;
            }else{
                return getAddress(NextSibling(P), X);
            }
        }
    }else{
        return NULL;
    }
}

int Treemachine(char string[], Matrix *m){
    int count = 0;
    int count1 = 1;
    int tempint = 1;
    int itemp = 0;
    int k = 0, j = 0;
    STARTWORD_FILE(string);
    tempint = WordToInt(currentWord);
    ADVWORD();
    while (count != tempint){
        if (count1 == 2){
            itemp = WordToInt(currentWord) + 2;
        }
        ELMTMTRX(*m,k,j) = WordToInt(currentWord);
        j++;
        if (count1 == itemp){
            k++;
            j = 0;
            count1 = 0;
            count++;
        }
        count1++;
        if (count != tempint){
            ADVWORD();
        }
    }
    return tempint;
}

void matrixToTree (Matrix m, int N, Tree *T){
    int i,j,k,found,temp;
    addressTree P[N];
    addressTree PPrev;
    addressTree PNow;

    for (i = 0 ; i < N ; i ++){
        P[i] = Alokasi(MATRIXELMT(m,i,0));
    }

    (*T).root = P[N-1];

    for (i = 0 ; i < N ; i++){
        temp = 0;
        for (j = 0 ; j < MATRIXELMT(m,i,1) ; j++){
            // check if m[i][j+2] exists in P
            found = 0;
            k = 0;
            while (k < N && !found){
                if (MATRIXELMT(m,i,j+2) == Data(P[k])){
                    found = 1;
                }
                k++;
            }
            if (!found){
                PNow = Alokasi(MATRIXELMT(m,i,j+2));
            } else {
                PNow = P[k-1];
            }

            if (temp == 0){
                AddChild(&P[i], PNow);
                temp = 1;
            }
            else{
                AddSibling(&PPrev, PNow);
            }
            PPrev = PNow;
        }
    }
}

addressTree getParent(addressTree root,addressTree C){
    // I.S. C terdefinisi
    // F.S. mengembalikan addressTree parent dari C
    if(FirstChild(root) == C){
        return root;
    }else{
        addressTree Q = FirstChild(root);
        while(Q != NULL){
            if(NextSibling(Q) == C){
                return root;
            }else{
                addressTree R = getParent(Q, C);
                if(R != NULL){
                    return R;
                }else{
                    Q = NextSibling(Q);
                }
            }
        }
        return NULL;
    }
}

ListStatik getChild(addressTree parent){
    ListStatik L;
    CreateListStatik(&L);
    if(FirstChild(parent)!=NULL){
        parent=FirstChild(parent);
        insertLast_ListStatik(&L,Data(parent));
        while (NextSibling(parent)!=NULL)
        {
            parent=NextSibling(parent);
            insertLast_ListStatik(&L,Data(parent));
        }            
    }
    return L;
}

ListStatik getAllNodes(addressTree parent){
    // return all the nodes inside the tree
    ListStatik L;
    CreateListStatik(&L);
    if(parent!=NULL){
        insertLast_ListStatik(&L,Data(parent));
        if(FirstChild(parent)!=NULL){
            L=concat_ListStatik(L,getAllNodes(FirstChild(parent)));
        }
        if(NextSibling(parent)!=NULL){
            L=concat_ListStatik(L,getAllNodes(NextSibling(parent)));
        }
    }
    return L;
}

    /* ----------------------------------------------- */

void CreateListTreeStatik(ListTreeStatik *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan LISTMARK */
{
    int i;
    for (i = 0; i < CAPACITY; i++){
        LISTELMT(*l, i).root = NULL;
    }
}
int listLength_ListTreeStatik(ListTreeStatik l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
    int i, count;
    count = 0;
    for (i = 0 ; i < CAPACITY ; i++){
        if (LISTELMT(l, i).root != NULL){
            count++;
        }
    }
    return count;
}
boolean isEmpty_ListTreeStatik(ListTreeStatik l){
    return (listLength_ListTreeStatik(l) == 0);
}

void insertLast_ListTreeStatik(ListTreeStatik *l, ListTreeStatik_ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    LISTELMT(*l, listLength_ListTreeStatik(*l)) = val;
}
void printList_ListTreeStatik(ListTreeStatik l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
    int i;
    for (i = 0; i < listLength_ListTreeStatik(l); i++) {
        printTree(LISTELMT(l,i).root, 0);
        printf("\n------------------- %d -------------------\n", i+1);
    }   

}
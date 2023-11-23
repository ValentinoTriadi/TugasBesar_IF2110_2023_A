#include "charmachine.h"
#include "wordmachine.h"
#include "../Database/db.h"
#include "utas.h"
#include <stdio.h>
#include <stdlib.h>

extern Word CurrentWord;

// Definisi struktur Utas


Address newNode(Kicauan tweet) {
    Address P = (Address)malloc(sizeof(NodeUtas));
    if(P!=NULL){
        INFO(P) = tweet;
        NEXT(P) = NULL;
    }
    return P;
}

boolean checkKicau(int IDKicau, ListUtas L){
    //Check apakah kicauan ada atau tidak
    boolean found = false;
    int i = 0;
    while (i < L.length && !found){
        if (IDKicau == L.Utas[i].mainTweet->id){
            found = true;
        }
        i++;
    }
    return found;
}

void CreateUtas(Utas* Utas,int IDKicau){
    Address p = newNode(DaftarKicau.kicau[IDKicau]);
    if (p != NULL){
        DaftarUtas.length += 1;
        Utas->mainTweet = p;
        Utas->tweetCount += 1;
        Utas->IDUtas = DaftarUtas.length;
    }    
}

boolean checkUtas(int IDUtas,int idx){
    boolean found = false;
    int i = 0;
    while (i < DaftarUtas.length && !found){
        if (IDUtas == DaftarUtas.Utas[i].IDUtas){
            return true;
        }
        i++;
    }
    return false;
}



// Fungsi untuk membuat utas baru
void UTAS(int CurrentUser) {
    // static int currentID = 1;  // Variable statis untuk melacak ID berikutnya
    // u->IDUtas = currentID++;
    // u->mainTweet = mainTweet;
    // u->tweetCount = 1;  // Memulai dengan satu kicauan (kicauan utama)
    // printf("Utas berhasil dibuat!\\n");

    int IDKicau;

    STARTWORD();
    printf("Masukkan ID Kicauan yang ingin dibuat utas: \n");
    IDKicau = wordToInt(CurrentWord);


    if(!checkKicau(IDKicau, DaftarUtas)){
        //Check author dari kicauan
        if(CurrentUser == DaftarKicau.kicau[IDKicau].author){
            CreateUtas(&DaftarUtas,IDKicau);


            
        }else{
            printf("Anda tidak dapat membuat utas dari kicauan orang lain!\n");
        }











        printf("Utas berhasil dibuat!\\n");
    } else {
        printf("Utas sudah ada!\\n");
    }


}

// Fungsi untuk menambahkan kicauan ke dalam utas
void SAMBUNG_UTAS(Utas u, Kicauan tweet, int index) {
    if (index < 0 || index > u.tweetCount) {
        printf("Index terlalu tinggi!\\n");
        return;
    }

    Kicauan* current = u.mainTweet;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    tweet->next = current->next;
    current->next = tweet;
    u->tweetCount++;

    printf("Kicauan berhasil ditambahkan.\\n");
}

// Fungsi untuk menghapus kicauan dari utas
void HAPUS_UTAS(Utas *u, int index) {
    if (index < 0 || index >= u->tweetCount) {
        printf("Index tidak ditemukan pada utas!\\n");
        return;
    }
    if (index == 0) {
        printf("Anda tidak bisa menghapus kicauan utama!\\n");
        return;
    }

    Kicauan* current = u->mainTweet;
    Kicauan* toDelete = NULL;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    toDelete = current->next;
    current->next = toDelete->next;
    free(toDelete);
    u->tweetCount--;

    printf("Kicauan sambungan berhasil dihapus!\\n");
}

// Fungsi untuk mencetak utas
void CETAK_UTAS(const Utas *u) {
    printf("Utas ID: %d\\n", u->IDUtas);
    Kicauan* current = u->mainTweet;
    int index = 0;
    while (current != NULL) {
        printf("| INDEX = %d\\n| %s\\n", index, current->text); // Asumsi 'text' adalah bagian dari struktur Kicauan
        current = current->next; // Asumsi 'next' adalah bagian dari struktur Kicauan
        index++;
    }
}

// Fungsi utama untuk menguji ADT Utas
int main() {
    // Implementasi uji coba fungsi Utas dengan charmachine dan wordmachine
    return 0;
}
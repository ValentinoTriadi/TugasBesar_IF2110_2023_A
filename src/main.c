#include "./ADT/Perintah/perintah.h"
#include "./ADT/Inisialisasi/inisialisasi.h"
#include <stdio.h>

extern Word currentWord;
extern Word currentSentence;
extern boolean EndWord;
boolean endProgram;

int main(){
    // Kamus
    Word listPerintah[3];
    Word initial_word;
    Word load;
    FILE *fascii;
    char * filename;
    int i;

    // Inisiasi status program
    endProgram = false;

    // Inisiasi Input Perintah
    HURUF(load, 0) = 'L';
    HURUF(load, 1) = 'O';
    HURUF(load, 2) = 'A';
    HURUF(load, 3) = 'D';
    load.Length = 4; 
    inisialisasi();
    listPerintah[0] = load;
    listPerintah[1] = currentWord;
    bacaPerintah(listPerintah);
    initial_word.Length = 0;
    while (!endProgram){
        i = 0;
        listPerintah[1] = initial_word;
        listPerintah[2] = initial_word;
        printf("%s>> ", NORMAL);
        STARTWORD();
        while (!EndWord){
            listPerintah[i] = currentWord;
            i++;
            ADVWORD();
        }
        bacaPerintah(listPerintah);
        if (!endProgram){
            filename = "./ADT/Inisialisasi/img1.txt";
            system("cls || clear");
            print_image(filename);
        }

    }

    return 0;
}
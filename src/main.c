#include "/Spesifikasi_Program/Perintah/perintah.c"
#include <stdio.h>
Word currentWord;
boolean EndWord;
boolean endProgram;

int main(){
    // Kamus
    Word listPerintah[3];
    Word initial_word;
    int i = 0;

    // Inisiasi status program
    endProgram = false;

    // Inisiasi Input Perintah
    initial_word.Length = 0;
    listPerintah[1] = initial_word;
    listPerintah[2] = initial_word;

    while (!endProgram){
        printf(">> ");
        STARTWORD();
        while (!EndWord){
            listPerintah[i] = currentWord;
            i++;
            ADVWORD();
        }
        bacaPerintah(listPerintah);
    }

    return 0;
}
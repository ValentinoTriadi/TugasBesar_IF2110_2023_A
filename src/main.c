#include "ADT/Database/db.h"
#include <stdio.h>
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
        printf("%s>> ", YELLOW);
        printf("%s", NORMAL);

        STARTWORD();
        while (!EndWord){
            listPerintah[i] = currentWord;
            i++;
            ADVWORD();
        }
        bacaPerintah(listPerintah);
        delay(1);
        if (!endProgram){
            // filename = "./ADT/Inisialisasi/img1.txt";
            // system("cls || clear");
            printf("%s\n=====================================================================================================================\n",BLUE);
        }
    }

    return 0;
}
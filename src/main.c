#include "Spesifikasi_Program/Perintah/perintah.c"
#include "Spesifikasi_Program/Inisialisasi/inisialisasi.c"
#include <stdio.h>
extern Word currentWord;
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
            filename = "Spesifikasi_Program/Inisialisasi/img1.txt";
            fascii = NULL;
            fascii = fopen(filename,"r");
            if(fascii == NULL){
                printf("error opening %s\n",filename);
            } else {
                system("cls || clear");
                print_image(fascii);
                fclose(fascii);
            }
        }

    }

    return 0;
}
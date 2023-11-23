#include <stdio.h>
#include <stdlib.h>
#include "../Database/db.h"
#include "inisialisasi.h"

void print_image(char* filename){
    system("cls || clear");
    STARTSENTENCEWITHNL(filename);
    Word s = currentSentence;
    printf("%s%s\n",CYAN, s.TabWord);
    // while(fgets(read_string,sizeof(read_string),fascii) != NULL)
    // printf("%s%s",CYAN,read_string);
    // printf("\n");
}

void inisialisasi(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    // printf("HALO\n");
    for (int i = 0; i < 5; i++){
        if (i == 0) {
            filename = "./ADT/Inisialisasi/img5.txt";
        } else if (i == 1){
            filename = "./ADT/Inisialisasi/img4.txt";
        } else if (i == 2){
            filename = "./ADT/Inisialisasi/img3.txt";
        } else if (i == 3){
            filename = "./ADT/Inisialisasi/img2.txt";
        } else if (i == 4){
            filename = "./ADT/Inisialisasi/img1.txt";
        }
        // fascii = NULL;
        // fascii = fopen(filename,"r");
        // if(fascii  == NULL){
            // printf("error opening %s\n",filename);
        // } else {
            // system("cls || clear");
        print_image(filename);
            // fclose(fascii);
        // }
        delay(1);
    }
    DaftarPengguna.total = 0;
    CurrentUser = -1;
    CreateListKicau(10);
    CreateEmptyDraf(&Draf);
    //CreateListTreeStatik(&dataBalasan);
    createTeman(&DataTeman);
    CreateList(&DaftarUtas);
    DaftarUtas.neffUtas = 0;

    printf("%sSilahkan masukan folder konfigurasi untuk dimuat: ", NORMAL);
    STARTINPUT();
    load(currentSentence);
    // printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}
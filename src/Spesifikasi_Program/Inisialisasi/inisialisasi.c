#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/wordmachine.h"
#include "../../ADT/pcolor.h"
 
#define MAX_LEN 5000

extern Word currentWord;

void delay(int number_of_half_seconds){
    int milli_seconds = 500 * number_of_half_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void print_image(FILE *fascii)
{
    char read_string[MAX_LEN];
    while(fgets(read_string,sizeof(read_string),fascii) != NULL)
    printf("%s%s",CYAN,read_string);
    printf("\n");
}

void inisialisasi(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    printf("HALO\n");
    for (int i = 0; i < 5; i++){
        if (i == 0) {
            filename = "Spesifikasi_Program/Inisialisasi/img5.txt";
        } else if (i == 1){
            filename = "Spesifikasi_Program/Inisialisasi/img4.txt";
        } else if (i == 2){
            filename = "Spesifikasi_Program/Inisialisasi/img3.txt";
        } else if (i == 3){
            filename = "Spesifikasi_Program/Inisialisasi/img2.txt";
        } else if (i == 4){
            filename = "Spesifikasi_Program/Inisialisasi/img1.txt";
        }
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            printf("error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
        }
        delay(1);
    }
    printf("%sSilahkan masukan folder konfigurasi untuk dimuat: ", NORMAL);
    STARTWORD();
    // load(currentWord);
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}
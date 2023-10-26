#include <stdio.h>
#include <stdlib.h>
 
#define MAX_LEN 5000

void print_image(FILE *fascii)
{
    char read_string[MAX_LEN];
    while(fgets(read_string,sizeof(read_string),fascii) != NULL)
        printf("%s",read_string);
    printf("\n");
}
void inisialisasi(){
    char *filename;
    FILE *fascii;
    system("cls || clear");
    printf("HALO\n");
    // for (int i = 0; i < 6; i++){
        filename = "Spesifikasi_Program/Inisialisasi/img1.txt";
        fascii = NULL;
        fascii = fopen(filename,"r");
        if(fascii  == NULL){
            fprintf(stderr,"error opening %s\n",filename);
        } else {
            system("cls || clear");
            print_image(fascii);
            fclose(fascii);
            
        }
    // }
}
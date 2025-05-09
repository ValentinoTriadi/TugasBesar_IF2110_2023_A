// #include "muat.h"
// #include <stdio.h>
// #include <sys/stat.h>

// void loadpenggunakuy(char* NamaFile){
//     char name[(Strlen(NamaFile) + 17)];
//     int i;
//     for (i = 0; i<(Strlen(NamaFile)); i++){
//         name[i] = NamaFile[i];
//     }
//     char config[17] = "/pengguna.config";
//     for (i = 0; i<(16); i++){
//         name[Strlen(NamaFile) + i] = config[i];
//     }
//     printf("NAMA FILE DI LOAD : %s\n", name);
//     READFILE(name);
//     printf("-------\n");
//     Word temp = currentSentence;
//     printWord(temp);
//     printf("\n");
//     printf("-------\n");
//     int n = wordToInt(currentSentence);
//     for (int i = 0; i<n; i++){
//         ADVSENTENCEFILE();
//         printWord(currentSentence);
//         printf("\n");
//         printf("-------\n");
//         ADVSENTENCEFILE();
//         printWord(currentSentence);
//         printf("\n");
//         printf("-------\n");
//         ADVSENTENCEFILE();
//         printWord(currentSentence);
//         printf("\n");
//         printf("-------\n");
//         ADVSENTENCEFILE();
//         printWord(currentSentence);
//         printf("\n");
//         printf("-------\n");
//         ADVSENTENCEFILE();
//         printWord(currentSentence);
//         printf("\n");
//         printf("-------\n");
//         ADVSENTENCEFILE();
//         printWord(currentSentence);
//         printf("\n");
//         printf("-------\n");

//         for (int j = 0; j<5;j++){
//             ADVSENTENCEFILE();
//             printf("\n");
//             for (int k = 0; k<5; k++){
//                 // DaftarPengguna.pengguna[i].warna_profil.mem[j][k] = currentSentence.TabWord[(k*4)];
//                 // DaftarPengguna.pengguna[i].foto_profil.mem[j][k] = currentSentence.TabWord[(k*4)+2];
//                 printf("%c ", currentSentence.TabWord[(k*4)]);
//                 printf("%c ", currentSentence.TabWord[(k*4)+2]);
//             }
//             printf("\n");
//         }
//     }
//     for(int i=0; i<n; i++){
//         ADVSENTENCEFILE();
//         // printWord(currentSentence);
//         for (int j = 0; j < n; j++){
//             // DataTeman.dataTeman.adjacencyMatrix[i][j] = charToInt(currentSentence.TabWord[(2*j)]);
//             printf("%d ", charToInt(currentSentence.TabWord[(2*j)]));
//         }
//         printf("\n");
//     }
//     ADVSENTENCEFILE();
//     printWord(currentSentence);
//     printf("\n");
//     n = wordToInt(currentSentence);
//     for(int i=0; i<n; i++){
//         ADVSENTENCEFILE();
//         printWord(currentSentence);
//         printf("\n");
//     }
// }

// int main(){
//     boolean isExists;
//     struct stat st = {0};
//     char* NamaFile = "First";
//     char FullPath[100]= "./Config/";
//     int len = Strlen(FullPath);
//     int i;
//     for (i = 0; i <Strlen(NamaFile); i++){
//         FullPath[len+i] = NamaFile[i];
//     }
//     FullPath[len+i] = '\0';


//     if (stat(FullPath, &st) == -1) {
//         isExists = false;
//         printf("Tidak ada folder yang dimaksud!\n");
//     } else {
//         isExists = true;
        
//         printf("Anda akan melakukan pemuatan dari ");
//         printf("%s",NamaFile);
//         printf(".\n\nMohon tunggu...\n");
//         delay(2);
//         printf("1...\n");
//         delay(2);
//         printf("2...\n");
//         delay(2);
//         printf("3...\n");
//         delay(2);
//         printf("Pemuatan selesai!\n");
//         loadpenggunakuy(FullPath);   
//     }
//     return 0;
// }

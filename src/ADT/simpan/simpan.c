#include "../Database/db.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

void savePengguna(char * FilePath){
    char name[(Strlen(FilePath) + 17)];
    int i;
    for (i = 0; i<(Strlen(FilePath)); i++){
        name[i] = FilePath[i];
    }
    char config[17] = "/pengguna.config";
    for (i = 0; i<(16); i++){
        name[Strlen(FilePath) + i] = config[i];
    }
    name[(Strlen(FilePath) + 16)] = '\0';

    FILE* f = fopen(name, "w");

    fprintf(f, "%d\n", DaftarPengguna.total);
    for (int i = 0; i < DaftarPengguna.total; i++){
        char * s = wordToStr(DaftarPengguna.pengguna[i].nama);
        fprintf(f, "%s\n", s);
        free(s);

        s = wordToStr(DaftarPengguna.pengguna[i].sandi);
        fprintf(f, "%s\n", s);
        free(s);

        s = wordToStr(DaftarPengguna.pengguna[i].bio);
        fprintf(f, "%s\n", s);
        free(s);

        s = wordToStr(DaftarPengguna.pengguna[i].no_hp);
        fprintf(f, "%s\n", s);
        free(s);

        s = wordToStr(DaftarPengguna.pengguna[i].weton);
        fprintf(f, "%s\n", s);
        free(s);

        if (DaftarPengguna.pengguna[i].jenis_akun){
            fprintf(f, "Publik\n");
        } else {
            fprintf(f, "Private\n");
        }
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                fprintf(f, "%c %c", DaftarPengguna.pengguna[i].warna_profil.mem[j][k], DaftarPengguna.pengguna[i].foto_profil.mem[j][k]);
                if (k != 4) fprintf(f, " ");
            }
            fprintf(f, "\n");
        }
    }
    for (int i = 0; i < DaftarPengguna.total; i++){
        for (int j = 0; j < DaftarPengguna.total; j++){
           fprintf(f, "%d", DataTeman.dataTeman.adjacencyMatrix[i][j]);
           if (j != 4) fprintf(f, " "); 
        }
        fprintf(f, "\n");
    }
    // req teman bloman
    int count = 0;
    for (int i = 0; i < DataTeman.saveReq.rowEff;i++){
        if(ELMTMTRX(DataTeman.saveReq,i,0) == 0 && ELMTMTRX(DataTeman.saveReq,i,1) == 0 ){
            break;
        }else{
            count++;
        }
    }
    fprintf(f, "%d\n", count);
    for (int i = 0; i < count; i++){
        fprintf(f, "%d %d %d\n", DataTeman.saveReq.mem[i][0], DataTeman.saveReq.mem[i][1], DataTeman.saveReq.mem[i][2]);
    }

    
    fclose(f);
}

void saveKicauan(char* FilePath){
    char name[(Strlen(FilePath) + 16)];
    int i;
    for (i = 0; i<(Strlen(FilePath)); i++){
        name[i] = FilePath[i];
    }
    char config[16] = "/kicauan.config";
    for (i = 0; i<(15); i++){
        name[Strlen(FilePath) + i] = config[i];
    }
    name[(Strlen(FilePath) + 15)] = '\0';

    FILE* f = fopen(name, "w");
    fprintf(f, "%d\n", DaftarKicau.nEff);
    for(int i =0; i < DaftarKicau.nEff; i++){
        fprintf(f, "%d\n", DaftarKicau.kicau[i].id);
        char* s = wordToStr(DaftarKicau.kicau[i].text);
        fprintf(f, "%s\n", s);
        free(s);
        fprintf(f, "%d\n", DaftarKicau.kicau[i].like);
        s = wordToStr(DaftarPengguna.pengguna[DaftarKicau.kicau[i].author].nama);
        fprintf(f, "%s\n", s);
        free(s);

        fprintf(f, "%02d/%02d/%04d %02d:%02d:%02d\n", DaftarKicau.kicau[i].datetime.DD, DaftarKicau.kicau[i].datetime.MM, DaftarKicau.kicau[i].datetime.YYYY, DaftarKicau.kicau[i].datetime.T.HH, DaftarKicau.kicau[i].datetime.T.MM, DaftarKicau.kicau[i].datetime.T.SS);
    }
    fclose(f);
}

void saveDraf(char* FilePath){
    char name[(Strlen(FilePath) + 13)];
    int i;
    for (i = 0; i<(Strlen(FilePath)); i++){
        name[i] = FilePath[i];
    }
    char config[13] = "/draf.config";
    for (i = 0; i<(12); i++){
        name[Strlen(FilePath) + i] = config[i];
    }
    name[(Strlen(FilePath) + 12)] = '\0';

    FILE* f = fopen(name, "w");
    int n = 0;
    for (int i = 0; i<20; i++){
        if (Draf.Draf[i].TOP != Nil) n++;
    }
    fprintf(f, "%d\n",n);
    i = 0;
    while (n != 0){
        if (Draf.Draf[i].TOP != -1){
            n--;
            char* s = wordToStr(DaftarPengguna.pengguna[i].nama);
            fprintf(f, "%s ", s);
            free(s);
            fprintf(f, "%d\n", Draf.Draf[i].TOP +1);
            for (int j = Draf.Draf[i].TOP; j >=0; j--){
                s = wordToStr(Draf.Draf[i].T[j].text);
                fprintf(f, "%s\n", s);
                free(s);
                fprintf(f, "%02d/%02d/%04d %02d:%02d:%02d\n", Draf.Draf[i].T[j].timestamp.DD, Draf.Draf[i].T[j].timestamp.MM, Draf.Draf[i].T[j].timestamp.YYYY, Draf.Draf[i].T[j].timestamp.T.HH, Draf.Draf[i].T[j].timestamp.T.MM, Draf.Draf[i].T[j].timestamp.T.SS);
            }
        }
        i++;
    }
    fclose(f);
}

boolean createFolder(char* path){
    printf("\n%s\n", path);
    int check = mkdir(path, 0777);
    return true;
}

void simpan(){
    printf("Masukkan nama folder yang hendak disimpan: ");
    STARTINPUT();
    Word NamaFile = currentSentence;
    struct stat st = {0};
    char FullPath[100]= "./Config/";
    int len = Strlen(FullPath);
    int i;
    for (i = 0; i <NamaFile.Length; i++){
        FullPath[len+i] = NamaFile.TabWord[i];
    }
    FullPath[len+i] = '\0';
    boolean success;
    if (stat(FullPath, &st) == -1) {
        printf("\nBelum terdapat "); 
        printWord(NamaFile);
        printf(". Akan dilakukan pembuatan "); 
        printWord(NamaFile);
        success = createFolder(FullPath);
        if (success) {
            printf(" terlebih dahulu.\n");
            printf("\nMohon tunggu...\n");
            delay(2);
            printf("%s1...\n", RED);
            delay(2);
            printf("%s2...\n", YELLOW);
            delay(2);
            printf("%s3...\n%s", GREEN, NORMAL);
            delay(2);
            printf("Pemuatan selesai!\n");
        }
    } else {
        success = true;
    }
    if (success){
        printf("\nAnda akan melakukan penyimpanan di ");
        printWord(NamaFile);
        printf(".\n\nMohon tunggu...\n");
        delay(2);
        printf("%s1...\n", RED);
        delay(2);
        printf("%s2...\n", YELLOW);
        delay(2);
        printf("%s3...\n%s", GREEN, NORMAL);
        delay(2);
        printf("\nPenyimpanan telah berhasil dilakukan!\n");
        savePengguna(FullPath);
        saveKicauan(FullPath);
        saveDraf(FullPath);
    }
}
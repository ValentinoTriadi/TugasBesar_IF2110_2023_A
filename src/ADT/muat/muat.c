#include <stdio.h>
#include <sys/stat.h>
#include "muat.h"
#include "../Database/db.h"

void loadDraf(char* NamaFile){
    char name[(Strlen(NamaFile) + 13)];
    int i;
    for (i = 0; i<(Strlen(NamaFile)); i++){
        name[i] = NamaFile[i];
    }
    char config[13] = "/draf.config";
    for (i = 0; i<(12); i++){
        name[Strlen(NamaFile) + i] = config[i];
    }
    name[(Strlen(NamaFile) + 12)] = '\0';
    READFILE(name);
    int n = wordToInt(currentSentence);
    for (int i = 0; i < n; i++){
        ADVSENTENCEFILE();
        int idx_last_space = findIdxLastSpace(currentSentence);
        int idxUser = findIndexUser(getWordBeforeIdx(currentSentence, idx_last_space));
        int countDraf = wordToInt(getWordAfterIdx(currentSentence, idx_last_space));
        for (int j = 0; j < countDraf; j++){
            infotypeDraf x;
            ADVSENTENCEFILE();
            x.text = currentSentence;
            ADVSENTENCEFILE();
            x.timestamp = wordToDatetime(currentSentence);
            Push(&Draf.Draf[idxUser], x);
        }
        reverseStack(idxUser);
    }
}

void loadKicau(char* NamaFile){
    char name[(Strlen(NamaFile) + 16)];
    int i;
    for (i = 0; i<(Strlen(NamaFile)); i++){
        name[i] = NamaFile[i];
    }
    char config[16] = "/kicauan.config";
    for (i = 0; i<(15); i++){
        name[Strlen(NamaFile) + i] = config[i];
    }
    name[(Strlen(NamaFile) + 15)] = '\0';
    READFILE(name);
    int n = wordToInt(currentSentence);
    Kicauan k;
    for (int i = 0; i<n; i++){
        ADVSENTENCEFILE();
        k.id = wordToInt(currentSentence); 
        ADVSENTENCEFILE();
        k.text = currentSentence; 
        ADVSENTENCEFILE();
        k.like = wordToInt(currentSentence);
        ADVSENTENCEFILE();
        k.author = findIndexUser(currentSentence);
        ADVSENTENCEFILE();
        k.datetime = wordToDatetime(currentSentence);
        AddTweetToList(k);
    }
}

void loadPengguna(char* NamaFile){
    char name[(Strlen(NamaFile) + 17)];
    int i;
    for (i = 0; i<(Strlen(NamaFile)); i++){
        name[i] = NamaFile[i];
    }
    char config[17] = "/pengguna.config";
    for (i = 0; i<(16); i++){
        name[Strlen(NamaFile) + i] = config[i];
    }
    name[(Strlen(NamaFile) + 16)] = '\0';
    READFILE(name);
    // printWord(currentSentence);
    int n = wordToInt(currentSentence);
    DaftarPengguna.total = n;
    for (int i = 0; i<n; i++){
        ADVSENTENCEFILE();
        // printWord(currentSentence);
        NAMA(DaftarPengguna.pengguna[i]) = currentSentence;
        addVertex(&DataTeman.dataTeman, currentSentence);
        ADVSENTENCEFILE();
        // printWord(currentSentence);
        SANDI(DaftarPengguna.pengguna[i]) = currentSentence;
        ADVSENTENCEFILE();
        // printWord(currentSentence);
        BIO(DaftarPengguna.pengguna[i]) = currentSentence;
        ADVSENTENCEFILE();
        // printWord(currentSentence);
        HP(DaftarPengguna.pengguna[i]) = currentSentence;
        ADVSENTENCEFILE();
        // printWord(currentSentence);
        WETON(DaftarPengguna.pengguna[i]) = currentSentence;
        ADVSENTENCEFILE();
        // printWord(currentSentence);

        if (isEqualWordStr(currentSentence, "Publik")){
            JENISAKUN(DaftarPengguna.pengguna[i]) = publik;
        } else {
            JENISAKUN(DaftarPengguna.pengguna[i]) = private;
        }
        for (int j = 0; j<5;j++){
            ADVSENTENCEFILE();
            for (int k = 0; k<5; k++){
                DaftarPengguna.pengguna[i].warna_profil.mem[j][k] = currentSentence.TabWord[(k*4)];
                DaftarPengguna.pengguna[i].foto_profil.mem[j][k] = currentSentence.TabWord[(k*4)+2];
            }
        }
    }
    for(int i=0; i<n; i++){
        ADVSENTENCEFILE();
        for (int j = 0; j < n; j++){
            DataTeman.dataTeman.adjacencyMatrix[i][j] = charToInt(currentSentence.TabWord[(2*j)]);
        }
    }
    ADVSENTENCEFILE();
    n = wordToInt(currentSentence);
    for(int i=0; i<n; i++){
        ADVSENTENCEFILE();
        infotype x;
        x.nama = DaftarPengguna.pengguna[charToInt(currentSentence.TabWord[0])].nama;
        x.jumlahTeman = charToInt(currentSentence.TabWord[4]);
        EnqueuePrio(&DataTeman.dataTeman.vertex[charToInt(currentSentence.TabWord[2])].friendReq, x);
        ELMTMTRX(DataTeman.saveReq,i,0) = charToInt(currentSentence.TabWord[0]);
        ELMTMTRX(DataTeman.saveReq,i,1) = charToInt(currentSentence.TabWord[2]);
        ELMTMTRX(DataTeman.saveReq,i,2) = charToInt(currentSentence.TabWord[4]);
        
         
    }
    // 0 1 2
 

    

}

void muat(){
    if (CurrentUser != -1){
        printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
    } else {
        printf("Masukkan nama folder yang hendak dimuat: ");
        STARTINPUT();
        Word NamaFile = currentSentence;
        
        load (NamaFile);
    }
}

void load(Word NamaFile){
    boolean isExists;
    struct stat st = {0};
    char FullPath[100]= "./Config/";
    int len = Strlen(FullPath);
    int i;
    for (i = 0; i <NamaFile.Length; i++){
        FullPath[len+i] = NamaFile.TabWord[i];
    }
    FullPath[len+i] = '\0';


    if (stat(FullPath, &st) == -1) {
        isExists = false;
        printf("Tidak ada folder yang dimaksud!\n");
    } else {
        isExists = true;
        DaftarPengguna.total = 0;
        CurrentUser = -1;
        CreateListKicau(10);
        for (int i = 0; i < 20; i++){
            CreateEmptyDraf(&Draf.Draf[i]);
        }
        createTeman(&DataTeman);
        CreateList(&DaftarUtas);
        DaftarUtas.neffUtas =1 ;
        printf("Anda akan melakukan pemuatan dari ");
        printWord(NamaFile);
        printf(".\n\nMohon tunggu...\n");
        delay(2);
        printf("%s1...\n", RED);
        delay(2);
        printf("%s2...\n", YELLOW);
        delay(2);
        printf("%s3...\n%s", GREEN, NORMAL);
        delay(2);
        printf("Pemuatan selesai!\n");
        loadPengguna(FullPath);
        loadKicau(FullPath);
        loadDraf(FullPath);
    }
}
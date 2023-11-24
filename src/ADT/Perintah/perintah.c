#include "perintah.h"
#include <stdio.h>
#include <time.h>
#include "../Database/db.h"

Word temp;

void printPerintah(Word cmd){
    for (int i = 0; i < cmd.Length; i++){
        printf("%c",cmd.TabWord[i]);
    }
    printf("\n");
}
void bacaPerintah(Word* cmd){
    // TAMBAHAN
    if (isEqualWordStr(cmd[0], "LOAD")){
        // printf("%s\n",cmd[0].TabWord);
        // printf("%s\n",cmd[1].TabWord);
        // load();
    }
    if (isEqualWordStr(cmd[0], "CEKUSER")){
        // printf("%s\n",cmd[0].TabWord);
        // printf("%d\n",cmd[0].Length);
        printUser();
    }
    // TAMBAHAN

    
    if (isEqualWordStr(cmd[0], "DAFTAR")){
        // printf("%s\n",cmd[0].TabWord);
        // printf("%d\n",cmd[0].Length);
        daftar();
    }
    if (isEqualWordStr(cmd[0], "MASUK")){
        // printf("%s\n",cmd[0].TabWord);
        masuk();
    }
    if (isEqualWordStr(cmd[0], "KELUAR")){
        // printf("%s\n",cmd[0].TabWord);
        keluar();
    }
    if (isEqualWordStr(cmd[0], "TUTUP_PROGRAM")){
        // printf("%s\n",cmd[0].TabWord);
        tutupProgram();
    }
    if (isEqualWordStr(cmd[0], "DAFTAR_TEMAN")){
        // printf("%s\n",cmd[0].TabWord);
        SalinWord(getWord(CurrentUser),&temp);
        daftarTeman(DataTeman, temp);
    }
    if (CurrentUser != -1){
        if (isEqualWordStr(cmd[0], "GANTI_PROFIL")){
            // printf("%s\n",cmd[0].TabWord);
            ubahProfil();
        }
        if (isEqualWordStr(cmd[0], "LIHAT_PROFIL")){
            // printWord(cmd[0]);
            // printWord(cmd[1]);
            // note: cmd[1] adalah Word nama
            lihatProfile(cmd[1]);
        }
        if (isEqualWordStr(cmd[0], "ATUR_JENIS_AKUN")){
            // printf("%s\n",cmd[0].TabWord);
            ubahJenisAkun();
        }
        if (isEqualWordStr(cmd[0], "UBAH_FOTO_PROFIL")){
            // printf("%s\n",cmd[0].TabWord);
            ubahFotoProfil();
        }
        if (isEqualWordStr(cmd[0], "DAFTAR_TEMAN")){
            // printf("%s\n",cmd[0].TabWord);
            SalinWord(getWord(CurrentUser),&temp);
            daftarTeman(DataTeman, temp);
        }
        if (isEqualWordStr(cmd[0], "HAPUS_TEMAN")){
            // printf("%s\n",cmd[0].TabWord);
            SalinWord(getWord(CurrentUser),&temp);
            hapusTeman(&DataTeman, temp);
        }
        if (isEqualWordStr(cmd[0], "TAMBAH_TEMAN")){
            // printf("%s\n",cmd[0].TabWord);
            SalinWord(getWord(CurrentUser),&temp);
            sentReq(temp, &DataTeman);
        }
        if (isEqualWordStr(cmd[0], "DAFTAR_PERMINTAAN_PERTEMANAN")){
            // printf("%s\n",cmd[0].TabWord);
            SalinWord(getWord(CurrentUser),&temp);
            printRequest(temp);
        }
        if (isEqualWordStr(cmd[0], "SETUJUI_PERMINTAAN")){
            // printf("%s\n",cmd[0].TabWord);
            SalinWord(getWord(CurrentUser),&temp);
            acceptRequest(&DataTeman, temp);
        }
        if (isEqualWordStr(cmd[0], "KICAU")){
            // printf("%s\n",cmd[0].TabWord);
            CreateTweet();
        }
        if (isEqualWordStr(cmd[0], "KICAUAN")){
            // printf("%s\n",cmd[0].TabWord);
            ShowTweets();
        }
        if (isEqualWordStr(cmd[0], "SUKA_KICAUAN")){
            // printf("%s\n",cmd[0].TabWord);
            // printf("%s\n",cmd[1].TabWord);
            LikeTweet(wordToInt(cmd[1]));
        }
        if (isEqualWordStr(cmd[0], "UBAH_KICAUAN")){
            // printf("%s\n",cmd[0].TabWord);
            // printf("%s\n",cmd[1].TabWord);
            UpdateTweet(wordToInt(cmd[1]));
        }
        if (isEqualWordStr(cmd[0], "BALAS")){
            printf("%s\n",cmd[0].TabWord);
            printf("%s\n",cmd[1].TabWord);
            printf("%s\n",cmd[2].TabWord);
            //  balas(wordToInt(cmd[1]), wordToInt(cmd[2]));
        }
        if (isEqualWordStr(cmd[0], "BALASAN")){
            printf("%s\n",cmd[0].TabWord);
            printf("%s\n",cmd[1].TabWord);
            Balasan balasan;
            // CreateReply(&balasan,)
            // if (cmd[1].TabWord[0] - '0' == -1){
            //     AddReplyToTweet(&dataBalasan,&balasan,cmd[0].TabWord);
            // } else {
            //     AddReplyToReply(&dataBalasan, &balasan,cmd[1].TabWord);
            // }
        }
        if (isEqualWordStr(cmd[0], "HAPUS_BALASAN")){
            printf("%s\n",cmd[0].TabWord);
            printf("%s\n",cmd[1].TabWord);
            printf("%s\n",cmd[2].TabWord);
            //  hapusBalasan(wordToInt(cmd[1]), wordToInt(cmd[2]));
        }
        if (isEqualWordStr(cmd[0], "BUAT_DRAF")){
            // printf("%s\n",cmd[0].TabWord);
            CreateDraft();
            
        }
        if (isEqualWordStr(cmd[0], "LIHAT_DRAF")){
            // printf("%s\n",cmd[0].TabWord);
            ViewLastDraft();
        }
        if (isEqualWordStr(cmd[0], "UTAS")){
            // printf("%s\n",cmd[0].TabWord);
            // printf("%s\n",cmd[1].TabWord);
            UTAS(wordToInt(cmd[1]));
        }
        if (isEqualWordStr(cmd[0], "SAMBUNG_UTAS")){
            // printf("%s\n",cmd[0].TabWord);
            // printf("%s\n",cmd[1].TabWord);
            // printf("%s\n",cmd[2].TabWord);
            sambungUtas(wordToInt(cmd[1]), wordToInt(cmd[2]));
        }
        if (isEqualWordStr(cmd[0], "HAPUS_UTAS")){
            // printf("%s\n",cmd[0].TabWord);
            // printf("%s\n",cmd[1].TabWord);
            // printf("%s\n",cmd[2].TabWord);
            hapusUtas(wordToInt(cmd[1]), wordToInt(cmd[2]));
        }
        if (isEqualWordStr(cmd[0], "CETAK_UTAS")){
            // printf("%s\n",cmd[0].TabWord);
            // printf("%s\n",cmd[1].TabWord);
            cetakUtas(wordToInt(cmd[1]));
        }
    }
    if (isEqualWordStr(cmd[0], "SIMPAN")){
        printf("%s\n",cmd[0].TabWord);
        simpan();
    }
    if (isEqualWordStr(cmd[0], "MUAT")){
        // printf("%s\n",cmd[0].TabWord);
        muat();
    }
}
// void bacaPerintah(Word* cmd){
//     // printPerintah(cmd[0]);
//     // if (cmd[1].Length != 0) printPerintah(cmd[1]);
//     // if (cmd[2].Length != 0) printPerintah(cmd[2]);
//     // printf("\n");
//     // if (cmd[1].Length != 0) printf("%d\n", wordToInt(cmd[1]));
//     // if (cmd[2].Length != 0) printf("%d\n", wordToInt(cmd[2]));
//     if (HURUF(cmd[0],0) == 'A'){
//         // ATUR_JENIS_AKUN
//         aturJenisAkun();

//     } else if (HURUF(cmd[0],0) == 'B'){
//         if (HURUF(cmd[0],1) == 'U'){
//             // BUAT_DRAF
//             buatDraf();
//         } else if (HURUF(cmd[0],1) == 'A'){
//             if (HURUF(cmd[0],2) == 'T'){
//                 // BATAL_TAMBAH_TEMAN 
//                 batalTambahTeman();   
//             } else if (HURUF(cmd[0],2) == 'L'){
//                 if (HURUF(cmd[0],5) == 'A'){
//                     // BALASAN [IDKICAU]
//                     balasan(wordToInt(cmd[1]));
//                 } else if (cmd[0].Length == 5) {
//                     // BALAS [IDKICAU] [IDBALASAN]
//                     balas(wordToInt(cmd[1]), wordToInt(cmd[2]));
//                 }
//             }
//         }

//     } else if (HURUF(cmd[0],0) == 'C'){
//         // CETAK_UTAS [IDKICAU]
//         cetakUtas(wordToInt(cmd[1]));
        
//     } else if (HURUF(cmd[0],0) == 'D'){
//         if (cmd[0].Length == 6){
//             // DAFTAR
//             daftar();
//         } else {
//             if (HURUF(cmd[0],7) == 'P'){
//                 // DAFTAR_PERMINTAAN_PERTEMANAN 
//                 daftarPermintaanPertemanan();
//             } else if (HURUF(cmd[0],7) == 'T'){
//                 // DAFTAR_TEMAN
//                 daftarTeman();
//             }
//         }
        
//     } else if (HURUF(cmd[0],0) == 'G'){
//         // GANTI_PROFIL
//         gantiProfil();
        
//     } else if (HURUF(cmd[0],0) == 'H'){
//         if (HURUF(cmd[0],6) == 'B'){
//             // HAPUS_BALASAN [IDKICAU] [IDBALASAN]
//             hapusBalasan(wordToInt(cmd[1]), wordToInt(cmd[2]));

//         } else if (HURUF(cmd[0],6) == 'T') {
//             // HAPUS_TEMAN
//             hapusTeman();

//         } else if (HURUF(cmd[0],6) == 'U') {
//             // HAPUS_UTAS [IDUTAS] [INDEX]
//             hapusUtas(wordToInt(cmd[1]), wordToInt(cmd[2]));
//         }
        
//     } else if (HURUF(cmd[0],0) == 'L'){
//         if (HURUF(cmd[0],6) == 'D') {
//             // LIHAT_DRAF
//             lihatDraf();
//         } else if (HURUF(cmd[0],6) == 'b') {
//             // LIHAT_PROFIL [NAMA] 
//             lihatProfil(cmd[1]);
//         } else if (HURUF(cmd[0],1) == 'O'){
//             // LOAD
//             load(cmd[1]);
//         }
        
//     } else if (HURUF(cmd[0],0) == 'K'){
//         if (HURUF(cmd[0],1) == 'E') {
//             // KELUAR
//             keluar();
//         } else if (HURUF(cmd[0],2) == 'I'){
//             if (cmd[0].Length == 5){
//                 // KICAU
//                 kicau();
//             } else if (cmd[0].Length == 7){
//                 // KICAUAN
//                 kicauan();
//             }
//         }
        
//     } else if (HURUF(cmd[0],0) == 'M'){
//         if (HURUF(cmd[0],1) == 'A') {
//             // MASUK
//             masuk();
//         } else if (HURUF(cmd[0],1) == 'U') {
//             // MUAT
//             muat();
//         }
        
//     } else if (HURUF(cmd[0],0) == 'S'){
//         if (HURUF(cmd[0],1) == 'A') {
//             // SAMBUNG_UTAS [IDUTAS] [INDEX]
//             sambungUtas(wordToInt(cmd[1]), wordToInt(cmd[2]));
//         } else if (HURUF(cmd[0],1) == 'E') {
//             // SETUJUI_PERTEMANAN
//             setujuiPertemanan();
//         } else if (HURUF(cmd[0],1) == 'I') {
//             // SIMPAN
//             simpan();
//         } else if (HURUF(cmd[0],1) == 'U') {
//             // SUKA_KICAUAN [IDKICAU]
//             sukaKicauan(wordToInt(cmd[1]));
//         }
        
//     } else if (HURUF(cmd[0],0) == 'T'){
//         if (HURUF(cmd[0],1) == 'A') {
//             // TAMBAH_TEMAN
//             tambahTeman();
//         } else if (HURUF(cmd[0],1) == 'U') {
//             // TUTUP_PROGRAM
//             // TutupProgram();
//             endProgram = true;
//         }
        
//     } else if (HURUF(cmd[0],0) == 'U'){
//         if (HURUF(cmd[0],1) == 'T') {
//             // UTAS [IDKICAU]
//             utas(wordToInt(cmd[1]));
//         } else if (HURUF(cmd[0],1) == 'B') {
//             if (HURUF(cmd[0],5) == 'F') {
//                 // UBAH_FOTO_PROFILE
//                 ubahFotoProfile();
//             } else if (HURUF(cmd[0],5) == 'K') {
//                 // UBAH_KICAUAN [IDKICAU]
//                 ubahKicauan(wordToInt(cmd[1]));
//             }
//         }
//     }
// }
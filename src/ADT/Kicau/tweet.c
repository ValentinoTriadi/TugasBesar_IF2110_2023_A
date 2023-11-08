/* File : tweet.c */

#include <stdio.h>
#include "wordmachine.h"
#include "datetime.h"
#include "tweet.h"

extern Word currentSentence;
extern Word CurrentUser;

boolean IsKicauValid(Word textKicauan) {
    return textKicauan.Length > 0 && textKicauan.Length <= 280;
}

void kicau(ListKicau *listKicau, Word CurrentUser) {
    Word textKicauan;
    STARTINPUT();
    CopyInput(&textKicauan);
    
    if (IsKicauValid(textKicauan)) {
        DATETIME currentDatetime = getLocalTime();
        Kicauan newKicauan;
        newKicauan.id = listKicau->nEff + 1;
        newKicauan.text = textKicauan;
        newKicauan.like = 0;
        newKicauan.author = CurrentUser;
        newKicauan.datetime = currentDatetime;
        
        listKicau->nEff++;
        if (listKicau->nEff > listKicau->capacity) {
            // Kalo kapasitas penuh, realokasi memori(?)
            listKicau->capacity *= 2;
            listKicau->kicau = (Kicauan*)realloc(listKicau->kicau, sizeof(Kicauan) * listKicau->capacity);
        }
        
        listKicau->kicau[listKicau->nEff - 1] = newKicauan;
        
        printf("Selamat! Kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        printf("| ID = %d\n", newKicauan.id);
        printf("| ");
        printWord(CurrentUser);
        printf("| ");
        TulisDATETIME(newKicauan.datetime);
        printf("\n| ");
        printWord(newKicauan.text);
        printf("\n| Disukai: %d\n", newKicauan.like);
    } else {
        printf("Kicauan tidak boleh kosong atau melebihi 280 karakter!\n");
    }
}

void kicauan(ListKicau listKicau, Word CurrentUser) {
    printf(">>\n");
    printf("Pengguna saat ini: ");
    printWord(CurrentUser);
    printf("\n\n");
    
    for (int i = listKicau.nEff - 1; i >= 0; i--) {
        Kicauan kicauan = listKicau.kicau[i];
        
        printf("| ID = %d\n", kicauan.id);
        printf("| ");
        printWord(kicauan.author);
        printf("| ");
        TulisDATETIME(kicauan.datetime);
        printf("\n| ");
        printWord(kicauan.text);
        printf("\n| Disukai: %d\n\n", kicauan.like);
    }
}

void ubah_kicauan(ListKicau *listKicau, Word CurrentUser, int id) {
    int kicauanIndex = -1;
    for (int i = 0; i < listKicau->nEff; i++) {
        if (listKicau->kicau[i].id == id) {
            kicauanIndex = i;
            break;
        }
    }
    
    if (kicauanIndex != -1) {
        Kicauan *kicauan = &listKicau->kicau[kicauanIndex];
        
        if (isEqualWordWord(kicauan->author, CurrentUser)) {
            Word updatedText;
            printf("Masukkan kicauan baru:\n");
            STARTINPUT();
            CopyInput(&updatedText);
            
            if (IsKicauValid(updatedText)) {
                kicauan->text = updatedText;
                printf("Selamat! Kicauan telah diubah!\n");
                printf("Detil kicauan:\n");
                printf("| ID = %d\n", kicauan->id);
                printf("| ");
                printWord(CurrentUser);
                printf("| ");
                TulisDATETIME(kicauan->datetime);
                printf("\n| ");
                printWord(kicauan->text);
                printf("\n| Disukai: %d\n", kicauan->like);
            } else {
                printf("Kicauan tidak boleh kosong atau melebihi 280 karakter!\n");
            }
        } else {
            printf("Kicauan dengan ID = %d bukan milikmu!\n", id);
        }
    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", id);
    }
}

void suka_kicauan(ListKicau *listKicau, Word CurrentUser, int id) {
    int kicauanIndex = -1;
    for (int i = 0; i < listKicau->nEff; i++) {
        if (listKicau->kicau[i].id == id) {
            kicauanIndex = i;
            break;
        }
    }
    
    if (kicauanIndex != -1) {
        Kicauan *kicauan = &listKicau->kicau[kicauanIndex];
        
        if (!isEqualWordWord(kicauan->author, CurrentUser)) {
            kicauan->like++;
            printf("Kicauan dengan ID = %d telah disukai!\n", id);
            printf("Detil kicauan:\n");
            printf("| ID = %d\n", kicauan->id);
            printf("| ");
            printWord(kicauan->author);
            printf("| ");
            TulisDATETIME(kicauan->datetime);
            printf("\n| ");
            printWord(kicauan->text);
            printf("\n| Disukai: %d\n", kicauan->like);
        } else {
            printf("Kicauan dengan ID = %d adalah milikmu, kamu tidak bisa menyukainya!\n", id);
        }
    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", id);
    }
}
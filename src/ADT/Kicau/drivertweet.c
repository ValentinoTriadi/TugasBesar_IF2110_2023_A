#include "tweet.h"

int main() {
    ListKicau listKicau;
    CreateListKicau(&listKicau, 100); // Misalnya, kapasitas list kicauan adalah 100

    // Pengguna saat ini (contoh: John Doe)
    Word currentUser = StrToWord("John Doe");

    printf("Selamat datang di BurBir!\n");

    while (1) {
        printf("\nPerintah:\n");

        // Membaca perintah dari pengguna
        STARTINPUT();
        ADVSENTENCEWITHNL();
        if (isEqualWordStr(currentSentence, "KICAU")) {
            // Perintah KICAU
            inputKicau(listKicau);
        } else if (isEqualWordStr(currentSentence, "KICAUAN")) {
            // Perintah KICAUAN
            DisplayKicauan(listKicau);
        } else if (isEqualWordStr(currentSentence, "SUKA_KICAUAN")) {
            // Perintah SUKA_KICAUAN
            STARTSENTENCEWITHNL(stdin);
            ADVSENTENCEWITHNL();

            int idKicau = wordToInt(currentSentence);

            if (idKicau <= listKicau.nEff) {
                sukaKicauan(idKicau, listKicau);
                printf("Selamat! Kicauan telah disukai!\nDetil kicauan:\n");
                printDataKicauan(KELMT(listKicau, idKicau - 1));
            } else {
                printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicau);
            }
        } else if (isEqualWordStr(currentSentence, "UBAH_KICAUAN")) {
            // Perintah UBAH_KICAUAN
            STARTSENTENCEWITHNL(stdin);
            ADVSENTENCEWITHNL();

            int idKicau = wordToInt(currentSentence);

            if (idKicau <= listKicau.nEff) {
                // Memeriksa apakah kicauan ini milik pengguna saat ini
                if (isEqualWordWord(KAUTH(KELMT(listKicau, idKicau - 1)), currentUser)) {
                    printf("Masukkan kicauan baru:\n");

                    // Membaca kicauan yang baru
                    STARTSENTENCEWITHNL(stdin);
                    ADVSENTENCEWITHNL();

                    Kicauan *kicauToUpdate = &KELMT(listKicau, idKicau - 1);
                    CopySentenceWithNL();
                    strcpy(kicauToUpdate->text, currentSentence.TabWord);

                    printf("Selamat! Kicauan telah diterbitkan!\nDetil kicauan:\n");
                    printDataKicauan(*kicauToUpdate);
                } else {
                    printf("Kicauan dengan ID = %d bukan milikmu!\n", idKicau);
                }
            } else {
                printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicau);
            }
        } else {
            printf("Perintah tidak valid. Coba lagi.\n");
        }
    }

    return 0;
}
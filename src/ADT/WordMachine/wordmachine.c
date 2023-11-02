#include "wordmachine.h"
#include "../CharMachine/charmachine.c"


boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */

    /* Algoritma */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */

    /* Algoritma */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        currentWord.Length = 0;
        ADVWORD();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */

    /* Algoritma */
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

    /* Algoritma */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        {
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
        }
        ADV();
    }
    currentWord.TabWord[currentWord.Length] = '\0'; // Menambahkan null-terminator
}

// Tambahan Primitif
int wordToInt(Word x){
    int result = 0;
    int sign = 1;
    int i = 0;
    if (HURUF(x,0) == '-'){
        sign = -1;
        i++;
    }
    for (i; i<x.Length; i++){
        result = result*10 + charToInt(HURUF(x,i));
    }
    return result * sign;
}


boolean isEqualWord(Word w1, Word w2) {
    if (w1.Length != w2.Length) {
        return false;
    } else {
        for (int i = 0; i < w1.Length; i++) {
            if (w1.TabWord[i] != w2.TabWord[i]) {
                return false;
            }
        }
    }
    return true;
}

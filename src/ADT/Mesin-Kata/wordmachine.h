/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "../Mesin-Char/charmachine.h"


#define NMax 4999
#define BLANK ' '
#define NEWLINE '\n'
#define HURUF(w,i) (w).TabWord[(i)]

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern boolean EndSentence;
extern Word currentWord;
extern Word currentSentence;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreNL();
/* Mengabaikan satu atau beberapa NewLine
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ NewLine atau currentChar = MARK */
void Ignore1NL();
// baca per kata
void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

// buka file
void READFILE(char* filename);

// baca kalimat
void STARTSENTENCE();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVSENTENCE();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */


void CopySentence();
/* Mengakuisisi kalimat, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kalimat
   F.S. : currentWord berisi kalimat yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kalimat melebihi NMax, maka sisa kalimat "dipotong" */

void STARTSENTENCEWITHNL(char* filename);

void ADVSENTENCEWITHNL();

void CopySentenceWithNL();

void STARTINPUT();

void CopyInput();
/* Mengakuisisi kalimat, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kalimat
   F.S. : currentWord berisi kalimat yang sudah diakuisisi;
          currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kalimat melebihi NMax, maka sisa kalimat "dipotong" */

int wordToInt(Word x);
/* Mengembalikan Word angka dalam bentuk integer */

void splitSentence(Word Sentence, Word * l, int len);
/* Mengembalikan array of Word dengan pemisah BLANK */

Word toLowerCase(Word Sentence);
/* Mengembalikan Word dengan lower case */

void printWord(Word s);

int Strlen(char * ss);

boolean isEqualWordStr(Word s, char * ss);

boolean isEqualWordWord(Word s1, Word s2);

Word StrToWord(char *str);
#endif
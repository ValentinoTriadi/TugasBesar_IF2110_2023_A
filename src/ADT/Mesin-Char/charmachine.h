/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __CHAR_MACHINE_H__
#define __CHAR_MACHINE_H__

#include "../boolean.h"
#include <stdio.h>

#define MARK ';'
#define MARKLINE '\n'
#define MARKFILE EOF

extern char currentChar;
extern boolean EOP;


/* State Mesin */
void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
void STARTFILE(char* filename);
/* Membaca pita dari sebuah file */

void CLOSEFILE();

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

int charToInt(char x);
/* Mengembalikan Char angka dalam bentuk integer */

int countChar(char* l, int len, char x);
/* Mengembalikan jumlah char yang muncul dalam sebuah string */


#endif
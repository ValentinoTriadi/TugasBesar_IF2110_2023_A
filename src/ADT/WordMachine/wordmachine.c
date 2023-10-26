#include "wordmachine.h"
#include "../CharMachine/charmachine.c"

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK || currentChar == '\n'){
        ADV();
    }
}
void STARTWORD(){
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }

}
void ADVWORD(){
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    } else{
        CopyWord();
        IgnoreBlanks();
    }

}
void CopyWord(){
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentChar != '\n'){
        if (currentWord.Length < NMax){
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
        }
        ADV();
    }
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
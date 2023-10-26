#include "wordmachine.h"
#include "./../CharMachine/charmachine.c"

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK){
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
    while (currentChar != BLANK && currentChar != MARK){
        if (currentWord.Length < NMax){
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
        }
        ADV();
    }
}
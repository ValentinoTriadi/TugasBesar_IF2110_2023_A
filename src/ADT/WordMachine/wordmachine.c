#include "wordmachine.h"
#include "../CharMachine/charmachine.c"

/* State Mesin Word */
boolean EndWord;
boolean EndSentence;
Word currentWord;
Word currentSentence  ;

void IgnoreBlanks(){
    while (currentChar == BLANK){
        ADV();
    }
}
void IgnoreNL(){
    while (currentChar == NEWLINE){
        ADV();
    }
}
void STARTWORD(){
    START();
    IgnoreBlanks();
    IgnoreNL();
    if (currentChar == MARK){
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}
void ADVWORD(){
    IgnoreBlanks();
    IgnoreNL();
    if(currentChar == MARK ){
        EndWord = true;
    } else{
        CopyWord();
        IgnoreBlanks();
        IgnoreNL();
    }
}
void CopyWord(){
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentChar != NEWLINE){
        if (currentWord.Length < NMax){
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
        }
        ADV();
    }
}
void READFILE(){
    START();
    IgnoreNL();
    if (currentChar == MARKFILE){
        EndSentence = true;
    } else {
        EndSentence = false;
        CopySentence();
    }
}
void STARTSENTENCE(){
    START();
    IgnoreNL();
    if (currentChar == MARKFILE){
        EndSentence = true;
    } else {
        EndSentence = false;
        CopySentence();
    }
}
void ADVSENTENCE(){
    IgnoreNL();
    if(currentChar == MARKFILE){
        EndSentence = true;
    } else{
        CopySentence();
        IgnoreNL();
    }
}
void CopySentence(){
    currentSentence.Length = 0;
    while (currentChar != MARKLINE && currentChar != MARKFILE){
        if (currentSentence.Length < NMax){
            currentSentence.TabWord[currentSentence.Length] = currentChar;
            currentSentence.Length++;
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
void splitSentence(Word Sentence, Word * l, int len){
    // requirement
    /*
        int countWord = countChar(s.TabWord, s.Length, ' ') + 1;
        Word l[countWord];
        splitSentence(s, l, countWord);
    */
    Word temp;
    temp.Length = 0;
    int iS, iW = 0, idx = 0;
    for (iS = 0; iS < Sentence.Length; iS++){
        if (HURUF(Sentence,iS) != BLANK){
            HURUF(temp, iW) = HURUF(Sentence,iS);
            iW++;
            temp.Length++;
        } else {
            l[idx] = temp;
            idx++;
            iW = 0;
            temp.Length = 0;
        }
    }
    l[idx] = temp;
}

Word toLowerCase(Word weton){
    Word s;
    s.Length = 0;
    int idx = 0;
    for (int i = 0; i < weton.Length; i++){
        int p = (int) HURUF(weton, idx);
        char c;
        if (p <= 90){
            p += 32;
            c = p;
        }
        s.Length++;
        HURUF(s,idx) = (char) p;
        idx++;
    }
    return s;
}

void printWord(Word s){
    for(int i = 0; i < s.Length; i++){
        printf("%c", HURUF(s,i));
    }
    printf("\n");
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

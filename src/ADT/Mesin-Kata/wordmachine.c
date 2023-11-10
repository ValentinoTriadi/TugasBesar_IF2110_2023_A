#include "wordmachine.h"
#include <stdio.h>

/* State Mesin Word */
boolean EndWord;
boolean EndSentence;
Word currentWord;
Word currentSentence;

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
void READFILE(char* filename){
    STARTFILE(filename);
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

void STARTSENTENCEWITHNL(char* filename){
    STARTFILE(filename);
    if (currentChar == MARK){
        EndSentence = true;
        CLOSEFILE();       
    } else {
        EndSentence = false;
        CopySentenceWithNL();
    }
}
void ADVSENTENCEWITHNL(){
    if(currentChar == MARK){
        EndSentence = true;
    } else{
        CopySentenceWithNL();
    }
}
void CopySentenceWithNL(){
    currentSentence.Length = 0;
    while (currentChar != MARK){
        if (currentSentence.Length < NMax){
            currentSentence.TabWord[currentSentence.Length] = currentChar;
            currentSentence.Length++;
        }
        ADV();
    }   
}

void STARTINPUT(){
    START();
    IgnoreNL();
    if (currentChar == MARK){
        EndSentence = true;
    } else {
        EndSentence = false;
        CopyInput();
    }
}

void CopyInput(){
    currentSentence.Length = 0;
    while (currentChar != MARK){
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

int Strlen(char * ss){
    int count = 0;
    
    while (ss[count] != '\0'){
        count++;
    }

    return count;
}

boolean isEqualWordStr(Word s, char * ss){
    int len = Strlen(ss);
    if (len != s.Length) return false;
    for (int i = 0; i < s.Length; i++){
        if(HURUF(s,i) != ss[i]) return false;
    }
    return true;
}
boolean isEqualWordWord(Word s1, Word s2){
    if (s1.Length != s2.Length) return false;
    for (int i = 0; i < s1.Length; i++){
        if(HURUF(s1,i) != HURUF(s2,i)) return false;
    }
    return true;
}

Word StrToWord(char *str)
{
    Word w;
    w.Length = Strlen(str);
    for (int i = 0; i < w.Length; i++)
    {
        w.TabWord[i] = str[i];
    }
    return w;
}



#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

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
    while (currentChar == NEWLINE || currentChar == '\r'){
        ADV();
    }
}
void Ignore1NL(){
    if (currentChar == NEWLINE || currentChar == '\r'){
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
    if (currentChar == EOF){
        EndSentence = true;
    } else {
        EndSentence = false;
        CopyFile();
    }
}
void ADVSENTENCEFILE(){
    Ignore1NL();
    // printf("%c\n", currentChar);
    if(currentChar == EOF){
        EndSentence = true;
        CLOSEFILE();
    } else{
        CopyFile();
    }
}
void CopyFile(){
    currentSentence.Length = 0;
    while ((currentChar != NEWLINE) && (currentChar != EOF)){
        if (currentSentence.Length < NMax){
            currentSentence.TabWord[currentSentence.Length] = currentChar;
            currentSentence.Length++;
        }
        ADVFILE();
    }
    currentSentence.TabWord[currentSentence.Length] = '\0';
    currentSentence.Length--;
}


void STARTSENTENCE(){
    START();
    Ignore1NL();
    if (currentChar == MARKFILE){
        EndSentence = true;
    } else {
        EndSentence = false;
        CopySentence();
    }
}
void ADVSENTENCE(){
    Ignore1NL();
    if(currentChar == MARKFILE){
        EndSentence = true;
    } else{
        CopySentence();
        Ignore1NL();
    }
}
void CopySentence(){
    currentSentence.Length = 0;
    while ((currentChar != MARKLINE && currentChar != '\r') && (currentChar != MARKFILE && currentChar != MARK)){
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

Word toLowerCase(Word kata){
    Word s = kata;
    for (int i = 0; i < s.Length; i++){
        int p = (int) HURUF(s, i);
        if (p <= 90) p += 32;
        HURUF(s,i) = (char) p;
    }
    return s;
}

void printWord(Word s){
    for(int i = 0; i < s.Length; i++){
        printf("%c", HURUF(s,i));
    }
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

void SalinWord(Word source, Word *destination) {
    int i;
    for (i = 0; i < source.Length && i < NMax; i++) {
        destination->TabWord[i] = source.TabWord[i];
    }
    destination->Length = i;

    destination->TabWord[i] = '\0';
}

DATETIME wordToDatetime(Word w){
    DATETIME d;
    int i;
    int j = 0;
    int temp = 0;
    while(w.TabWord[j] != '/'){
        temp = (charToInt(w.TabWord[j]) + temp*10);
        j++;
    }
    j++;
    d.DD = temp;
    temp = 0;
    while(w.TabWord[j] != '/'){
        temp = charToInt(w.TabWord[j]) + temp*10;
        j++;
    }
    j++;
    d.MM = temp;
    temp = 0;
    while(w.TabWord[j] != ' '){
        temp = charToInt(w.TabWord[j]) + temp*10;
        j++;
    }
    j++;
    d.YYYY = temp;
    temp = 0;
    while(w.TabWord[j] != ':'){
        temp = charToInt(w.TabWord[j]) + temp*10;
        j++;
    }
    j++;
    d.T.HH = temp;
    temp = 0;
    while(w.TabWord[j] != ':'){
        temp = charToInt(w.TabWord[j]) + temp*10;
        j++;
    }
    j++;
    d.T.MM = temp;
    temp = 0;
    while(j < w.Length){
        temp = charToInt(w.TabWord[j]) + temp*10;
        j++;
    }
    d.T.SS = temp;
    return d;
}

int findIdxLastSpace(Word w){
    int found = 0;
    for (int i = 0; i < w.Length; i++){
        if (w.TabWord[i] == ' ') found = i;
    }
    return found;
}

Word getWordBeforeIdx (Word w, int idx){
    Word new;
    new.Length = idx;
    for (int i = 0; i < idx; i++){
        new.TabWord[i] = w.TabWord[i];
    } 
    return new;
}
Word getWordAfterIdx (Word w, int idx){
    Word new;
    new.Length = (w.Length - idx)-1;
    for (int i = 0; i < w.Length; i++){
        new.TabWord[i] = w.TabWord[i+idx+1];
    } 
    return new;
}
char* wordToStr (Word w){
    char* str = malloc((w.Length + 1) * sizeof(char));
    for(int i = 0; i < w.Length; i++){
        str[i] = w.TabWord[i];
    }
    str[w.Length] = '\0';
    return str;
}
#include "wordmachine.h"
#include <stdio.h>


int main(){
    READFILE("ADT/Mesin-Kata/bro.config");
    Word temp = currentSentence;
    printWord(temp);
    printf("\n");
    // printf("\n----------------1----------------\n");
    ADVSENTENCEFILE();
    temp = currentSentence;
    printWord(temp);
    printf("\n");
    // printf("\n-----------------2---------------\n");
    ADVSENTENCEFILE();
    temp = currentSentence;
    printWord(temp);
    printf("\n");
    // printf("\n-----------------3---------------\n");
    ADVSENTENCEFILE();
    temp = currentSentence;
    printWord(temp);
    printf("\n");
    // printf("\n----------------4----------------\n");
    ADVSENTENCEFILE();
    temp = currentSentence;
    printWord(temp);
    printf("\n");
    // printf("\n-------------------5-------------\n");
    ADVSENTENCEFILE();
    temp = currentSentence;
    printWord(temp);
    printf("\n");
    // printf("\n----------------6----------------\n");
    ADVSENTENCEFILE();
    temp = currentSentence;
    printWord(temp);
    printf("\n");
    // printf("\n----------------7----------------\n");

    return 0;
}
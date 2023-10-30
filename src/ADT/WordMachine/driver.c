#include "wordmachine.c"
#include <stdio.h>

int main(){
    Word s;
    s.Length = 9;
    HURUF(s,0) = 'P';
    HURUF(s,1) = 'o';
    HURUF(s,2) = 'N';
    HURUF(s,3) = ' ';
    HURUF(s,4) = 'N';
    HURUF(s,5) = 'N';
    HURUF(s,6) = ' ';
    HURUF(s,7) = 'A';
    HURUF(s,8) = 'N';
    HURUF(s,9) = '\n';
    int countWord = countChar(s.TabWord, s.Length, ' ') + 1;
    Word l[countWord];
    splitSentence(s, l, countWord);
    printWord(l[0]);
    printWord(l[1]);
    printWord(l[2]);

    return 0;
}

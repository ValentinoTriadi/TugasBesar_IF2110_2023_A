#include "user.c"

int main(){
    int i = 0;

    while (i<5){
        STARTWORD();
    ADVWORD();
    CopyWord();
    printWord(currentWord);
        i++;
    }

    return 0;
}
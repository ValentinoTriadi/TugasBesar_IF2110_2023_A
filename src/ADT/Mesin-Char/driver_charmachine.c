#include "charmachine.h"
extern char currentChar;


int main() {
    int n;
    scanf("%d", &n);

    switch (n) {
        case 1: // charToInt
            char numChar = '5';
            printf("\nThe integer value of '%c' is %d\n\n", numChar, charToInt(numChar));
            break;
        case 2: // countChar
            char testStr[] = "This is a test string ttt.";
            char countTarget = 't';
            int count = countChar(testStr, sizeof(testStr) - 1, countTarget);
            printf("The character '%c' appears %d times in \"%s\"\n", countTarget, count, testStr);
            break;
        case 3:
            char* filename = "input.txt";
            STARTFILE(filename);
            while ((int) currentChar != MARKFILE){
                printf("%c",currentChar);
                ADV();
            }
            CLOSEFILE();
            break;
        
        default:
            break;
    }
    return 0;
}
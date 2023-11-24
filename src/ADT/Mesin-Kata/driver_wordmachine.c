#include "wordmachine.h"
#include <stdio.h>

int main() {
    char filename[] = "example.txt"; // Assume this is a valid file path
    Word sentence;
    int choice;
    boolean running = true;

    printf("Word Machine Driver\n");

    while (running) {
        printf("\nMenu:\n");
        printf("1. Read Word from Standard Input\n");
        printf("2. Read Sentence from Standard Input\n");
        printf("3. Read from File\n");
        printf("4. Convert Word to Integer\n");
        printf("5. Convert Word to Lowercase\n");
        printf("6. Compare Word with String\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                STARTWORD();
                while (!EndWord) {
                    printWord(currentWord);
                    printf("\n");
                    ADVWORD();
                }
                break;
            case 2:
                STARTINPUT();
                printWord(currentSentence);
                break;
            case 3:
                READFILE(filename);
                while (!EndSentence) {
                    printWord(currentSentence);
                    ADVSENTENCEWITHNL();
                }
                break;
            case 4:
                printf("Enter a word to convert to integer: ");
                STARTWORD();
                printf("Integer: %d\n", wordToInt(currentWord));
                break;
            case 5:
                printf("Enter a word to convert to lowercase: ");
                STARTWORD();
                sentence = toLowerCase(currentWord);
                printWord(sentence);
                printf("\n");
                break;
            case 6:
                printf("Enter a word and string to compare: ");
                STARTWORD();
                char str[NMax];
                scanf("%s", str); // Read a string to compare with the word
                if (isEqualWordStr(currentWord, str)) {
                    printf("The word and string are equal.\n");
                } else {
                    printf("The word and string are not equal.\n");
                }
                break;
            case 7:
                running = false;
                break;
            default:
                printf("Invalid option selected. Please choose between 1 and 7.\n");
                break;
        }
    }

    return 0;
}

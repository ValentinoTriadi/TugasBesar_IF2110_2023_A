// #include "charmachine.h"
// extern char currentChar;


// int main() {
//     int choice;
//     char numChar = '5';
//     char testStr[] = "This is a test string ttt.";
//     char countTarget = 't';
//     int count = countChar(testStr, sizeof(testStr) - 1, countTarget);
//     char* filename = "input.txt";

//     do {
//         printf("\n");
//         printf("1. Char to Int\n");
//         printf("2. Count Char\n");
//         printf("3. Read File\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1: // charToInt
//                 printf("\nThe integer value of '%c' is %d\n\n", numChar, charToInt(numChar));
//                 break;
//             case 2: // countChar
//                 printf("The character '%c' appears %d times in \"%s\"\n", countTarget, count, testStr);
//                 break;
//             case 3:
//                 STARTFILE(filename);
//                 while ((int) currentChar != MARKFILE){
//                     printf("%c",currentChar);
//                     ADV();
//                 }
//                 break;
            
//             case 4:
//                 printf("Exiting...\n");
//                 break;
//             default:
//                 printf("Invalid choice.\n");
//                 break;
//         } 
//     } while (choice != 4);
//     return 0;
// }
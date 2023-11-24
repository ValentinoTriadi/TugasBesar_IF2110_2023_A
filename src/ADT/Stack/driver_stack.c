#include "stack.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../Time/datetime.h"
#include <stdio.h>

int main() {
    Stack s;
    int choice;
    infotype draft;
    DATETIME timestamp;

    printf("Stack Operations\n");
    CreateEmpty(&s);

    do {
        printf("\n");
        printf("1. Push draft\n");
        printf("2. Pop draft\n");
        printf("3. Check if Stack is Empty\n");
        printf("4. Check if Stack is Full\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                if (!IsFull(s)) {
                    printf("Enter your text (end with a dot): ");
                    STARTINPUT(); 
                    if (!EndSentence) {
                        draft.text = currentSentence;
                        draft.timestamp = getLocalTime();
                        Push(&s, draft);
                        printf("Draft pushed to stack.\n");
                    } else {
                        printf("No text entered.\n");
                    }
                } else {
                    printf("Stack is full. Cannot push more drafts.\n");
                }
                break;
            case 2:
                if (!IsEmpty(s)) {
                    Pop(&s, &draft);
                    printf("Draft popped from stack:\n");
                    printWord(draft.text); // Assuming printWord is a function to display a Word.
                    TulisDATETIME(draft.timestamp);
                    printf("\n");
                } else {
                    printf("Stack is empty. Cannot pop drafts.\n");
                }
                break;
            case 3:
                if (IsEmpty(s)) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
                }
                break;
            case 4:
                if (IsFull(s)) {
                    printf("The stack is full.\n");
                } else {
                    printf("The stack is not full.\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
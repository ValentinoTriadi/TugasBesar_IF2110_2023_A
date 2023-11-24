#include "draf.h"
#include <stdio.h>

int main() {
    Stack drafts;
    int choice;
    Draft draft;

    CreateEmpty(&drafts);

    do {
        printf("\n");
        printf("Draft Management System\n");
        printf("1. Create New Draft\n");
        printf("2. View Last Draft\n");
        printf("3. Update Last Draft\n");
        printf("4. Delete Last Draft\n");
        printf("5. Publish Last Draft\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                CreateDraft();
                break;
            case 2:
                ViewLastDraft();
                break;
            case 3:
                UpdateDraft();
                break;
            case 4:
                DeleteDraft();
                break;
            case 5:
                PublishDraft();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

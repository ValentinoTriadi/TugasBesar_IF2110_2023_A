#include "adttime.h"
#include <stdio.h>

int main() {
    TIME t1, t2;
    int hh, mm, ss, duration;
    int choice;
    boolean running = true;

    while (running) {
        printf("\nTIME Operations\n");
        printf("1. Create TIME\n");
        printf("2. Read TIME\n");
        printf("3. Write TIME\n");
        printf("4. Add Seconds to TIME\n");
        printf("5. Subtract Seconds from TIME\n");
        printf("6. Compare Two Times\n");
        printf("7. Calculate Duration Between Two Times\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter hours, minutes, and seconds: ");
                scanf("%d %d %d", &hh, &mm, &ss);
                if (IsTIMEValid(hh, mm, ss)) {
                    CreateTime(&t1, hh, mm, ss);
                    printf("TIME created: ");
                    TulisTIME(t1);
                    printf("\n");
                } else {
                    printf("Invalid TIME entered.\n");
                }
                break;
            case 2:
                BacaTIME(&t1);
                break;
            case 3:
                TulisTIME(t1);
                printf("\n");
                break;
            case 4:
                printf("Enter seconds to add: ");
                scanf("%d", &duration);
                t1 = NextNDetik(t1, duration);
                printf("New TIME: ");
                TulisTIME(t1);
                printf("\n");
                break;
            case 5:
                printf("Enter seconds to subtract: ");
                scanf("%d", &duration);
                t1 = PrevNDetik(t1, duration);
                printf("New TIME: ");
                TulisTIME(t1);
                printf("\n");
                break;
            case 6:
                printf("Enter the second TIME for comparison (hours minutes seconds): ");
                scanf("%d %d %d", &hh, &mm, &ss);
                CreateTime(&t2, hh, mm, ss);
                if (TEQ(t1, t2)) {
                    printf("The times are equal.\n");
                } else {
                    printf("The times are not equal.\n");
                }
                break;
            case 7:
                printf("Enter the second TIME to calculate duration (hours minutes seconds): ");
                scanf("%d %d %d", &hh, &mm, &ss);
                CreateTime(&t2, hh, mm, ss);
                printf("Duration: %ld seconds\n", Durasi(t1, t2));
                break;
            case 8:
                running = false;
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    }

    return 0;
}
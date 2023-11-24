#include "datetime.h"
#include <stdio.h>

int main() {
    DATETIME dt1, dt2;
    int DD, MM, YYYY, hh, mm, ss, secondsToAdd;
    int choice;
    boolean running = true;

    while (running) {
        printf("\nDATETIME Operations\n");
        printf("1. Create DATETIME\n");
        printf("2. Read DATETIME\n");
        printf("3. Write DATETIME\n");
        printf("4. Add Seconds to DATETIME\n");
        printf("5. Subtract Seconds from DATETIME\n");
        printf("6. Compare Two DATETIMEs\n");
        printf("7. Calculate Duration Between Two DATETIMEs\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter day, month, year, hours, minutes, and seconds: ");
                scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
                if (IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)) {
                    CreateDATETIME(&dt1, DD, MM, YYYY, hh, mm, ss);
                    printf("DATETIME created: ");
                    TulisDATETIME(dt1);
                    printf("\n");
                } else {
                    printf("Invalid DATETIME entered.\n");
                }
                break;
            case 2:
                BacaDATETIME(&dt1);
                break;
            case 3:
                TulisDATETIME(dt1);
                printf("\n");
                break;
            case 4:
                printf("Enter seconds to add: ");
                scanf("%d", &secondsToAdd);
                dt1 = DATETIMENextNDetik(dt1, secondsToAdd);
                printf("New DATETIME: ");
                TulisDATETIME(dt1);
                printf("\n");
                break;
            case 5:
                printf("Enter seconds to subtract: ");
                scanf("%d", &secondsToAdd);
                dt1 = DATETIMEPrevNDetik(dt1, secondsToAdd);
                printf("New DATETIME: ");
                TulisDATETIME(dt1);
                printf("\n");
                break;
            case 6:
                printf("Enter the second DATETIME for comparison (DD MM YYYY HH MM SS): ");
                scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
                CreateDATETIME(&dt2, DD, MM, YYYY, hh, mm, ss);
                if (DEQ(dt1, dt2)) {
                    printf("The DATETIMEs are equal.\n");
                } else {
                    printf("The DATETIMEs are not equal.\n");
                }
                break;
            case 7:
                printf("Enter the second DATETIME to calculate duration (DD MM YYYY HH MM SS): ");
                scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
                CreateDATETIME(&dt2, DD, MM, YYYY, hh, mm, ss);
                printf("Duration: %ld seconds\n", DATETIMEDurasi(dt1, dt2));
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
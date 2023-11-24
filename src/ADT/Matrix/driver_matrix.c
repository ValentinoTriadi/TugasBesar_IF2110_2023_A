#include "matrix.h"
#include <stdio.h>

int main() {
    Matrix m;
    int choice;
    int nRows, nCols;

    do {
        printf("\n");
        printf("1. Create a zero matrix\n");
        printf("2. Create a photo matrix with '*'\n");
        printf("3. Create a color matrix with 'R'\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createMatrix(5, 5, &m);
                printf("Zero matrix created.\n");
                displayMatrixInt(m);
                break;
            case 2:
                createMatrixFoto(5, 5, &m);
                printf("Photo matrix created.\n");
                displayMatrixChar(m);
                break;
            case 3:
                createMatrixWarna(5, 5, &m);
                printf("Color matrix created.\n");
                displayMatrixChar(m);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        } 
    } while (choice != 4);

    return 0;
}

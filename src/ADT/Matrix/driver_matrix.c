#include "matrix.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    Matrix m1, mFoto, mWarna;
    int n;
    scanf("%d", &n);

    switch (n) {
    case 1:
        createMatrix(5, 5, &m1);
        printf("M1:\n");
        displayMatrixInt(m1);
        break;
    case 2:
        createMatrixFoto(5, 5, &mFoto);
        printf("\nMFOTO:\n");
        displayMatrixChar(mFoto);
        break;
    case 3:
        createMatrixWarna(5, 5, &mWarna);
        printf("\nMWARNA:\n");
        displayMatrixChar(mWarna);
        break;
    
    default:
        break;
    }

    return 0;
}

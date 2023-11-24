#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFFMTRX(*m) = nRows;
    COL_EFFMTRX(*m)= nCols;
    int i,j;
    for(i=0; i<nRows; i++){
        for(j=0; j<nCols; j++){
            ELMTMTRX(*m, i, j) = 0;
        }
    }
}

void createMatrixFoto(int nRows, int nCols, Matrix *m){
    ROW_EFFMTRX(*m) = nRows;
    COL_EFFMTRX(*m)= nCols;
    int i,j;
    for(i=0; i<nRows; i++){
        for(j=0; j<nCols; j++){
            ELMTMTRX(*m, i, j) = '*';
        }
    }
}
void createMatrixWarna(int nRows, int nCols, Matrix *m){
    ROW_EFFMTRX(*m) = nRows;
    COL_EFFMTRX(*m)= nCols;
    int i,j;
    for(i=0; i<nRows; i++){
        for(j=0; j<nCols; j++){
            ELMTMTRX(*m, i, j) = 'R';
        }
    }
}

void displayMatrixChar(Matrix m){
    int i,j;
    for(i=0; i<ROW_EFFMTRX(m); i++){
        for(j=0; j<COL_EFFMTRX(m); j++){
            printf("%c", ELMTMTRX(m,i,j));
            if (j<(COL_EFFMTRX(m)-1)) printf(" ");
        }
        printf("\n");
    }
}

void displayMatrixInt(Matrix m){
    int i,j;
    for(i=0; i<ROW_EFFMTRX(m); i++){
        for(j=0; j<COL_EFFMTRX(m); j++){
            printf("%d", ELMTMTRX(m,i,j));
            if (j<(COL_EFFMTRX(m)-1)) printf(" ");
        }
        printf("\n");
    }
}

void shiftMatrix(Matrix *m) {
    int nRows = ROW_EFFMTRX(*m);
    int nCols = COL_EFFMTRX(*m);

    Matrix shiftedMatrix;
    createMatrix(nRows, nCols, &shiftedMatrix);

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            int newRow = (i + 1) % nRows; // Menggeser baris ke bawah
            ELMTMTRX(shiftedMatrix, newRow, j) = ELMTMTRX(*m, i, j);
        }
    }

    copyMatrix(shiftedMatrix, m);
}

void copyMatrix(Matrix mIn, Matrix *mOut){
    createMatrix(ROW_EFFMTRX(mIn),COL_EFFMTRX(mIn),mOut);
    int i, j;
    for(i=0; i<ROW_EFFMTRX(mIn); i++){
        for(j=0; j<COL_EFFMTRX(mIn); j++){
            ELMTMTRX(*mOut, i, j) = ELMTMTRX(mIn, i, j); 
        }
    }
}
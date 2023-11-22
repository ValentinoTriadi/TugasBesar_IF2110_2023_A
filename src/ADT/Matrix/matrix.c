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
            if (j<getLastIdxCol(m)) printf(" ");
        }
        printf("\n");
    }
}

void displayMatrixInt(Matrix m){
    int i,j;
    for(i=0; i<ROW_EFFMTRX(m); i++){
        for(j=0; j<COL_EFFMTRX(m); j++){
            printf("%d", ELMTMTRX(m,i,j));
            if (j<getLastIdxCol(m)) printf(" ");
        }
        printf("\n");
    }
}
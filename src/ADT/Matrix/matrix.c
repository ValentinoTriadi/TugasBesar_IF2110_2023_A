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
// boolean isMatrixIdxValid(int i, int j){
//     return (i<ROW_CAPMTRX && i>=0 && j>=0 && j<COL_CAPMTRX);
// }
// IdxTypeMTRX getLastIdxRow(Matrix m){
//     return (ROW_EFFMTRX(m)-1);
// }
// IdxTypeMTRX getLastIdxCol(Matrix m){
//     return (COL_EFFMTRX(m)-1);
// }
// boolean isIdxEff(Matrix m, IdxTypeMTRX i, IdxTypeMTRX j){
//     return (i<ROW_EFFMTRX(m) && i>=0 && j>=0 && j<COL_EFFMTRX(m));
// }
// ElTypeMTRX getElmtDiagonal(Matrix m, IdxTypeMTRX i){
//     return (ELMTMTRX(m,i,i));
// }
// void copyMatrix(Matrix mIn, Matrix *mOut){
//     createMatrix(ROW_EFFMTRX(mIn),COL_EFFMTRX(mIn),mOut);
//     int i, j;
//     for(i=0; i<ROW_EFFMTRX(mIn); i++){
//         for(j=0; j<COL_EFFMTRX(mIn); j++){
//             ELMTMTRX(*mOut, i, j) = ELMTMTRX(mIn, i, j); 
//         }
//     }
// }
// void readMatrix(Matrix *m, int nRow, int nCol){
//     createMatrix(nRow,nCol,m);
//     int i,j;
//     for(i=0; i<nRow; i++){
//         for(j=0; j<nCol; j++){
//             scanf("%d", &ELMTMTRX(*m, i, j));
//         }
//     }
// }
// void displayMatrix(Matrix m){
//     int i,j;
//     for(i=0; i<ROW_EFFMTRX(m); i++){
//         for(j=0; j<COL_EFFMTRX(m); j++){
//             printf("%d", ELMTMTRX(m,i,j));
//             if (j<getLastIdxCol(m)) printf(" ");
//         }
//         // if (i!=ROW_EFFMTRX(m)-1) printf("\n");
//         printf("\n");
//     }
// }
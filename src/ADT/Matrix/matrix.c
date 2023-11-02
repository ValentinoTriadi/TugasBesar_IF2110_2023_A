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
boolean isMatrixIdxValid(int i, int j){
    return (i<ROW_CAPMTRX && i>=0 && j>=0 && j<COL_CAPMTRX);
}
IdxType getLastIdxRow(Matrix m){
    return (ROW_EFFMTRX(m)-1);
}
IdxType getLastIdxCol(Matrix m){
    return (COL_EFFMTRX(m)-1);
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return (i<ROW_EFFMTRX(m) && i>=0 && j>=0 && j<COL_EFFMTRX(m));
}
ElType getElmtDiagonal(Matrix m, IdxType i){
    return (ELMTMTRX(m,i,i));
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
void readMatrix(Matrix *m, int nRow, int nCol){
    createMatrix(nRow,nCol,m);
    int i,j;
    for(i=0; i<nRow; i++){
        for(j=0; j<nCol; j++){
            scanf("%d", &ELMTMTRX(*m, i, j));
        }
    }
}
void displayMatrix(Matrix m){
    int i,j;
    for(i=0; i<ROW_EFFMTRX(m); i++){
        for(j=0; j<COL_EFFMTRX(m); j++){
            printf("%d", ELMTMTRX(m,i,j));
            if (j<getLastIdxCol(m)) printf(" ");
        }
        // if (i!=ROW_EFFMTRX(m)-1) printf("\n");
        printf("\n");
    }
}
Matrix addMatrix(Matrix m1, Matrix m2){
    int i,j;
    for(i=0; i<ROW_EFFMTRX(m1); i++){
        for(j=0; j<COL_EFFMTRX(m1); j++){
            ELMTMTRX(m1, i, j) += ELMTMTRX(m2, i, j);
        }
    }
    return m1;
}
Matrix subtractMatrix(Matrix m1, Matrix m2){
    int i,j;
    for(i=0; i<ROW_EFFMTRX(m1); i++){
        for(j=0; j<COL_EFFMTRX(m1); j++){
            ELMTMTRX(m1, i, j) -= ELMTMTRX(m2, i, j);
        }
    }
    return m1;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m;
    createMatrix(ROW_EFFMTRX(m1), COL_EFFMTRX(m2), &m);

    int i,j,k;
    for(i=0; i<ROW_EFFMTRX(m); i++){
        for(j=0; j<COL_EFFMTRX(m); j++){
            for(k=0; k<COL_EFFMTRX(m1); k++){
                ELMTMTRX(m, i, j) += ELMTMTRX(m1, i, k) * ELMTMTRX(m2, k, j);
            }
        }
    }
    return m;
}
Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod){
    Matrix m;
    createMatrix(ROW_EFFMTRX(m1),COL_EFFMTRX(m2), &m);;
    
    int i,j,k;
    for (i=0;i<ROW_EFFMTRX(m);i++){
        for (j=0;j<COL_EFFMTRX(m);j++){
            for (k=0;k<COL_EFFMTRX(m1);k++){
                ELMTMTRX(m,i,j) += ELMTMTRX(m1,i,k) * ELMTMTRX(m2,k,j);
            }
            ELMTMTRX(m,i,j) %= mod;
        }   
    }

    return m;
}
Matrix multiplyByConst(Matrix m, ElType x){
    int i,j;
    for(i=0; i<ROW_EFFMTRX(m); i++){
        for(j=0; j<COL_EFFMTRX(m); j++){
            ELMTMTRX(m, i, j) *= x;
        }
    }
    return m;
}
void pMultiplyByConst(Matrix *m, ElType k){
    int i,j;
    for(i=0; i<ROW_EFFMTRX(*m); i++){
        for(j=0; j<COL_EFFMTRX(*m); j++){
            ELMTMTRX(*m,i,j) *= k;
        }
    }
}
boolean isMatrixEqual(Matrix m1, Matrix m2){
    if (!isMatrixSizeEqual(m1,m2)) return false;
    int i,j;
    for(i=0; i<ROW_EFFMTRX(m1); i++){
        for(j=0; j<COL_EFFMTRX(m1); j++){
            if (ELMTMTRX(m1,i,j) != ELMTMTRX(m2,i,j)) return false;
        }
    }
    return true;
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return (!isMatrixEqual(m1,m2));
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFFMTRX(m1) == ROW_EFFMTRX(m2) && COL_EFFMTRX(m1) == COL_EFFMTRX(m2));
}
int countElmt(Matrix m){
    return(ROW_EFFMTRX(m)*COL_EFFMTRX(m));
}
boolean isSquare(Matrix m){
    return(ROW_EFFMTRX(m) == COL_EFFMTRX(m));
}
boolean isSymmetric(Matrix m){
    if (!isSquare(m)) return false;
    int i,j;
    for(i=0; i<ROW_EFFMTRX(m); i++){
        for(j=0; j<COL_EFFMTRX(m); j++){
            if (ELMTMTRX(m,i,j) != ELMTMTRX(m,j,i)) return false;
        }
    }
    return true;
}
boolean isIdentity(Matrix m){
    if (!isSquare(m)) return false;
    int i,j;
    for(i=0; i<ROW_EFFMTRX(m); i++){
        for(j=0; j<COL_EFFMTRX(m); j++){
            if (i == j){
                if (ELMTMTRX(m,i,j) != 1) return false;
            } else {
                if (ELMTMTRX(m,i,j) != 0) return false;
            }
        }
    }
    return true;

}
boolean isSparse(Matrix m){
    if (!isSquare(m)) return false;
    int i,j, counter = 0;
    for(i=0; i<ROW_EFFMTRX(m); i++){
        for(j=0; j<COL_EFFMTRX(m); j++){
            if (ELMTMTRX(m,i,j) != 0) counter++;
        }
    }
    return (counter <= (0.05)*(float)countElmt(m));
}
Matrix negation(Matrix m){
    return multiplyByConst(m, -1);
}
void pNegation(Matrix *m){
    pMultiplyByConst(m, -1);
}
float determinant(Matrix m){
    if (ROW_EFFMTRX(m) == 0) return (float)(0);
    if (ROW_EFFMTRX(m) == 1) return (float)(ELMTMTRX(m,0,0));
    if (COL_EFFMTRX(m) == 2) return (float)((ELMTMTRX(m,0,0)*ELMTMTRX(m,1,1)) - (ELMTMTRX(m,0,1)*ELMTMTRX(m,1,0)));

    int i,j,k,l;
    float det=0;
    for (i=0; i<ROW_EFFMTRX(m); i++){
        Matrix mtemp;
        createMatrix(ROW_EFFMTRX(m)-1, COL_EFFMTRX(m)-1, &mtemp);
        for(j=0; j<ROW_EFFMTRX(mtemp); j++){
            int l = 0;
            for(k=0; k<COL_EFFMTRX(m); k++){
                if(k != i){
                    ELMTMTRX(mtemp,j,l) = ELMTMTRX(m,j+1,k);
                    l++;
                }
            }
        }

        det += (float)(ELMTMTRX(m,0,i)*(pow(-1,2+i))*determinant(mtemp));
    }

    return det;
}
Matrix transpose(Matrix m){
    Matrix mtemp;
    createMatrix(COL_EFFMTRX(m), ROW_EFFMTRX(m), &mtemp);
    int i,j;
    for(i=0; i<ROW_EFFMTRX(mtemp); i++){
        for(j=0; j<COL_EFFMTRX(mtemp); j++){
            ELMTMTRX(mtemp,i,j) = ELMTMTRX(m,j,i);
        }
    }
    return mtemp;
}
void pTranspose(Matrix *m){
    Matrix mtemp;
    createMatrix(COL_EFFMTRX(*m), ROW_EFFMTRX(*m), &mtemp);
    int i,j;
    for(i=0; i<COL_EFFMTRX(*m); i++){
        for(j=0; j<ROW_EFFMTRX(*m); j++){
            ELMTMTRX(mtemp,i,j) = ELMTMTRX(*m,j,i);
        }
    }
    *m = mtemp;
}
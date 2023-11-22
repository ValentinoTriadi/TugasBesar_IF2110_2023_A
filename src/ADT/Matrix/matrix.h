/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "../boolean.h"


/* Ukuran maksimum baris dan kolom */
#define ROW_CAPMTRX 100
#define COL_CAPMTRX 100
/* *** Selektor *** */
#define ROW_EFFMTRX(M) (M).rowEff
#define COL_EFFMTRX(M) (M).colEff
#define ELMTMTRX(M, i, j) (M).mem[(i)][(j)]

typedef int IdxTypeMTRX; /* Index baris, kolom */
typedef char ElTypeMTRX;
typedef struct
{
   ElTypeMTRX mem[ROW_CAPMTRX][COL_CAPMTRX];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAPMTRX-1][0..COL_CAPMTRX-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m);
void createMatrixFoto(int nRows, int nCols, Matrix *m);
void createMatrixWarna(int nRows, int nCols, Matrix *m);
void displayMatrixChar(Matrix m);
void displayMatrixInt(Matrix m);

#endif
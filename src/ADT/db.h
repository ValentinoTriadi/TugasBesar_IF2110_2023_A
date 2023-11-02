
#ifndef DB_H
#define DB_H
typedef struct db
{
    
} DB;

/*---------------------------------------------------CHAR MACHINE---------------------------------------------------*/
#define MARK ';'
#define MARKLINE '\n'
#define MARKFILE '\0'
/*---------------------------------------------------CHAR MACHINE---------------------------------------------------*/

/*---------------------------------------------------WORD MACHINE---------------------------------------------------*/
#define NMax 500
#define BLANK ' '
#define NEWLINE '\n'
#define HURUF(w,i) (w).TabWord[(i)]

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;
/*---------------------------------------------------WORD MACHINE---------------------------------------------------*/

/*---------------------------------------------------LIST STATIK---------------------------------------------------*/
/*  Kamus Umum */
#define CAPACITYPENGGUNA 20
/* Kapasitas penyimpanan */
#define IDX_MINLISTSTATIK 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARKLISTSTATIK -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeLISTSTATIK;
typedef struct {
   PROFIL contents[CAPACITYPENGGUNA]; /* memori tempat penyimpan elemen (container) */
} ListStatikProfil;
/* Indeks yang digunakan [0..CAPACITYPENGGUNA-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses: 
   ELMTLISTSTATIK(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai MARKLISTSTATIK
   Definisi elemen pertama: ELMTLISTSTATIK(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMTLISTSTATIK(l, i) (l).contents[(i)]
/*---------------------------------------------------LIST STATIK---------------------------------------------------*/

/*---------------------------------------------------MATRIKS---------------------------------------------------*/
/* Ukuran maksimum baris dan kolom */
#define ROW_CAPMTRX 100
#define COL_CAPMTRX 100
/* *** Selektor *** */
#define ROW_EFFMTRX(M) (M).rowEff
#define COL_EFFMTRX(M) (M).colEff
#define ELMTMTRX(M, i, j) (M).mem[(i)][(j)]

typedef int IdxType; /* Index baris, kolom */
typedef char ElType;
typedef struct
{
   ElType mem[ROW_CAPMTRX][COL_CAPMTRX];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAPMTRX-1][0..COL_CAPMTRX-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */
/*---------------------------------------------------MATRIKS---------------------------------------------------*/















typedef struct pengguna
{
    ListStatikProfil listProfil;
} PENGGUNA;

typedef struct profil
{
    Word Nama;
    Word Sandi;
    Word Bio;
    Word NoHP;
    Word Weton;
    Matrix Foto;
    Matrix WarnaFoto;
    boolean isPublic;
} PROFIL;

typedef struct teman
{
    
} TEMAN;

typedef struct kicau
{
    /* data */
} KICAU;




#endif
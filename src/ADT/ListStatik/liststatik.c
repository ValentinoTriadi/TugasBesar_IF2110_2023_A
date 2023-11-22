/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */


#include "liststatik.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARKLISTSTATIK */
    int i;
    for (i = IDX_MIN; i < CAPACITY; i++)
    {
        ELMTLISTSTATIK(*l, i) = MARKLISTSTATIK;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listStatikLength(ListStatik l){
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */
    int i = 0;

    while ((i < CAPACITY) && (ELMTLISTSTATIK(l, i) != MARKLISTSTATIK))
    {
        i++;
    }
    return i;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxLISTSTATIK(ListStatik l){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}

IdxType getLastIdxLISTSTATIK(ListStatik l){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    if (listStatikLength(l) == 0){
        return IDX_MIN;
    }
    else{
        return (listStatikLength(l) - 1);
    }
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidLISTSTATIK(ListStatik l, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IDX_MIN) && (i <= (CAPACITY - 1))) ;
}

boolean isIdxEffLISTSTATIK(ListStatik l, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
    /* yaitu antara 0..length(l)-1 */
    return ((i >= getFirstIdxLISTSTATIK(l)) && (i <= getLastIdxLISTSTATIK(l))) ;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyLISTSTATIK(ListStatik l){
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return (listStatikLength(l) == 0);
}
/* *** Test List penuh *** */
boolean isFullLISTSTATIK(ListStatik l){
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (listStatikLength(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListStatik(ListStatik *l){
    /* I.S. l sembarang */
    /* F.S. List l terdefinisi */
    /* Proses: membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
    /*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
    /*    Jika n tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
              Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
    /*    Jika n = 0; hanya terbentuk List kosong */
    int n, i;
    boolean valid = false;
    ElTypeLISTSTATIK ELMTLISTSTATIK;
    /*ALGORITMA*/
    while (valid != true){
        scanf("%d", &n);

        if ((n >= 0) && (n <= CAPACITY))
        {
            valid = true;
        }
    }

    CreateListStatik(l);
    for (i = 0; i < n ; i++){
        scanf("%d", &ELMTLISTSTATIK);
        ELMTLISTSTATIK(*l, i) = ELMTLISTSTATIK;
    }
}

void printListStatik(ListStatik l){
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
       siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
       karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    int i;
    printf("[");
    for (i = 0; i < listStatikLength(l); i++)
    {
        printf("%d", ELMTLISTSTATIK(l, i));
        if (i != listStatikLength(l) - 1)
        {
            printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusListStatik(ListStatik l1, ListStatik l2, boolean plus){
    /* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
           indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
           elemen l2 pada indeks yang sama */
    ListStatik l3;
    int i;
    CreateListStatik(&l3);
    for (i = 0; i < listStatikLength(l1); i++){
        if (plus == true){
            ELMTLISTSTATIK(l3, i) = ELMTLISTSTATIK(l1, i) + ELMTLISTSTATIK(l2, i);
        }
        else{
            ELMTLISTSTATIK(l3, i) = ELMTLISTSTATIK(l1, i) - ELMTLISTSTATIK(l2, i);
        }
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListStatikEqual(ListStatik l1, ListStatik l2){
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
       elemennya sama */
    /*KAMUS LOKAL*/
    boolean eq = true;
    int i;
    /*ALGORITMA*/
    if (listStatikLength(l1) == listStatikLength(l2)){
        for (i = 0; i < listStatikLength(l1) ; i++){
            if (ELMTLISTSTATIK(l1, i) != ELMTLISTSTATIK(l2, i)){
                eq = false;
            }
        }
    }
    else{
        eq = false;
    }
    return eq;
}

// /* ********** SEARCHING ********** */
// /* ***  Perhatian : List boleh kosong!! *** */
// int indexOfLISTSTATIK(ListStatik l, ElTypeLISTSTATIK val){
//     /* Search apakah ada elemen List l yang bernilai val */
//     /* Jika ada, menghasilkan indeks i terkecil, dengan ELMTLISTSTATIK(l,i) = val */
//     /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
//     /* Skema Searching yang digunakan bebas */
//     /*KAMUS LOKAL*/
//     int i = 0;
//     boolean found = false;
//     while ((i < CAPACITY) && (found != true))
//     {
//         if (ELMTLISTSTATIK(l, i) == val){
//             found = true;
//         }
//         else{
//             i++;
//         }
//     }

//     if (found == true){
//         return i;
//     }
//     else{
//         return IDX_UNDEF;
//     }
// }

// /* ********** NILAI EKSTREM ********** */
// void extremeValues(ListStatik l, ElTypeLISTSTATIK *max, ElTypeLISTSTATIK *min){
//     /* I.S. List l tidak kosong */
//     /* F.S. Max berisi nilai terbesar dalam l;
//             Min berisi nilai terkecil dalam l */
//     //  ElTypeLISTSTATIK maxval, minval;
//     // int i;
//     /*ALGORITMA*/
//     // emax = ELMTLISTSTATIK(l, 0);
//     // emin = ELMTLISTSTATIK(l, 0);
//     // for (i = 0; i < listStatikLength(l); i++){
//     //     if (ELMTLISTSTATIK(l, i) > emax){
//     //         maxval = ELMTLISTSTATIK(l, i);
//     //     }
//     //     if (ELMTLISTSTATIK(l, i) < emin){
//     //         minval = ELMTLISTSTATIK(l, i);
//     //     }
//     // }
//     // *max = emax;
//     // *min = emin;
//     // ElTypeLISTSTATIK maxval, minval;
//     int i;
//     /*ALGORITMA*/
//     *max = ELMTLISTSTATIK(l, 0);
//     *min = ELMTLISTSTATIK(l, 0);
//     for (i = 0; i < listStatikLength(l); i++){
//         if (ELMTLISTSTATIK(l, i) > *max){
//             *max = ELMTLISTSTATIK(l, i);
//         }
//         if (ELMTLISTSTATIK(l, i) < *min){
//             *min = ELMTLISTSTATIK(l, i);
//         }
//     }
// }

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirstLISTSTATIK(ListStatik *l, ElTypeLISTSTATIK val){
    /* Proses: Menambahkan val sebagai elemen pertama List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen pertama l yang baru */
    int i;
    if (isFullLISTSTATIK(*l) != true){
        for (i = listStatikLength(*l); i > 0; i--){
            ELMTLISTSTATIK(*l, i) = ELMTLISTSTATIK(*l, i - 1);
        }
        ELMTLISTSTATIK(*l, 0) = val;
    }
}
/* *** Menambahkan elemen pada index tertentu *** */
void insertAtLISTSTATIK(ListStatik *l, ElTypeLISTSTATIK val, IdxType idx){
    /* Proses: Menambahkan val sebagai elemen pada index idx List */
    /* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
    /* F.S. val adalah elemen yang disisipkan pada index idx l */
    int i;
    if ((isFullLISTSTATIK(*l) != true) && (isEmptyLISTSTATIK(*l) != true))
    {
        for (i = listStatikLength(*l); i > idx; i--)
        {
            ELMTLISTSTATIK(*l, i) = ELMTLISTSTATIK(*l, i - 1);
        }
        ELMTLISTSTATIK(*l, idx) = val;
    }
}
/* *** Menambahkan elemen terakhir *** */
void insertLastLISTSTATIK(ListStatik *l, ElTypeLISTSTATIK val){
    /* Proses: Menambahkan val sebagai elemen terakhir List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    if (isFullLISTSTATIK(*l) != true){
        ELMTLISTSTATIK(*l, listStatikLength(*l)) = val;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstLISTSTATIK(ListStatik *l, ElTypeLISTSTATIK *val){
    /* Proses : Menghapus elemen pertama List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    int i;
    if (isEmptyLISTSTATIK(*l) != true){
        *val = ELMTLISTSTATIK(*l, getFirstIdxLISTSTATIK(*l));

        for (i = 0; i < getLastIdxLISTSTATIK(*l); i++){
            ELMTLISTSTATIK(*l, i) = ELMTLISTSTATIK(*l, i + 1);
        }
        ELMTLISTSTATIK(*l, getLastIdxLISTSTATIK(*l)) = MARKLISTSTATIK;
    }
}
/* *** Menghapus elemen pada index tertentu *** */
void deleteAtLISTSTATIK(ListStatik *l, ElTypeLISTSTATIK *val, IdxType idx){
    /* Proses : Menghapus elemen pada index idx List */
    /* I.S. List tidak kosong, idx adalah index yang valid di l */
    /* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */

    int i;
    if (isEmptyLISTSTATIK(*l) != true){
        *val = ELMTLISTSTATIK(*l, idx);

        for (i = idx; i < getLastIdxLISTSTATIK(*l); i++){
            ELMTLISTSTATIK(*l, i) = ELMTLISTSTATIK(*l, i + 1);
        }
        ELMTLISTSTATIK(*l, getLastIdxLISTSTATIK(*l)) = MARKLISTSTATIK;
    }
}
/* *** Menghapus elemen terakhir *** */
void deleteLastLISTSTATIK(ListStatik *l, ElTypeLISTSTATIK *val){
    /* Proses : Menghapus elemen terakhir List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    if (isEmptyLISTSTATIK(*l) != true){
        *val = ELMTLISTSTATIK(*l, getLastIdxLISTSTATIK(*l));
        ELMTLISTSTATIK(*l, getLastIdxLISTSTATIK(*l)) = MARKLISTSTATIK;
    }
}

ListStatik concat_ListStatik(ListStatik l1, ListStatik l2){
    ListStatik l3;
    int i;
    CreateListStatik(&l3);
    for (i = 0; i < listLength_ListStatik(l1); i++){
        insertLast_ListStatik(&l3, ELMTLISTSTATIK(l1, i));
    }
    for (i = 0; i < listLength_ListStatik(l2); i++){
        insertLast_ListStatik(&l3, ELMTLISTSTATIK(l2, i));
    }
    return l3;
}

/* ********** SORTING ********** */
// void sortListStatik(ListStatik *l, boolean asc){
//     /* I.S. l boleh kosong */
//     /* F.S. Jika asc = true, l terurut membesar */
//     /*      Jika asc = false, l terurut mengecil */
//     /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
//        algoritma bebas */
//     /*Menggunakan Insertion Sort*/
//     /*KAMUS LOKAL*/
//     int i, j;
//     ElTypeLISTSTATIK temp;
//     IdxType idx;
//     /*ALGORITMA*/
//     if (asc == true){
//         for (i = 1; i < listStatikLength(*l); i++){
//             temp = ELMTLISTSTATIK(*l, i);
//             idx = i - 1;
//             while ((temp < ELMTLISTSTATIK(*l, idx)) && (idx > 0)){
//                 ELMTLISTSTATIK(*l, idx + 1) = ELMTLISTSTATIK(*l, idx);
//                 idx--;
//             }
//             if (temp >= ELMTLISTSTATIK(*l, idx)){
//                 ELMTLISTSTATIK(*l, idx + 1) = temp;
//             }
//             else{
//                 ELMTLISTSTATIK(*l, idx + 1) = ELMTLISTSTATIK(*l, idx);
//                 ELMTLISTSTATIK(*l, idx) = temp;
//             }
//         }
//     }
//     else{
//         for (i = 1; i < listStatikLength(*l); i++){
//             temp = ELMTLISTSTATIK(*l, i);
//             idx = i - 1;
//             while ((temp > ELMTLISTSTATIK(*l, idx)) && (idx > 0)){
//                 ELMTLISTSTATIK(*l, idx + 1) = ELMTLISTSTATIK(*l, idx);
//                 idx--;
//             }
//             if (temp <= ELMTLISTSTATIK(*l, idx)){
//                 ELMTLISTSTATIK(*l, idx + 1) = temp;
//             }
//             else{
//                 ELMTLISTSTATIK(*l, idx + 1) = ELMTLISTSTATIK(*l, idx);
//                 ELMTLISTSTATIK(*l, idx) = temp;
//             }
//         }
//     }
// }
/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */


#include "Liststatik.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListUser(ListUser *l){
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARKListUser */
    int i;
    for (i = IDX_MIN; i < CAPACITY; i++)
    {
        user(*l, i) = MARKListUser;
    }
}
 
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int ListUserLength(ListUser l){
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */
    int i = 0;

    while ((i < CAPACITY) && (user(l, i) != MARKListUser))
    {
        i++;
    }
    return i;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxListUser(ListUser l){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}

IdxType getLastIdxListUser(ListUser l){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    if (ListUserLength(l) == 0){
        return IDX_MIN;
    }
    else{
        return (ListUserLength(l) - 1);
    }
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListUser(ListUser l, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IDX_MIN) && (i <= (CAPACITY - 1))) ;
}

boolean isIdxEffListUser(ListUser l, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
    /* yaitu antara 0..length(l)-1 */
    return ((i >= getFirstIdxListUser(l)) && (i <= getLastIdxListUser(l))) ;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListUser(ListUser l){
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return (ListUserLength(l) == 0);
}
/* *** Test List penuh *** */
boolean isFullListUser(ListUser l){
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (ListUserLength(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListUser(ListUser *l){
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
    ElTypeListUser user;
    /*ALGORITMA*/
    while (valid != true){
        scanf("%d", &n);

        if ((n >= 0) && (n <= CAPACITY))
        {
            valid = true;
        }
    }

    CreateListUser(l);
    for (i = 0; i < n ; i++){
        scanf("%d", &user);
        user(*l, i) = user;
    }
}

void printListUser(ListUser l){
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
       siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
       karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    int i;
    printf("[");
    for (i = 0; i < ListUserLength(l); i++)
    {
        printf("%d", user(l, i));
        if (i != ListUserLength(l) - 1)
        {
            printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListUser plusMinusListUser(ListUser l1, ListUser l2, boolean plus){
    /* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
           indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
           elemen l2 pada indeks yang sama */
    ListUser l3;
    int i;
    CreateListUser(&l3);
    for (i = 0; i < ListUserLength(l1); i++){
        if (plus == true){
            user(l3, i) = user(l1, i) + user(l2, i);
        }
        else{
            user(l3, i) = user(l1, i) - user(l2, i);
        }
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListUserEqual(ListUser l1, ListUser l2){
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
       elemennya sama */
    /*KAMUS LOKAL*/
    boolean eq = true;
    int i;
    /*ALGORITMA*/
    if (ListUserLength(l1) == ListUserLength(l2)){
        for (i = 0; i < ListUserLength(l1) ; i++){
            if (user(l1, i) != user(l2, i)){
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
// int indexOfListUser(ListUser l, ElTypeListUser val){
//     /* Search apakah ada elemen List l yang bernilai val */
//     /* Jika ada, menghasilkan indeks i terkecil, dengan user(l,i) = val */
//     /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
//     /* Skema Searching yang digunakan bebas */
//     /*KAMUS LOKAL*/
//     int i = 0;
//     boolean found = false;
//     while ((i < CAPACITY) && (found != true))
//     {
//         if (user(l, i) == val){
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
// void extremeValues(ListUser l, ElTypeListUser *max, ElTypeListUser *min){
//     /* I.S. List l tidak kosong */
//     /* F.S. Max berisi nilai terbesar dalam l;
//             Min berisi nilai terkecil dalam l */
//     //  ElTypeListUser maxval, minval;
//     // int i;
//     /*ALGORITMA*/
//     // emax = user(l, 0);
//     // emin = user(l, 0);
//     // for (i = 0; i < ListUserLength(l); i++){
//     //     if (user(l, i) > emax){
//     //         maxval = user(l, i);
//     //     }
//     //     if (user(l, i) < emin){
//     //         minval = user(l, i);
//     //     }
//     // }
//     // *max = emax;
//     // *min = emin;
//     // ElTypeListUser maxval, minval;
//     int i;
//     /*ALGORITMA*/
//     *max = user(l, 0);
//     *min = user(l, 0);
//     for (i = 0; i < ListUserLength(l); i++){
//         if (user(l, i) > *max){
//             *max = user(l, i);
//         }
//         if (user(l, i) < *min){
//             *min = user(l, i);
//         }
//     }
// }

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirstListUser(ListUser *l, ElTypeListUser val){
    /* Proses: Menambahkan val sebagai elemen pertama List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen pertama l yang baru */
    int i;
    if (isFullListUser(*l) != true){
        for (i = ListUserLength(*l); i > 0; i--){
            user(*l, i) = user(*l, i - 1);
        }
        user(*l, 0) = val;
    }
}
/* *** Menambahkan elemen pada index tertentu *** */
void insertAtListUser(ListUser *l, ElTypeListUser val, IdxType idx){
    /* Proses: Menambahkan val sebagai elemen pada index idx List */
    /* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
    /* F.S. val adalah elemen yang disisipkan pada index idx l */
    int i;
    if ((isFullListUser(*l) != true) && (isEmptyListUser(*l) != true))
    {
        for (i = ListUserLength(*l); i > idx; i--)
        {
            user(*l, i) = user(*l, i - 1);
        }
        user(*l, idx) = val;
    }
}
/* *** Menambahkan elemen terakhir *** */
void insertLastListUser(ListUser *l, ElTypeListUser val){
    /* Proses: Menambahkan val sebagai elemen terakhir List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    if (isFullListUser(*l) != true){
        user(*l, ListUserLength(*l)) = val;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstListUser(ListUser *l, ElTypeListUser *val){
    /* Proses : Menghapus elemen pertama List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    int i;
    if (isEmptyListUser(*l) != true){
        *val = user(*l, getFirstIdxListUser(*l));

        for (i = 0; i < getLastIdxListUser(*l); i++){
            user(*l, i) = user(*l, i + 1);
        }
        user(*l, getLastIdxListUser(*l)) = MARKListUser;
    }
}
/* *** Menghapus elemen pada index tertentu *** */
void deleteAtListUser(ListUser *l, ElTypeListUser *val, IdxType idx){
    /* Proses : Menghapus elemen pada index idx List */
    /* I.S. List tidak kosong, idx adalah index yang valid di l */
    /* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */

    int i;
    if (isEmptyListUser(*l) != true){
        *val = user(*l, idx);

        for (i = idx; i < getLastIdxListUser(*l); i++){
            user(*l, i) = user(*l, i + 1);
        }
        user(*l, getLastIdxListUser(*l)) = MARKListUser;
    }
}
/* *** Menghapus elemen terakhir *** */
void deleteLastListUser(ListUser *l, ElTypeListUser *val){
    /* Proses : Menghapus elemen terakhir List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    if (isEmptyListUser(*l) != true){
        *val = user(*l, getLastIdxListUser(*l));
        user(*l, getLastIdxListUser(*l)) = MARKListUser;
    }
}

/* ********** SORTING ********** */
// void sortListUser(ListUser *l, boolean asc){
//     /* I.S. l boleh kosong */
//     /* F.S. Jika asc = true, l terurut membesar */
//     /*      Jika asc = false, l terurut mengecil */
//     /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
//        algoritma bebas */
//     /*Menggunakan Insertion Sort*/
//     /*KAMUS LOKAL*/
//     int i, j;
//     ElTypeListUser temp;
//     IdxType idx;
//     /*ALGORITMA*/
//     if (asc == true){
//         for (i = 1; i < ListUserLength(*l); i++){
//             temp = user(*l, i);
//             idx = i - 1;
//             while ((temp < user(*l, idx)) && (idx > 0)){
//                 user(*l, idx + 1) = user(*l, idx);
//                 idx--;
//             }
//             if (temp >= user(*l, idx)){
//                 user(*l, idx + 1) = temp;
//             }
//             else{
//                 user(*l, idx + 1) = user(*l, idx);
//                 user(*l, idx) = temp;
//             }
//         }
//     }
//     else{
//         for (i = 1; i < ListUserLength(*l); i++){
//             temp = user(*l, i);
//             idx = i - 1;
//             while ((temp > user(*l, idx)) && (idx > 0)){
//                 user(*l, idx + 1) = user(*l, idx);
//                 idx--;
//             }
//             if (temp <= user(*l, idx)){
//                 user(*l, idx + 1) = temp;
//             }
//             else{
//                 user(*l, idx + 1) = user(*l, idx);
//                 user(*l, idx) = temp;
//             }
//         }
//     }
// }
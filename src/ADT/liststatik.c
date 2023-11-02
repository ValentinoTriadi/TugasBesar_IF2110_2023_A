#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liststatik.h"


void CreateListStatik(ListStatikProfil *l){
    int i;
    for (i=IDX_MINLISTSTATIK; i<CAPACITYPENGGUNA; i++){
        ELMTLISTSTATIK(*l,i) = MARKLISTSTATIK;
    }
}

int listLength(ListStatikProfil l){
    int i, counter = 0;
    for (i=IDX_MINLISTSTATIK; i<CAPACITYPENGGUNA; i++){
        if (ELMTLISTSTATIK(l,i) != MARKLISTSTATIK) counter++;
    }
    return counter;
}

IdxTypeLISTSTATIK getFirstIdx(ListStatikProfil l){
    int i;
    for (i=IDX_MINLISTSTATIK; i<CAPACITYPENGGUNA; i++){
        if (ELMTLISTSTATIK(l,i) != MARKLISTSTATIK) return i;
    }
    return IDX_UNDEF;
}

IdxTypeLISTSTATIK getLastIdx(ListStatikProfil l){
    int i;
    for (i=CAPACITYPENGGUNA-1; i>=IDX_MINLISTSTATIK; i--){
        if (ELMTLISTSTATIK(l,i) != MARKLISTSTATIK) return i;
    }
    return IDX_UNDEF;
}

boolean isIdxValid(ListStatikProfil l, IdxTypeLISTSTATIK i){
    return (i >= IDX_MINLISTSTATIK && i < CAPACITYPENGGUNA);
}

boolean isIdxEff(ListStatikProfil l, IdxTypeLISTSTATIK i){
    return (i >= 0 && i < listLength(l));
}

boolean isEmpty(ListStatikProfil l){
    return (listLength(l) == 0);
}

boolean isFull(ListStatikProfil l){
    return (listLength(l) == CAPACITYPENGGUNA);
}

void readList(ListStatikProfil *l){
    int n, i;
    scanf("%d", &n);
    while (n< IDX_MINLISTSTATIK || n>CAPACITYPENGGUNA){
        scanf("%d", &n);
    }

    CreateListStatik(l);
    for (i = 0; i<n; i++) {
        scanf("%d", &ELMTLISTSTATIK(*l,i));
    }
}

void printList(ListStatikProfil l){
    int i;
    printf("[");
    if (!isEmpty(l)){
        for (i=getFirstIdx(l); i<=getLastIdx(l); i++) {
            printf("%d",ELMTLISTSTATIK(l,i));
            if (i < getLastIdx(l)) printf(",");
        }
    }
    printf("]");
}

ListStatikProfil plusMinusList(ListStatikProfil l1, ListStatikProfil l2, boolean plus){
    ListStatikProfil lbaru;
    CreateListStatik(&lbaru);
    int i, firstIDXl1 = getFirstIdx(l1), firstIDXl2 = getFirstIdx(l2);
    if (plus) {
        for (i=0;i<listLength(l1);i++) {
            ELMTLISTSTATIK(lbaru, i) = ELMTLISTSTATIK(l1,firstIDXl1+i) + ELMTLISTSTATIK(l2,firstIDXl2+i);
        } 
    } else {
        for (i=0;i<listLength(l1);i++) {
            ELMTLISTSTATIK(lbaru, i) = ELMTLISTSTATIK(l1,firstIDXl1+i) - ELMTLISTSTATIK(l2,firstIDXl2+i);
        } 
    }
    return lbaru;
}

boolean isListEqual(ListStatikProfil l1, ListStatikProfil l2){
    if (listLength(l1) != listLength(l2)) return false;
    int i, firstIDXl1 = getFirstIdx(l1), firstIDXl2 = getFirstIdx(l2);
    for (i=0; i<listLength(l1); i++) {
        if (ELMTLISTSTATIK(l1, firstIDXl1+i) != ELMTLISTSTATIK(l2, firstIDXl2+i)) return false;
    }
    return true;
}

void insertFirst(ListStatikProfil *l, PROFIL val){
    int i, fidx = IDX_MINLISTSTATIK;
    if (!isEmpty(*l)){
        fidx  = getFirstIdx(*l);
        for (i=getLastIdx(*l); i>= fidx; i--){
            ELMTLISTSTATIK(*l,i+1) = ELMTLISTSTATIK(*l,i);
        }
    }
    ELMTLISTSTATIK(*l, fidx) = val;
}

void insertAt(ListStatikProfil *l, PROFIL val, IdxTypeLISTSTATIK idx){
    int i;
    if (getLastIdx(*l) < CAPACITYPENGGUNA-1){
        for(i=getLastIdx(*l);i>=idx;i--){
            ELMTLISTSTATIK(*l,i+1) = ELMTLISTSTATIK(*l,i);
        }
    } else {
        for(i=getFirstIdx(*l);i<=idx;i++){
            ELMTLISTSTATIK(*l,i-1) = ELMTLISTSTATIK(*l,i);
        }
    }
    ELMTLISTSTATIK(*l,idx) = val;
}

void insertLast(ListStatikProfil *l, PROFIL val){
    ELMTLISTSTATIK(*l, getLastIdx(*l) + 1) = val;
}

void deleteFirst(ListStatikProfil *l, PROFIL *val){
    int i, lidx = getLastIdx(*l), fidx = getFirstIdx(*l);
    *val = ELMTLISTSTATIK(*l, fidx);
    for (i=fidx; i<lidx; i++) {
        ELMTLISTSTATIK(*l,i) = ELMTLISTSTATIK(*l,i+1);
    }
    ELMTLISTSTATIK(*l, lidx) = MARKLISTSTATIK;
}

void deleteAt(ListStatikProfil *l, PROFIL *val, IdxTypeLISTSTATIK idx){
    int i, lidx = getLastIdx(*l);
    *val = ELMTLISTSTATIK(*l, idx);
    for (i=idx; i<lidx; i++) {
        ELMTLISTSTATIK(*l,i) = ELMTLISTSTATIK(*l,i+1);
    }
    ELMTLISTSTATIK(*l, lidx) = MARKLISTSTATIK;
}

void deleteLast(ListStatikProfil *l, PROFIL *val){
    int lidx = getLastIdx(*l);
    *val = ELMTLISTSTATIK(*l, lidx);
    ELMTLISTSTATIK(*l, lidx) = MARKLISTSTATIK;
}

void sortList(ListStatikProfil *l, boolean asc){
    int i, j, temp;
    if (asc) {
        for (i=getFirstIdx(*l); i<getLastIdx(*l); i++){
            for (j=getLastIdx(*l); j>i; j--){
                if (ELMTLISTSTATIK(*l,j) < ELMTLISTSTATIK(*l,j-1)) {
                    temp = ELMTLISTSTATIK(*l,j);
                    ELMTLISTSTATIK(*l,j) = ELMTLISTSTATIK(*l,j-1);
                    ELMTLISTSTATIK(*l,j-1) = temp;
                }
            }
        }
    } else {
        for (i=getFirstIdx(*l); i<getLastIdx(*l); i++){
            for (j=getLastIdx(*l); j>i; j--){
                if (ELMTLISTSTATIK(*l,j) > ELMTLISTSTATIK(*l,j-1)) {
                    temp = ELMTLISTSTATIK(*l,j);
                    ELMTLISTSTATIK(*l,j) = ELMTLISTSTATIK(*l,j-1);
                    ELMTLISTSTATIK(*l,j-1) = temp;
                }
            }
        }

    }
}

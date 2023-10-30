// #include <stdio.h>
// #include <stdlib.h>
// #include "listdin.h"

// void CreateListDin(ListDinWord *l, int capacity) {
//     CAPACITYLISTDIN(*l) = capacity;
//     NEFFLISTDIN(*l) = 0;
//     BUFFERLISTDIN(*l) = (ElTypeW *) malloc (sizeof(ElTypeW) * capacity);
// }
// void dealocateList(ListDinWord *l) {
//     free(BUFFERLISTDIN(*l));
//     CAPACITYLISTDIN(*l) = 0;
//     NEFFLISTDIN(*l) = 0;
// }
// int listLength(ListDinWord l) {
//     return NEFFLISTDIN(l);
// }
// IdxType getFirstIdx(ListDinWord l) {
//     return IDX_MIN;
// }
// IdxType getLastIdx(ListDinWord l) {
//     return listLength(l)-1;
// }
// boolean isIdxValid(ListDinWord l, IdxType i) {
//     return (i >= IDX_MIN && i < (IdxType) CAPACITYLISTDIN(l));
// }
// boolean isIdxEff(ListDinWord l, IdxType i) {
//     return (i >= IDX_MIN && i < listLength(l));
// }
// boolean isEmpty(ListDinWord l) {
//     return (listLength(l) == 0);
// }
// boolean isFull(ListDinWord l) {
//     return (listLength(l) == CAPACITYLISTDIN(l));
// }
// void readList(ListDinWord *l) {
//     int N;
//     IdxType i;
//     scanf("%d", &N);
//     while (N<0 || N>CAPACITYLISTDIN(*l)){
//         scanf("%d", &N);
//     }
//     NEFFLISTDIN(*l) = N;
//     for(i = 0; i < (IdxType) N; i++) {
//         scanf("%d", &ELMTLISTDIN(*l,i));
//     }
// }
// void printList(ListDinWord l) {
//     int i;
//     printf("[");
//     for(i = getFirstIdx(l); i<=getLastIdx(l); i++){
//         printf("%d", ELMTLISTDIN(l,i));
//         if (i < getLastIdx(l)) printf(",");
//     }
//     printf("]");
// }
// void copyList(ListDinWord lIn, ListDinWord *lOut) {
//     CreateListDin(lOut, CAPACITYLISTDIN(lIn));
//     NEFFLISTDIN(*lOut) = NEFFLISTDIN(lIn);
//     IdxType i;
//     for (i=getFirstIdx(lIn); i<=getLastIdx(lIn); i++) {
//         ELMTLISTDIN(*lOut,i) = ELMTLISTDIN(lIn,i);
//     }
// }
// void insertLast(ListDinWord *l, ElTypeW val) {
//     ELMTLISTDIN(*l, listLength(*l)) = val;
//     NEFFLISTDIN(*l)++;
// }
// void deleteLast(ListDinWord *l, ElTypeW *val) {
//     *val = ELMTLISTDIN(*l, getLastIdx(*l));
//     NEFFLISTDIN(*l)--;
// }
// void expandList(ListDinWord *l, int num) {
//     ListDinWord L;
//     copyList(*l, &L);
//     dealocateList(l);
//     CreateListDin(l, CAPACITYLISTDIN(L)+num);
//     NEFFLISTDIN(*l) = NEFFLISTDIN(L);
//     IdxType i;
//     for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
//         ELMTLISTDIN(*l,i) = ELMTLISTDIN(L,i);
//     }
// }
// void shrinkList(ListDinWord *l, int num){
//     ListDinWord L;
//     copyList(*l, &L);
//     dealocateList(l);
//     CreateListDin(l, CAPACITYLISTDIN(L)-num);
//     NEFFLISTDIN(*l) = NEFFLISTDIN(L);
//     IdxType i;
//     for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
//         ELMTLISTDIN(*l,i) = ELMTLISTDIN(L,i);
//     }
// }
// void compressList(ListDinWord *l) {
//     ListDinWord L;
//     copyList(*l, &L);
//     dealocateList(l);
//     CreateListDin(l, NEFFLISTDIN(L));
//     NEFFLISTDIN(*l) = NEFFLISTDIN(L);
//     IdxType i;
//     for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
//         ELMTLISTDIN(*l,i) = ELMTLISTDIN(L,i);
//     }
// }
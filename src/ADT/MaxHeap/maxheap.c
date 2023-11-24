// #include "maxheap.h"
// #include <stdio.h>


// void swap(MAXHEAP* h, int p, int c){
//     int temp = ELMTHeap(*h,p);
//     ELMTHeap(*h,p) = ELMTHeap(*h,c);
//     ELMTHeap(*h,c) = temp;
// }

// void createHeap(MAXHEAP* h, int n){
//     h->size = n;
//     for (int i = 0; i < MAXSIZEHEAP; i++){
//         h->ID[i] = HEAP_UNDEF;
//     }
//     for (int i = 0; i < n; i++){
//         h->ID[i] = i+1;
//     }
// }

// void insertHeap(MAXHEAP h, int id);

// void maxHeapify(MAXHEAP* h, int idx){
//     // int p = idx;
//     // if (isLeaf(*h , idx)) return;
//     // if (getLikeByID(ELMTHeap(*h,LChild(p))) >= getLikeByID(ELMTHeap(*h,RChild(p)))){
//     //     if (getLikeByID(ELMTHeap(*h,LChild(p))) == getLikeByID(ELMTHeap(*h,RChild(p)))){
//     //         if (getTimeByID(ELMTHeap(*h,LChild(p))) < getTimeByID(ELMTHeap(*h,RChild(p)))){
//     //             swap(h, p, LChild(p));
//     //             p = LChild(p);
//     //         } else {
//     //             swap(h, p, RChild(p));
//     //             p = RChild(p);
//     //         }
//     //     } else {
//     //         swap(h, p, LChild(p));
//     //         p = LChild(p);
//     //     }
//     // } else {
//     //     swap(h, p, RChild(p));
//     //     p = RChild(p);
//     // }
//     // maxHeapify(h, p);
//     int p = idx;
//     int l = ELMTHeap(*h,LChild(p));
//     int r = ELMTHeap(*h,RChild(p));
//     // if (isLeaf(*h , idx)) return;
//     // printf("%d ", ELMTHeap(*h,LChild(p)) >= (ELMTHeap(*h,RChild(p))));
//     // printf("%d ", RChild(p) < h->size);
//     // printf("%d ", (RChild(p) >= h->size && LChild(p) < h->size));
//     // printf("%d ", ELMTHeap(*h,p) < ELMTHeap(*h,LChild(p)));
//     if (((ELMTHeap(*h,LChild(p)) >= ELMTHeap(*h,RChild(p)) && RChild(p) < h->size) || (RChild(p) >= h->size && LChild(p) < h->size)) && ELMTHeap(*h,p) < ELMTHeap(*h,LChild(p))){
//         // if (ELMTHeap(*h,LChild(p)) == (ELMTHeap(*h,RChild(p)))){
//             // if (getTimeByID(ELMTHeap(*h,LChild(p))) < getTimeByID(ELMTHeap(*h,RChild(p)))){
//             //     swap(h, p, LChild(p));
//             //     p = LChild(p);
//             // } else {
//                 // swap(h, p, RChild(p));
//                 // p = RChild(p);
//             // }
//         // } else {
//             swap(h, p, LChild(p));
//             maxHeapify(h, LChild(p));
//         // }
//     } else if (ELMTHeap(*h,LChild(p)) < (ELMTHeap(*h,RChild(p))) && RChild(p) < h->size && ELMTHeap(*h,p) < ELMTHeap(*h,RChild(p))){
//         swap(h, p, RChild(p));
//         maxHeapify(h, RChild(p));
//     } 
// }

// void deleteMaxHeap(MAXHEAP* h, int* val){
//     for(int i = (h->size/2)-1; i >= 0; i--){
//         maxHeapify(h, i);
//         // printf ("\n");
//         // printf ("%d\n", i);
//         // printheap(*h);
//     }
//     *val = ELMTHeap(*h,0);
//     ELMTHeap(*h,0) = ELMTHeap(*h,(h->size)-1);
//     h->size--;
// }
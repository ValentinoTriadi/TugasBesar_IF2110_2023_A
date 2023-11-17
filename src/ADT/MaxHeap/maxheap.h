#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include <math.h>
#include "../boolean.h"

#define MAXSIZEHEAP 10
#define HEAP_UNDEF -999

typedef struct maxheap
{
    int size;
    int ID [MAXSIZEHEAP];
} MAXHEAP;

#define LChild(i)           (2*(i)+1)
#define RChild(i)           (2*(i)+2)
#define Parent(i)           floor(((i)-1)/2)
#define ELMTHeap(h,i)       (h).ID[i]


boolean isLeaf(MAXHEAP h, int idx);

void swap(MAXHEAP* h, int p, int c);

void createHeap(MAXHEAP* h, int n);

void insertHeap(MAXHEAP h, int id);

void maxHeapify(MAXHEAP* h, int idx);

void deleteMaxHeap(MAXHEAP* h, int* val);

#endif
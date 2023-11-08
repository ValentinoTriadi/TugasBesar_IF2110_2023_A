#include "stack.h"
#include "boolean.h"

#define Nil -1 // stack dengan elemen kosong
#define MaxEl 100

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

void CreateEmpty(Stack *S)
{
    Top(*S) = Nil;
}

boolean IsEmpty(Stack S)
{
    return Top(S) == Nil;
}

boolean IsFull(Stack S)
{
    return Top(S) == MaxEl - 1;
}

void Push(Stack *S, infotype X)
{
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotype *X) // Menghapus X dari Stack S.
{
    *X = InfoTop(*S);
    Top(*S)--;
}
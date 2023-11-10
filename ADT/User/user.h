#ifndef __USER_H__
#define __USER_H__
#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../ListStatik/liststatik.h"
#include "../Profil/profil.h"

#define CAPACITY 20

typedef Profil ElType;  /* type elemen List */
typedef int IdxType;
typedef struct {
   ElType Users[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} Listuser;

#define ELMT(l, i) (l).users[(i)]

void signUp() ;

void signIn() ;

void signOut() ;

void exitProgram();


#endif
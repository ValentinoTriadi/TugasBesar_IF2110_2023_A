#ifndef __USER_H__
#define __USER_H__
#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../Mesin-Kata/wordmachine.c"
#include "../ListStatik/liststatik.c"
#include "../Profil/profil.c"

extern Profil user;

#define CAP 20

// typedef Profil ElType;  /* type elemen List */
typedef int IdxType;
typedef struct {
   Profil Users[CAP]; /* memori tempat penyimpan elemen (container) */
} Listuser;

#define User(l, i) (l).users[(i)]

void signUp() ;

void signIn() ;

void signOut() ;

void exitProgram();


#endif
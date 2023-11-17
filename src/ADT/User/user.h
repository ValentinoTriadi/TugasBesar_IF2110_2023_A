#ifndef __USER_H__
#define __USER_H__
#include <stdio.h>
#include <stdlib.h>
// #include "../Database/db.h"
#include "../Profil/profil.h"
#include "../boolean.h"

#define MAX_USER_LIST 20

typedef struct {
   Profil pengguna[MAX_USER_LIST];
} userlist;


void signUp() ;

void signIn() ;

void signOut() ;

void exitProgram();


#endif
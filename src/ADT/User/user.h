#ifndef __USER_H__
#define __USER_H__
#include <stdio.h>
#include <stdlib.h>
#include "..\boolean.h"
#include "..\ListStatik\liststatik.h"
#include "..\Profil\profil.h"

#define MAX_USER_LIST 20

typedef struct {
   Profil pengguna[MAX_USER_LIST];
} userlist;


void signUp() ;

void signIn() ;

void signOut() ;

void exitProgram();


#endif
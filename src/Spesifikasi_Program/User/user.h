#ifndef __USER_H__
#define __USER_H__
#include <stdio.h>
#include <stdlib.h>
#include "..\boolean.h"
#include "..\..\ADT\WordMachine\wordmachine.c"
#include "..\..\ADT\ListStatik\liststatik.c"
#include "..\Profil\profil.c"

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20


typedef struct {
    Profil pengguna[20];
} User;

User currentUser;

void signUp() ;

void signIn() ;

void signOut() ;

void exitProgram();


#endif
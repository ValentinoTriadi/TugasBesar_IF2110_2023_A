#ifndef __USER_H__
#define __USER_H__
#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../WordMachine/wordmachine.c"


#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    Word nama;
    Word sandi;
} user;

user currentUser;

void signUp() ;

void signIn() ;

void signOut() ;

void exit();


#endif
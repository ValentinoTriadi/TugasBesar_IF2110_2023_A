#ifndef __USER_H__
#define __USER_H__

#include "../Profil/profil.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_USER_LIST 20
#define MAX_LENGTH 20

typedef struct {
   Profil pengguna[MAX_USER_LIST];
   int total;
} userlist;

#define User(l, i) (l).users[(i)]


boolean isExists(Word name);
boolean checkPassword (Word nama, Word sandi);
int findIndexUser(Word nama);
void daftar();
void masuk();
void keluar();
void tutupProgram();
void printUser();


#endif
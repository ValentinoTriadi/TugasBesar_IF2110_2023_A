#ifndef INISIALISASI_H
#define INISIALISASI_H

#include "../Mesin-Kata/wordmachine.h"
#include "../pcolor/pcolor.h"
#include "../Time/adttime.h"
#include "../Database/db.h"
#include "../muat/muat.h"
#include <stdio.h>
#include <stdlib.h>

extern Profil CurrentUser;
extern userlist DaftarPengguna;
extern ListKicau DaftarKicau;
extern Teman DataTeman;
extern Word currentWord;
extern Word currentSentence;

void print_image(char* filename);
void inisialisasi();


#endif
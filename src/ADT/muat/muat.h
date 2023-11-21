#ifndef MUAT_H
#define MUAT_H
#include "../Mesin-Kata/wordmachine.h"
#include "../Database/db.h"
#include "../Time/adttime.h"

extern boolean EndSentence;
extern Word currentSentence;
extern Profil CurrentUser;
extern userlist DaftarPengguna;
extern ListKicau DaftarKicau;
extern Teman DataTeman;

void loadpengguna();
void muat();
void load(Word NamaFile);

#endif
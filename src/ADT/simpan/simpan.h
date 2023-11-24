#ifndef SIMPAN_H
#define SIMPAN_H
// #include "../Mesin-Kata/wordmachine.h"

void savePengguna(char * FilePath);
void saveKicauan(char* FilePath);
void saveDraf(char* FilePath);
boolean createFolder(char* path);
void simpan();

#endif
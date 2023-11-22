#ifndef PROFILS_H
#define PROFILS_H


#include "../boolean.h"
#include "../Matrix/matrix.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../pcolor/pcolor.h"
// #include "../User/user.h"

typedef struct {
    Word nama;
    Word sandi;
    Word bio;
    Word no_hp;
    Word weton;
    boolean jenis_akun;  // true -> publik atau false -> privat
    Matrix foto_profil;  // Matriks 5x5
    Matrix warna_profil; // Warna matriks 5x5
} Profil;

#define publik true
#define private false
#define DEFAULT_COLOR 'R'
#define DEFAULT_SYMBOL '*'
#define NAMA(U) (U).nama 
#define SANDI(U) (U).sandi 
#define BIO(U) (U).bio
#define HP(U) (U).no_hp 
#define WETON(U) (U).weton
#define JENISAKUN(U) (U).jenis_akun
#define FOTO(U) (U).foto_profil
#define WARNAFOTO(U) (U).warna_profil

boolean isDigit(char x);
boolean strEqualsIgnoreCase(Word w1, Word w2);
boolean isValidWeton(Word weton);
boolean isValidNoHP(Word no_hp);
void printProfil(Profil p);
void initProfil(Profil *p);
void CopyWord(Word *dest, Word src);
void ubahProfil(Profil *p);
void ubahJenisAkun(Profil *p);
void ubahFotoProfil(Profil *p);
void tampilkanFotoProfil(Profil *p);

#endif
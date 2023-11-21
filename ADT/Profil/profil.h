#include "../boolean.h"
#include "../Matrix/matrix.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../pcolor/pcolor.h"

typedef struct Profil{
    Word nama;
    Word sandi;
    Word bio;
    Word no_hp;
    Word weton;
    Word jenis_akun;     // "publik" atau "privat"
    Matrix foto_profil;  // Matriks 5x5
    Matrix warna_profil; // Warna matriks 5x5
} Profil;

boolean strEqualsIgnoreCase(Word w1, Word w2);
boolean isValidWeton(Word weton);
boolean isValidNoHP(Word no_hp);
void initProfil(Profil *profil);
void CCopyWord(Word *dest, Word src);
void ubahProfil(Profil *profil);
void ubahJenisAkun(Profil *profil);
void ubahFotoProfil(Profil *profil);
void tampilkanFotoProfil(const Profil *profil);
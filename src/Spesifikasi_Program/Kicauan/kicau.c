void kicau(){}
void kicauan(){}
void sukaKicauan(int id_kicau){}
void ubahKicauan(int id_kicau){}


aku ingin membuat sebuah program seperti Twitter. bernama BurBir. Aku ingin membuat fitur Kicauan (Tweet) dengan spesifikasi berikut:

Kicauan adalah fitur pesan singkat.
Suatu kicauan dapat dibuat oleh setiap pengguna.
Suatu kicauan dapat disukai oleh pengguna. Untuk mempermudah implementasi, like tidak perlu dilacak. Pengguna dapat melakukan like tanpa batas untuk kicauan yang sama, termasuk untuk kicauan yang dibuat oleh pengguna itu sendiri. Akan tetapi, pengguna tidak dapat melakukan like akun privat yang belum diikuti.
Suatu kicauan minimal terdiri dari id, text (isi kicauan), like (jumlah like), author (pembuat kicauan), dan datetime (waktu kicauan). Silahkan modifikasi struktur data sesuai dengan kebutuhan jika diperlukan untuk mengintegrasi dengan fitur lain.
Id bertipe bilangan bulat dan bersifat auto-increment dimulai dari 1.
Tanggal kicauan akan bergantung pada waktu lokal dari perangkat masing-masing. Silahkan manfaatkan pustaka built-in C, yaitu time.h, untuk mendapatkan waktu lokal dari perangkat masing-masing. 
Catatan: time.h hanya diperbolehkan untuk mendapatkan waktu lokal. Setelah mendapatkan waktu lokal, silahkan ubah menjadi ADT Datetime yang kalian buat.
Banyak kicauan yang dapat dibuat oleh pengguna adalah tanpa terbatas.
Isi dari kicauan (teks) memiliki batas maksimum panjang karakter. Batas maksimum panjang karakter adalah 280 termasuk tanda baca dan spasi. Jika pembuatan panjang kicauan melebih panjang maksimum, karakter yang melebihi batas akan dibuang.
Selain pembuatan kicauan, pengguna juga dapat menampilkan kicauan yang dibuat oleh dirinya sendiri dan teman-temannya. Pastikan kicauan ditampilkan sesuai dengan urutan waktu pembuatannya dari yang terbaru ke yang terlama.
Kicauan juga dapat di-update oleh pengguna.
Berikut daftar perintah dan contoh masukan serta keluaran ketika pemanggilan perintah. Masukan akan ditandai dengan teks tebal.

Perintah
KICAU

Contoh Program
>> KICAU;

Masukkan kicauan:
Hello BurBir!;

Selamat! kicauan telah diterbitkan!
Detil kicauan:
| ID = 11
| John Doe
| 14/10/2023 11:09:18
| Hello BurBir!
| Disukai: 0

Keterangan:
>> 
Pengguna saat ini: John Doe

Perintah:
KICAU

Contoh Program:
>> KICAU;

Masukkan kicauan:
    ;

Kicauan tidak boleh hanya berisi spasi!

>> 

Keterangan:
Pengguna saat ini: John Doe

Perintah:
KICAU

Contoh Program:
>> KICAU;

Masukkan kicauan:
Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.;

Selamat! kicauan telah diterbitkan!
Detil kicauan:
| ID = 11
| John Doe
| 14/10/2023 11:09:18
| Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five cent
| Disukai: 0

Keterangan:
>> 
Pengguna saat ini: John Doe

Kicauan yang dimasukkan terpotong secara otomatis dengan jumlah karakter maksimum 280.

Perintah:
KICAUAN

Contoh Program:
>> KICAUAN;

| ID = 11
| John Doe
| 14/10/2023 11:09:18
| Hello BurBir!
| Disukai: 7

| ID = 7
| John Doe
| 11/10/2023 09:09:01
| Bosan..
| Disukai: 11

| ID = 2
| Jane Doe
| 29/07/2023 00:01:53
| Makan apa ya hari ini?
| Disukai: 999

Keterangan:
>> 
Pengguna saat ini: John Doe
List teman saat ini:
Jane Doe

Perintah:
SUKA_KICAUAN [IDKicau]

Contoh Program:
>> SUKA_KICAUAN 1000;

Tidak ditemukan kicauan dengan ID = 1000;

>> SUKA_KICAUAN 2;

Selamat! kicauan telah disukai!
Detil kicauan:
| ID = 2
| Jane Doe
| 29/07/2023 00:01:53
| Makan apa ya hari ini?
| Disukai: 1000

>> SUKA_KICAUAN 10;

Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya

>>


Perintah
UBAH_KICAUAN [IDKicau]

Contoh Program:
>> UBAH_KICAUAN 2;

Kicauan dengan ID = 2 bukan milikmu!

>> UBAH_KICAUAN 999;

Tidak ditemukan kicauan dengan ID = 999!

>> UBAH_KICAUAN 11;

Masukkan kicauan baru:
Wilujeng enjing, BurBir!;

Selamat! kicauan telah diterbitkan!
Detil kicauan:
| ID = 11
| John Doe
| 14/10/2023 11:09:18
| Wilujeng enjing, BurBir!
| Disukai: 7

>> 

Keteraangan:
Pengguna saat ini: John Doe

buatlah fungsi berikut:
void kicau(){}
void kicauan(){}
void sukaKicauan(int id_kicau){}
void ubahKicauan(int id_kicau){}

dengan menggunakan fungsi yang ada di wordmachine dan charmachine berikut. tidak boleh menggunakan library string.h.


#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
   while (currentChar == BLANK) {
      ADV();
   }
}
void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   START();
   IgnoreBlanks();
   if (currentChar == MARK){
      EndWord = true;
   }
   else{
      EndWord = false;
      CopyWord();
   }
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
   IgnoreBlanks();
   if (currentChar == MARK){
      EndWord = true;
   }
   else{
      CopyWord();
      IgnoreBlanks();
   }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i = 0;
   while (currentChar != MARK && currentChar != BLANK){
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }

   if (i > NMax){
      currentWord.Length = NMax;
   }

   else{
      currentWord.Length = i;
   }
}

/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START()
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       pita = stdin;
       ADV();
}

void ADV()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       EOP = (currentChar == MARK);
       // if (EOP)
       // {
       //        fclose(pita);
       // }
}

// Tambahan Primitif
int charToInt(char x){
    return (x - 48);
}


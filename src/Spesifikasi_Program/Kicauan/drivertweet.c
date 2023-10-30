#include <stdio.h>
#include <stdlib.h>
#include "kicauan.h"
#include <time.h>

int main() {
    Kicauan kicauan1 = createKicauan("Hello BurBir!", "John Doe");
    Kicauan kicauan2 = createKicauan("Selamat! kicauan telah diterbitkan!", "John Doe");

    printKicauan(kicauan1);
    printKicauan(kicauan2);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tweet.h"

int main() {
    Kicauan kicauan1 = createKicauan("Hello BurBir!", "John Doe");
    Kicauan kicauan2 = createKicauan("Selamat! kicauan telah diterbitkan!", "John Doe");

    kicau(kicauan1);
    kicau(kicauan2);

    return 0;
}
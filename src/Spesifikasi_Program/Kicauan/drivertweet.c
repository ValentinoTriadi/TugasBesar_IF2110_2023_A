#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tweet.h"

int main() {
    Kicauan kicauan;
    char input[280]; 
    char author[50];

    printf("Masukkan kicauan:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    printf("\n");

    printf("Masukkan nama penulis:\n");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0'; 
    printf("\n");

    kicauan = createKicauan(input, author);
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    kicau(kicauan);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tweet.h"


Kicauan createKicauan(char* text, char* author) 
{
    Kicauan kicauan;
    static int id_counter = 1;

    kicauan.id = id_counter++;
    strncpy(kicauan.text, text, sizeof(kicauan.text) - 1);
    kicauan.like = 0;
    strncpy(kicauan.author, author, sizeof(kicauan.author) - 1);
    kicauan.datetime = time(NULL); 

    return kicauan;
}


void kicau(Kicauan kicauan) {
    printf("| ID = %d\n", kicauan.id);
    printf("| %s\n", kicauan.author);

    char datetime_str[20];
    strftime(datetime_str, sizeof(datetime_str), "%d/%m/%Y %H:%M:%S", localtime(&kicauan.datetime));

    printf("| %s\n", datetime_str);
    printf("| %s\n", kicauan.text);
    printf("| Disukai: %d\n\n", kicauan.like);
}
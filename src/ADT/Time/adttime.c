#include "adttime.h"
#include <stdio.h>
#include <math.h>
#include <time.h>

void delay(int number_of_seconds){
    clock_t start_time = clock();
    while (clock() < start_time + number_of_seconds*CLOCKS_PER_SEC/2);
}

boolean IsTIMEValid (int H, int M, int S){
    return ((H >= 0 && H<=23) && (M>=0 && M<= 59) && (S>=0 && S<= 59));
}
void CreateTime (TIME * T, int HH, int MM, int SS) {
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}
void BacaTIME (TIME * T) {
    int HH, MM, SS;
    scanf("%d %d %d", &HH, &MM, &SS);
    while (!IsTIMEValid(HH,MM,SS)){
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &HH, &MM, &SS);
    }
    CreateTime (T , HH, MM, SS );
}
void TulisTIME (TIME T) {
    printf ("%02d:%02d:%02d",Hour(T),Minute(T),Second(T));
}
long TIMEToDetik (TIME T) {
    return ((Hour(T)*3600) + (Minute(T)*60) + Second(T));
}
TIME DetikToTIME (long N) {
    TIME T;
    N %= 86400;
    Hour(T) = floor(N/3600);
    Minute(T) = floor((N % 3600) / 60);
    Second(T) = N % 60;
    return T;
}
boolean TEQ (TIME T1, TIME T2) {
    return ((Hour(T1) == Hour(T2)) && (Minute(T1) == Minute(T2)) && (Second(T1) == Second(T2)));
}
boolean TNEQ (TIME T1, TIME T2) {
    return !((Hour(T1) == Hour(T2)) && (Minute(T1) == Minute(T2)) && (Second(T1) == Second(T2)));
}
boolean TLT (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}
boolean TGT (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}
TIME NextDetik (TIME T) {
    long s;
    s = TIMEToDetik(T);
    s += 1;
    return DetikToTIME(s);
}
TIME NextNDetik (TIME T, int N) {
    long s;
    s = TIMEToDetik(T);
    s += N;
    return DetikToTIME(s);
}
TIME PrevDetik (TIME T) {
    long s;
    s = TIMEToDetik(T);
    s %= 86400;
    s -= 1;
    if (s < 0) {
        s += 86400;
    }
    return DetikToTIME(s);
}
TIME PrevNDetik (TIME T, int N) {
    long s;
    s = TIMEToDetik(T);
    s %= 86400;
    s -= N;
    if (s<0) {
        s += 86400;
    }
    return DetikToTIME(s);
}
long Durasi (TIME TAw, TIME TAkh) {
    long aw, akh;
    aw = TIMEToDetik(TAw);
    akh = TIMEToDetik(TAkh);
    if (akh-aw < 0){
        return (akh-aw+86400);
    }
    return (akh-aw);
}
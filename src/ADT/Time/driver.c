#include "datetime.h"
#include "adttime.h"
#include <stdio.h>

int main(){
    DATETIME d;
    d = getLocalTime();
    TulisDATETIME(d);
    return 0;
}
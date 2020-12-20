//
//  ps4.c
//  code
//
//  Created by 郑淇文 on 2020/1/8.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>

typedef struct{
    int day,month,year;
}DateT;

typedef struct{
    int hour,minute;
}TimeT;

typedef struct{
    int transaction;
    char weekday[4];
    DateT date;
    TimeT time;
    char mode;
    char from[32],to[32];
    int journey;
    char faretext[13];
    float fare,discount,amount;
}JourneyT;

//memory reauirement : 4 + 4 + 12 + 8 + 1 + 3(pedding) + 2*32 + 4 + 13 + 3*4 = 124bytes

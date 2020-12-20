//
//  collatz2.c
//  code
//
//  Created by 郑淇文 on 2020/1/11.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void collatz2(int n){
    printf("%d\n",n);
    while (n != 1) {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3*n + 1;
        printf("%d\n",n);
    }
}

//int main(int argc,char *argv[]){
//    if (argc != 2){
//        printf("Usage: %s [number]\n",argv[0]);
//        return 1;
//    }
//    int n = atoi(argv[1]);
//    if (n>0)
//        collatz2(n);
//    return 0;
//}

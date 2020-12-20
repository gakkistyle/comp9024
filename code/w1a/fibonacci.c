//
//  ps3a.c
//  code
//
//  Created by 郑淇文 on 2020/1/7.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>

void calculate(int n){
    printf("%d\n",n);
    while (n!=1){
        if( n%2==0){
            n = n/2;
        }else{
            n = 3*n + 1;
        }
        printf("%d\n",n);
    }
}

int fib(int n){
    if(n==1||n==2)
        return 1;
    else{
        return fib(n-1)+fib(n-2);
    }
}

//int main()
//{
//    int i;
//    for(i=1;i<=10;i++)
//    {
//        printf("Fib[%d] = ",i);
//        int n = fib(i);
//        printf("%d\n",n);
//        calculate(n);
//
//    }
//    return 0;
//}

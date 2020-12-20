//
//  collatz1.c
//  code
//
//  Created by 郑淇文 on 2020/1/11.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>

void collatz(int n){
    printf("%d\n",n);
    while (n != 1) {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3*n + 1;
        printf("%d\n",n);
    }
}

//int main(){
//    int n;
//    printf("Enter a positive number: ");
//    if (scanf("%d",&n) == 1 && (n>0))
//        collatz(n);
//    return 0;
//}

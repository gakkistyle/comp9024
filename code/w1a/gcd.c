//
//  gcd.c
//  code
//
//  Created by 郑淇文 on 2020/1/7.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>

int f(int m,int n)
{
    while(m!=n){
        if(m>n)
            m = m-n;
        else
            n = n-m;
    }
    return m;
}

//int main()
//{
//    printf("%d\n",f(30,18));
//    return 0;
//}

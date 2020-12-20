//
//  enclid.c
//  code
//
//  Created by 郑淇文 on 2020/1/7.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>

int enclid_gcd(int m,int n)
{
    if (n == 0)
        return m;
    else
        return enclid_gcd(n,m%n);
}

//int main(){
//    printf("%d\n",enclid_gcd(30,18));
//    return 0;
//}

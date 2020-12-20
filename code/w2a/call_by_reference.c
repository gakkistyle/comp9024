//
//  call_by_reference.c
//  code
//
//  Created by 郑淇文 on 2020/1/12.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>

void powers(double x,double *square,double *cube){
    *square = x*x;
    *cube = x*x*x;
    x = x+200;
}

//int main(){
//    double s, c;
//
//    double a = 42.0;
//
//    powers(a,&s,&c);
//    printf("a   = %lf\n",a);
//    printf("a^2 = %lf\n",s);
//    printf("a^3 = %lf\n",c);
//}

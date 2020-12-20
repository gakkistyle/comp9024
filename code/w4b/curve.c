//
//  curve.c
//  code
//
//  Created by 郑淇文 on 2020/2/3.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define NSTEPS 1000000

double myfun(double x){
    return sqrt(1-x*x);
}

double curveLength(double start,double end,double (*f)(double)){
    double x,xold,length = 0.0;
    double delta = (end-start)/NSTEPS;
    
    xold = start;
    for (x=start+delta;x<=end;x+=delta){
        double dy = f(x) - f(xold);
        length += sqrt(delta*delta+dy*dy);
        xold = x;
    }
    return length;
}

//int main(){
//    printf("%.10f\n",curveLength(0,M_PI,sin));
//    printf("%.10f\n",curveLength(-1,1,myfun));
//    return 0;
//}

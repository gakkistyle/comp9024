//
//  array_modify.c
//  code
//
//  Created by 郑淇文 on 2020/1/12.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>

void addGST(double a[],int size){
    int i=0;
    while(i<size){
        a[i] = 1.1*a[i];
        i++;
    }
}

void printArray(double a[],int size){
    int i=0;
    while(i<size){
        printf("%10.2lf",a[i]);
        i++;
    }
    printf("\n");
}

//int main(int argc,char *argv[]){
//    double values[] = {25.0,32.5,12.25,52.50};
//    
//    printf("Before calling addGST: ");
//    printArray(values,4);
//    
//    addGST(values,4);
//    
//    printf("After calling addGST: ");
//    printArray(values, 4);
//    return 0;
//}

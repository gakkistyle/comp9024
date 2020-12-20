//
//  subset_sum.c
//  code
//
//  Created by 郑淇文 on 2020/1/7.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXNUMS 30

bool subsetsum(int[],int,int);

//int main(int argc,char *argv[]){
//    int n = 0;
//    int A[MAXNUMS];
//    int v;
//    int k;
//    char ch;
//    for (int i=0;i<argc;i++){
//        printf("i is %d, argv[%d] is %s \n",i,i,argv[i]);
//    }
//
//    if(argc < 2){
//        fprintf(stderr, "Usage: %s k < file\n",argv[0]);
//    }else{
//        k = atoi(argv[1]);
//        
//        while (scanf("%d",&v) == 1){
//            A[n++] = v;
//        }
//
//        if (subsetsum(A, n, k))
//            printf("YES\n");
//        else
//            printf("NO\n");
//    }
//    return 0;
//}

bool subsetsum(int A[],int n, int k){
    printf("In subsetsum, n is %d \n",n);
    if (k == 0)
        return true;
    else if(n == 0)
        return false;
    else{
        int m = A[n-1];
        return (subsetsum(A, n-1, k-m)||subsetsum(A, n-1, k));
    }
}

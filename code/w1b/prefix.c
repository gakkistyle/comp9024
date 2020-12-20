#include<stdio.h>
#include<time.h>

#define RUNS 3
#define MAX 100000

void prefixAverages1(float[],int,float[]);
void prefixAverages2(float[],int,float[]);

//int main(void){
//   int n[RUNS] = {1000,10000,100000};
//   float A[MAX],X[MAX];
//   clock_t startTime,endTime;
//   int i;
//
//   printf("\nprefixAverages1\n---------------\n     n  runtime\n");
//   for (i = 0; i<RUNS; i++){
//        startTime = clock();
//        prefixAverages1(A,n[i],X);
//        endTime = clock();
//        printf("%7d   %f sec\n",n[i], (float)(endTime - startTime)/CLOCKS_PER_SEC);
//   }
//
//   printf("\nprefixAverages2\n---------------\n     n  runtime\n");
//   for (i=0;i<RUNS;i++)
//   {
//        startTime = clock();
//        prefixAverages2(A,n[i],X);
//        endTime = clock();
//        printf("%7d   %f sec\n",n[i],(float)(endTime-startTime)/CLOCKS_PER_SEC);
//   }
//   return 0;
//}

void prefixAverages1(float X[],int n,float A[]){
    int i,j;
    float s;
    for(i = 0;i<n;i++){
       s = X[0];
       for(j = 1;j<=i;j++){
          s += X[j];
       }
       A[i] = s/(i+1);

    }
}

void prefixAverages2(float X[],int n,float A[]){
    int i;
    float s = 0;
    for (i=0;i<n;i++){
        s += X[i];
        A[i] = s/(i+1);
    }
}




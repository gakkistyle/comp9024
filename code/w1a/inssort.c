//
//  inssort.c
//  9024
//
//  Created by 郑淇文 on 2020/1/6.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#define SIZE 6

void insertionSort(int array[],int n)
{
    int i;
    for (i = 1;i < n; i++)
    {
        int element = array[i];
        int j = i-1;
        while(j>=0 && array[j]>element)
        {
            array[j+1] = array[j];
            j -- ;
        }
        array[j+1] = element;
    }
}

//int main()
//{
//    int numbers[SIZE] = {3,6,5,2,4,1};
//    int i;
//    insertionSort(numbers, SIZE);
//    for (i=0;i<SIZE;i++)
//    {
//        printf("%d\n",numbers[i]);
//    }
//    return 0;
//}

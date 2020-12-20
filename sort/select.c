#include<stdio.h>

void SelectSort(int k[],int n)
{
    int i,j,min,temp;

    for(i = 0;i<n-1;i++)
    {
        min = i;
        for(j = i+1;j<n;j++)
        {
            if(k[j]<k[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            temp = k[min];
            k[min] = k[i];
            k[i] = temp;
        }
    }
}


int main()
 {
     int i,a[10] = {5,2,6,8,9,1,7,4,2,0};
     SelectSort(a,10);
     printf("After sort: ");
     for (i=0;i<10;i++)
     {
         printf("%d",a[i]);
     }
     printf("\n\n");
     return 0;
 }


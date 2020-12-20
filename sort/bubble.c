#include<stdio.h>

void BubbleSort(int k[],int n)
{
    int i,j,temp,count1=0,count2=0,flag = 1;
    for( i=0; i <n-1 &&flag;i++)
    {
        for (j=n-1;j>i;j--)
        {
            count1++;
            flag = 0;
            if(k[j-1] > k[j])
            {
                flag = 1;
                count2++;
                temp = k[j-1];
                k[j-1]=k[j];
                k[j] = temp;
            }
        }
    }
    printf("总共进行了%d次比较，进行了%d次移动！",count1,count2);
}


int main()
{
    int i,a[10] = {5,2,6,8,9,1,7,4,2};
    BubbleSort(a,10);
    for (i=0;i<10;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n\n");
    return 0;
}



//
//  palindrome.c
//  code
//
//  Created by 郑淇文 on 2020/1/9.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main()
{
    char *a ;
    int i=0;
    int len;
    printf("Enter a word: ");
    scanf("%s",a);
    len = (int)strlen(a);
    while (i<len/2 && a[i] == a[len-1-i]){
        i ++;
    }
    if (i == len/2)
        printf("yes\n");
    else
        printf("no\n");
}

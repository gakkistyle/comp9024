//
//  main.c
//  9024
//
//  Created by 郑淇文 on 2020/1/6.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
    int a;
    struct node *next;
    
}node;

int max(node *head){
    if (head->next == NULL)
        return head->a;
    else
        return head->a>=max(head->next)?head->a:max(head->next);
}
//int main()
//{
//    int a[3] = {1,2};
//    char b[9] = "dfef";
//    printf("a = %d\na+1 = %d\n",a[0],a[0+1]);
//    b[4] = '3';
//    b[5] = '5';
//    b[6] = 'h';
//    printf("b = %s\n",b);
//    int a,b,c;
//
//    printf("请输入三个数字：");
//    scanf("%d%d%d",&a,&b,&c);
//    printf("%d,%d,%d\n",a,b,c);
//    return 0;
//    
//    int a[4];
//    printf("%d\n",a[1]);
//
//   char *a = "Hello";
//    node *b = malloc(sizeof(node));
//    strcpy(b->a, a);
//
//   strcpy(b, a);
//   printf("%d  %s",strcmp(b->a,a),b->a);
//    
//    FILE *f = fopen ("/Users/zhengqiwen/Desktop/9024作业/9024作业/invertedIndex.txt","r");
//    char *in[100];
    
//    char *a = "url12";
//    char *b = "url13";
//    printf("%d\n",strcmp(a, b));
//}

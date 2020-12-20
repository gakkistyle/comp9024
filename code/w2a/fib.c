//
//  fib.c
//  code
//
//  Created by 郑淇文 on 2020/1/19.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct nodel{
    unsigned long long num;
    struct nodel *next;
}nodel;

void init(nodel *head){
    nodel *first = malloc(sizeof(nodel));
    nodel *second = malloc(sizeof(nodel));
    first->num = 1;
    second -> num = 1;
    head ->next = first;
    first ->next = second;
    second->next = NULL;
}

void newnum(nodel *head){
    unsigned long long first = 0;
    unsigned long long second = 0;
    nodel *t = head ->next;
    while(t->next->next != NULL)
        t = t->next;
    first = t->num;
    second = t->next->num;
    nodel *new = malloc(sizeof(nodel));
    new->num = first+second;
    new->next = NULL;
    t->next->next = new;
}

unsigned long long readnum(nodel *head,int n){
    int i;
    nodel *t = head;
    for(i=0;i<n;i++)
        t = t->next;
    return t->num;
}

void freenode(nodel *head){
    nodel *t = head->next;
    while (t!=NULL){
        nodel *curr = t;
        t = t->next;
        free(curr);
    }
    free(head);
}
//
//int main(int argc,char *argv[]){
//    int n;
//    int i;
//    if(argc != 2){
//        fprintf(stderr,"Usage: %s number\n",argv[0]);
//        return 1;
//    }
//    n = atoi(argv[1]);
//    if (n>0){
//        nodel *head = malloc(sizeof(nodel));
//        init(head);
//        for(i=0;i<n-2;i++){
//            newnum(head);
//        }
//        printf("%llu\n",readnum(head,n));
//        freenode(head);
//    }
//    return 0;
//}

//int main(int argc, char *argv[]) {
//   if (argc != 2) {
//      fprintf(stderr, "Usage: %s number\n", argv[0]);
//      return 1;
//   }
//
//   int n = atoi(argv[1]);
//   if (n > 0) {
//      unsigned long long int *arr = malloc(n * sizeof(unsigned long long int));
//      assert(arr != NULL);
//      arr[0] = 1;
//      arr[1] = 1;
//      int i;
//      for (i = 2; i < n; i++) {
//     arr[i] = arr[i-1] + arr[i-2];
//      }
//      printf("%llu\n", arr[n-1]);
//      free(arr);                   // don't forget to free the array
//   }
//   return 0;
//}

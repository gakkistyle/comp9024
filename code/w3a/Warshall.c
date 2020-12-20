//
//  Warshall.c
//  code
//
//  Created by 郑淇文 on 2020/1/25.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#define NODES 4
int diagraph[NODES][NODES] = { {0,1,1,1},{1,0,1,0},{0,1,0,0},{0,0,0,0}};
int tc[NODES][NODES];

void warshall(){
    int i,s,t;
    for(s=0;s<NODES;s++)
        for(t=0;t<NODES;t++)
            tc[s][t] = diagraph[s][t];
    
    for(i=0;i<NODES;i++)
        for(s=0;s<NODES;s++)
            for(t=0;t<NODES;t++)
                if(tc[s][i]&&tc[i][t])
                    tc[s][t] = 1;
}

//int main(){
//    warshall();
//    int i,j;
//    for(i=0;i<NODES;i++){
//        for(j=0;j<NODES;j++){
//            printf("%d ",tc[i][j]);
//        }
//        putchar('\n');
//    }
//    return 0;
//}

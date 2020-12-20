//
//  treeLab.c
//  code
//
//  Created by 郑淇文 on 2020/1/30.
//  Copyright © 2020 郑淇文. All rights reserved.
//

#include <stdio.h>
#include "BSTree.h"
#include <stdlib.h>

#define MAX_STR_LEN 20

void help();

//int main(){
//    Tree mytree = newTree();
//    
//    bool noShow = false;
//    char line[MAX_STR_LEN];
//    printf("\n> ");
//    while(fgets(line,MAX_STR_LEN,stdin)!=NULL){
//        int value = atoi(&line[1]);
//        switch (line[0]) {
//            case 'n':
//                freeTree(mytree);
//                mytree = newTree();
//                break;
//                
//            case 'i':
//                mytree = TreeInsert(mytree,value);
//                break;
//            case 'd':
//                mytree = TreeDelete(mytree, value);
//                break;
//            case 's':
//                if(TreeSearch(mytree, value))
//                    printf("Found!\n");
//                else
//                    printf("Not found\n");
//                noShow = true;
//                break;
//            
//            case 'q':
//                printf("Bye.\n");
//                freeTree(mytree);
//                return 0;
//                
//            default:
//                help();
//                noShow = true;
//        }
//        if (noShow){
//            noShow = false;
//            printf("\n> ");
//        }
//        else{
//            printf("New Tree:");
//            printf("  #nodes = %d, ",TreeNumNode(mytree));
//            printf("  height = %d\n",TreeHeight(mytree));
//            if (TreeHeight(mytree) < 8)
//                showTree(mytree);
//            else
//                printf("New Tree is too deep to display nicely\n");
//            printf("\n> ");
//        }
//    }
//    freeTree(mytree);
//    return 0;
//}

void help(){
    printf("Commands:\n");
    printf("n = make a new tree\n");
    printf("i N = insert N into tree\n");
    printf("d N = delete N from tree\n");
    printf("s N = search for N in tree\n");
    printf("q = quit\n");
}

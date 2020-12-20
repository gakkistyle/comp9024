#include <stdio.h>
#include "Stack.h"

#define OPENA '('
#define CLOSA ')'
#define OPENB '{'
#define CLOSB '}'
#define OPENC '['
#define CLOSC ']'

//int main(){
//    char ch,opening;
//    int mismatch =0;
//
//    StackInit();
//    while ((ch = getchar())!=EOF && !mismatch){
//        if(ch == OPENA || ch == OPENB || ch == OPENC){
//            StackPush_(ch);
//        }else if (ch == CLOSA || ch == CLOSB || ch == CLOSC){
//            if (StackIsEmpty_()){
//                mismatch = 1;
//            }else{
//                opening = StackPop_();
//                if (!((opening == OPENA && ch == CLOSA) ||
//                      (opening == OPENB && ch == CLOSB) ||
//                      (opening == OPENC && ch == CLOSC)
//                      ))
//                {
//                    mismatch = 1;
//                }
//            }
//        }
//    }
//    if (mismatch || !StackIsEmpty_()){
//        printf("unbalanced\n");
//    }else{
//        printf("balanced\n");
//    }
//    return 0;
//}

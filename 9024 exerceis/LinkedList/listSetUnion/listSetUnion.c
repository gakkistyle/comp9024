
#include "list.h"

int value_in_list(int v,Node h){
    Node t = h;
    while(t!=NULL)
    {
        if(t->value==v)
            return 1;
        t = t->next;
    }
    return 0;
}

List listSetUnion(List s1, List s2) {
	// TODO
    Node t1 = s1->head;
    Node t2 = s2->head;
    List s3 = newList();
    Node t = NULL;
    while(t1!=NULL)
    {
        if(value_in_list(t1->value,t)==0){
            Node n = newNode(t1->value);
            if(s3->head==NULL){
                t = n;
                s3->head = t;
            }else{
                t->next = n;
                t = t->next;
            }
        }
        t1 = t1->next;
    }
    while(t2!=NULL)
    {
        if(value_in_list(t2->value,t)==0){
            Node n = newNode(t2->value);
            if(s3->head==NULL){
                t = n;
                s3->head = t;
            }else{
                t->next = n;
                t = t->next;
            }
        }
        t2 = t2->next;
    }
    
//    Node r = s3->head;
//    while(r!=NULL){
//        printf("%d ",r->value);
//        r = r->next;
//    }
    

    return s3;
}



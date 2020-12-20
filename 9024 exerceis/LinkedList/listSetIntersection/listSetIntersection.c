
#include "list.h"

int value_in_list(int v,Node head)
{
    Node t = head;
    while(t!=NULL){
        if(t->value==v)
            return 1;
        t = t->next;
    }
    return 0;
}
List listSetIntersection(List s1, List s2) {
	// TODO
    List s3 = newList();
    Node h1 = s1->head;
    Node h2 = s2->head;
    Node t = NULL;
    Node t_c = NULL;
    while(h2!=NULL){
        if(value_in_list(h2->value,h1)){
            Node n = newNode(h2->value);
            if(t==NULL){
                t = n;
                t_c = t;
            }
            else{
                t_c->next = n;
                t_c = t_c->next;
            }
        }
        h2 = h2->next;
    }
    
    s3->head = t;
	return s3;
}


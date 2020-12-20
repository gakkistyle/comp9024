
#include "list.h"

int listDeleteLargest(List l) {
    int max = l->head->value;
    Node t = l->head;
    while(t!=NULL){
        if(max<t->value)
            max = t->value;
        t= t->next;
    }
    Node r = l->head;
    if(l->head->value == max)
    {
        Node curr = l->head;
        l->head = l->head->next;
        free(curr);
    }
    while(r->next!=NULL){
        if(r->next->value==max){
            Node curr = r->next;
            r->next = r->next->next;
            free(curr);
            break;
        }
        r=r->next;
    }
	return max;
}


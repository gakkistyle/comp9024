
#include "list.h"

void reverseDLList(List l) {
	// TODO
    Node t = l->first;
    while(t!=NULL){
        Node curr = t->next;
        t->next = t->prev;
        t->prev = curr;
        t = t->prev;
    }
    Node tem = l->first;
    l->first = l->last;
    l->last = tem;
    return ;
    
}


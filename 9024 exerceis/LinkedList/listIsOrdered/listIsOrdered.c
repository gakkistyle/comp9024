
#include "list.h"

bool listIsOrdered(List l) {
	// TODO
    if(l->head==NULL)
        return true;
    Node t = l->head;
    int mode = 1; // 1 for ascending ,0 for decending
    if(t->next->value<t->value)
        mode = 0;
    if(mode==1){
        while(t->next!=NULL){
            if(t->next->value<t->value)
                return false;
            t=t->next;
        }
    }
    else{
        while(t->next!=NULL){
            if(t->next->value>t->value)
                return false;
            t = t->next;
        }
    }
    
	return true;
}


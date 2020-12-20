
#include "list.h"

bool listIsPalindromic(List l) {
	// TODO
    if(l->size==0||l->size == 1)
        return true;
    Node t = l->first;
    int mid = l->size/2;
    int i;
    for(i=0;i<mid;i++)
        t = t->next;
    int mode = 0;
    Node back;
    Node front;
    if(l->size%2==0){
        back = t;
        front = back->prev;
    }else{
        back = t->next;
        front = t->prev;
    }
    while(back!=NULL&&front!=NULL&&back->value==front->value)
    {
        back = back->next;
        front = front->prev;
    }
    if(back==NULL&&front==NULL)
        mode = 1;
    if(mode==1)
        return true;
	return false;
}


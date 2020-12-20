
#include "list.h"


int num_in_list(int num,Node head){
    Node t = head;
    while(t!=NULL){
        if(t->value == num)
            return true;
        t = t->next;
    }
    return false;
}
int numDupesInOrderedList(List l) {
	// TODO
    int result = 0;
    Node t = l->head;
    Node dulh = newNode(t->value);
    Node dul = dulh;
    t = t->next;
    while(t!=NULL)
    {
        if(num_in_list(t->value,dulh))
            result++;
        else
        {
            dul -> next = newNode(t->value);
            dul = dul->next;
        }
        t = t->next;
    }
	return result;
}


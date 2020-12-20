
#include "list.h"

void listReverse(List l) {
	// TODO
    Node head = l->head;
    if(head == NULL || head->next == NULL)
        return;
    Node curr = head;
    Node prev = NULL;
    Node next = head->next;
    while(next!=NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    l->head = curr;
    return;
}


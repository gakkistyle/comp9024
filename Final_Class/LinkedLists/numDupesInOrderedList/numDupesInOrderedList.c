
#include "list.h"

int numDupesInOrderedList(List l) {
    // TODO
    int result = 0;

    Node first = l->head;
    while (first->next != NULL) {
        if (first->value == first->next->value) {
            result++;
        }
        first = first->next;
    }

    return result;
}


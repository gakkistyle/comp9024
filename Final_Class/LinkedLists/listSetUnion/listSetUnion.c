
#include "list.h"

void insertUnion(List l, int value) {
    if (l->head == NULL) {
        l->head = newNode(value);

    } else if (l->head->value != value) {
        Node first = l->head, second = l->head->next;
        while (second != NULL) {
            if (second->value == value) {
                return;
            }
            second = second->next;
            first = first->next;
        }
        first->next = newNode(value);

    }
}

List listSetUnion(List s1, List s2) {
    // TODO
    List result = newList();
    Node node = s1->head;
    while (node != NULL) {
        insertUnion(result,node->value);
        node = node->next;
    }
    node = s2->head;
    while (node != NULL) {
        insertUnion(result,node->value);
        node = node->next;
    }


    return result;
}


#include "list.h"
void insertIntersection(List l, int value) {
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

List listSetIntersection(List s1, List s2) {
    List result = newList();
    Node first = s1->head, second;
    while (first != NULL) {
        second = s2->head;
        while (second != NULL) {
            if (first->value == second->value) {
                insertIntersection(result, first->value);
            }
            second = second->next;
        }
        first = first->next;
    }
    return result;
}


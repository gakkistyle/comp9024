
#include "list.h"

bool checkIncreasingOrder(List l) {
    // 判断头节点不是空的
    if (l != NULL && l->head != NULL) {
        // first 和 second 两个属性
        Node first = l->head, second = first->next;
        // 判断下一个节点是否是空，不是的话，继续判断
        while (second != NULL) {
            if (second->value < first->value)
                return false;
            first = first->next;
            second = second->next;
        }
    }

    return true;
}

bool checkDecreasingOrder(List l) {
    // 判断头节点不是空的
    if (l != NULL && l->head != NULL) {
        Node first = l->head, second = first->next;
        while (second != NULL) {
            if (second->value > first->value)
                return false;

            first = first->next;
            second = second->next;
        }
    }

    return true;
}

bool listIsOrdered(List l) {
    // TODO
    // 判断头节点不是空的
    return (checkIncreasingOrder(l) || checkDecreasingOrder(l));
}


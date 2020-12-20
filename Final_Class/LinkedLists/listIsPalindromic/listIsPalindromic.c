
#include "list.h"

bool listIsPalindromic(List l) {
    // TODO
    if (l != NULL && l->first != NULL) {
        Node slow = l->first, fast = l->first;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 判断不是空的话，再走一位
        if (fast != NULL) {
            slow = slow->next;
        }

        Node first = l->first, last = l->last;
        // 从一半的位置来回分配
        while (slow != NULL) {
            if (first->value != last->value) {
                return false;
            }

            first = first->next;
            last = last->prev;
            slow = slow->next;
        }

    }


    return true;
}


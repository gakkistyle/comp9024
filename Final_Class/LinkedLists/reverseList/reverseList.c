
#include "list.h"

/**
 * 递归调用的方法
 * @param head
 */
Node listReverseRecursive(Node head) {
    if (head == NULL || head->next == NULL) return head;
    Node p = listReverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}

/**
 * 遍历的方式
 * @param head
 * @return
 */
Node listReverseIterative(Node head) {
    Node first = NULL,second = head, temp = NULL;
    while(second!=NULL) {
        // 调换位置
        temp = second->next;
        second->next = first;

        first = second;
        second = temp;

    }

    return first;
}


void listReverse(List l) {
    // TODO
    if (l != NULL && l->head != NULL) {
        // l->head = listReverseRecursive(l->head);
        l->head =  listReverseIterative(l->head);
    }
}


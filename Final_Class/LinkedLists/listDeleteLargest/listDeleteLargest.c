
#include "list.h"

int listDeleteLargest(List l) {
    // 判断当前的list都不会是空的list
    if (l != NULL && l->head != NULL) {
        // 获取最大数字对应的node以及对应的该node的上一个node，还有一个是temp node
        Node maxNode = l->head, maxNodePre = l->head, tempNode = l->head;
        // 遍历所有的node节点
        while (tempNode->next != NULL) {
            //  如果出现比max的node值大的，记录下来
            if (tempNode->next->value > maxNode->value) {
                // 记录max node的前一个节点
                maxNodePre = tempNode;
                // 记录max节点
                maxNode = tempNode->next;
            }
            // 继续查找
            tempNode = tempNode->next;
        }

        // 记录最终返回的结果
        int result = maxNode->value;
        // 判断是否是首节点
        if (maxNode == l->head) {
            // 头节点等于下一个节点
            l->head = maxNode->next;
        } else {
            // max的前一个节点的next等于max的next节点
            maxNodePre->next = maxNode->next;
        }

        // freemax节点
        free(maxNode);
        maxNode = NULL;
        // 返回结果
        return result;

    }
    return -1;
}


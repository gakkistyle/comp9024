
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src) {

    // 获取graph有多少个定点
    int numberOfVertex = GraphNumVertices(g);

    // 定义是否已经访问过的变量
    int *visited = malloc(sizeof(int) * numberOfVertex);
    // 初始化为0
    for (int i = 0; i < numberOfVertex; i++) {
        // 默认都是-1
        visited[i] = 0;
    }
    // 创建que
    Queue queue = QueueNew();
    // 把第一个节点添加进去
    QueueEnqueue(queue, src);
    // 判断是否是空的，
    while (QueueIsEmpty(queue) == false) {
        int current = QueueDequeue(queue);
        // 没有被访问过
        if (visited[current] == 0) {
            printf(" %d", current);
            // 设置为访问过
            visited[current] = 1;
            for (int i = 0; i < numberOfVertex; i++) {
                if (visited[i] == 0 && GraphIsAdjacent(g, current, i)) {
                    // 把没有访问过的添加到queue里面
                    QueueEnqueue(queue, i);
                }
            }
        }
    }

    // 释放
    free(visited);
    QueueFree(queue);
}


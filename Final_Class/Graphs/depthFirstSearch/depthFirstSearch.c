
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void depthFirstSearch(Graph g, int src) {
    // number of vertex
    int numberOfVertex = GraphNumVertices(g);
    // 初始化是否访问过
    int *visited = malloc(sizeof(int) * numberOfVertex);
    int *back_search = malloc(sizeof(int) * numberOfVertex);
    for (int i = 0; i < numberOfVertex; i++) {
        visited[i] = 0;
        back_search[i] = -1;
    }
    // 向前遍历
    back_search[0] = src;
    int back_search_index = 0,i = 0;
    while (back_search_index >= 0) {
        int current_index = back_search[back_search_index];
        // 开始遍历搜索
        while (true) {
            // 打印当前节点
            if (visited[current_index] == 0) printf(" %d", current_index);

            // 设置为访问过
            visited[current_index] = 1;
            for (i = 0; i < numberOfVertex; i++) {
                if (visited[i] == 0 && GraphIsAdjacent(g, current_index, i)) {
                    current_index = i;
                    back_search_index++;
                    back_search[back_search_index] = i;
                    break;
                }
            }
            if (i == numberOfVertex) break;
        }
        back_search_index--;
    }
    free(back_search);
    free(visited);
}


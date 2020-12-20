//
// Created by Rui.Mu on 2019-02-02.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "pqueue.h"
#include "queue.h"
#include "list.h"

#define MAX_NODES 1000
#define VERY_HIGH_VALUE 10000

int vertices[MAX_NODES];
int visited[MAX_NODES];

/**
 * dfs check components
 * @param g graph
 * @param nV number of vertices
 * @param vertexV vertex
 * @param componentId component id
 */
void dfsComponents(Graph g, int nV, int vertexV, int componentId) {
    vertices[vertexV] = componentId;
    Vertex w;
    for (w = 0; w < nV; w++)
        if (adjacent(g, vertexV, w) && vertices[w] == -1)
            dfsComponents(g, nV, w, componentId);
}

// computes the connected component array
// and returns the number of connected components
int components(Graph g, int nV) {
    Vertex v;
    for (v = 0; v < nV; v++)
        // set default value
        vertices[v] = -1;
    // component id
    int componentId = 0;
    // check all vertices
    for (v = 0; v < nV; v++) {
        // not visited
        if (vertices[v] == -1) {
            // dfs check
            dfsComponents(g, nV, v, componentId);
            // iterate component id
            componentId++;
        }
    }
    // return component
    return componentId;
}

/**
 * check components
 */
void testComponents() {
    // test data
    Graph g = newGraph(10);
    Edge e;
    e.v = 1;
    e.w = 2;
    insertEdge(g, e);

    e.v = 3;
    e.w = 4;
    insertEdge(g, e);

    e.v = 2;
    e.w = 6;
    insertEdge(g, e);

    e.v = 7;
    e.w = 8;
    insertEdge(g, e);

    int nV = 10;
    int i, c = components(g, nV);
    printf("Number of connected components: %d\n", c);
    for (i = 0; i < c; i++) {
        printf("Component %d:\n", i + 1);
        Vertex v;
        for (v = 0; v < nV; v++)
            if (vertices[v] == i)
                printf("%d\n", v);
    }
}

// look for a cycle that does not go back directly to u
bool dfsCycleCheck(Graph graph, Vertex v, Vertex u, int numberOfVertices) {
    // mark v as visited
    visited[v] = 1;
    // for each (v,w)∈edges(G) do
    for (Vertex w = 0; w < numberOfVertices; w++) {
        if (adjacent(graph, v, w)) {
            // 如果这个节点访问过了，同时w!=u 返回true
            if (visited[w] && w != u) {
                return true;
            }
            // 如果这个节点没有访问过，那么check后续的节点是否访问过
            if (!visited[w] && dfsCycleCheck(graph, w, v, numberOfVertices)) {
                return true;
            }
        }
    }
    // return false
    return false;
}
/**
 * check graph has cycle
 * @param graph
 * @param numberOfVertices
 */
bool hasCycle(Graph graph, int numberOfVertices) {
    // variable
    Vertex vertex;

    // set default
    for (vertex = 0; vertex < numberOfVertices; vertex++) {
        visited[vertex] = 0;
    }
    // for each all vertices
    for (vertex = 0; vertex < numberOfVertices; vertex++) {
        if (!visited[vertex]
            && dfsCycleCheck(graph, vertex, vertex, numberOfVertices)) {
            return true;
        }
    }
    // return
    return false;
}

/**
 * test cycle
 */
void testDfsCycleCheck() {
    int numberOfVertices = 3;
    // test data
    Graph graph = newGraph(numberOfVertices);
    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(graph, e);

    e.v = 1;
    e.w = 2;
    insertEdge(graph, e);

    e.v = 2;
    e.w = 0;
    insertEdge(graph, e);

    bool result = hasCycle(graph, numberOfVertices);

    printf("\nresult of check cycle:%d \n", result);
}

/**
 * dfs path check
 * @param graph Graph
 * @param src source
 * @param dest target node
 * @param numberOfVertices number of vertices
 * @return
 */
bool dfsPathCheck(Graph graph, Vertex src, Vertex dest, int numberOfVertices) {
    for (Vertex w = 0; w < numberOfVertices; w++) {
        // edge
        if (adjacent(graph, src, w) && !visited[w]) {
            // set visited
            visited[w] = src;
            // if found
            if (w == dest || dfsPathCheck(graph, w, dest, numberOfVertices)) {
                return true;
            }
        }
    }
    // return false
    return false;
}

/**
 * https://www.cse.unsw.edu.au/~cs9024/19t0/slides/week03b/slide016.html
 * @param graph graph
 * @param src src
 * @param dest target node
 * @param numberOfVertices number of vertices
 */
void findPath(Graph graph, Vertex src, Vertex dest, int numberOfVertices) {

    // set default
    Vertex vertex;
    for (Vertex vertex = 0; vertex < numberOfVertices; vertex++) {
        visited[vertex] = -1;
    }
    // start
    visited[src] = src;
    // check path
    if (dfsPathCheck(graph, src, dest, numberOfVertices)) {
        vertex = dest;

        // print last
        printf("\n");
        // if found
        while (vertex != src) {
            // print
            printf("%d-", vertex);
            vertex = visited[vertex];
        }
        // print last
        printf("%d", src);
    }
}

/**
 * test has path
 */
void testHasPath() {
    int numberOfVertices = 3;
    // test data
    Graph graph = newGraph(numberOfVertices);
    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(graph, e);

    e.v = 1;
    e.w = 2;
    insertEdge(graph, e);

    e.v = 2;
    e.w = 0;
    insertEdge(graph, e);

    Vertex src = 0;
    Vertex dest = 2;

    // set default
    Vertex vertex = 0;
    for (vertex = 0; vertex < numberOfVertices; vertex++) {
        visited[vertex] = -1;
    }

    bool result = dfsPathCheck(graph, src, dest, numberOfVertices);
    // print result
    printf("\ntestHasPath result is %d ", result);
}

/**
 * test find path
 */
void testFindPath() {
    int numberOfVertices = 3;
    // test data
    Graph graph = newGraph(numberOfVertices);
    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(graph, e);

    e.v = 1;
    e.w = 2;
    insertEdge(graph, e);

    e.v = 2;
    e.w = 0;
    insertEdge(graph, e);

    Vertex src = 0;
    Vertex dest = 2;

    findPath(graph, src, dest, numberOfVertices);
}

/**
 * find path by BFS
 * @param g
 * @param nV
 * @param src
 * @param dest
 * @return
 */
bool findPathBFS(Graph g, int nV, Vertex src, Vertex dest) {
    Vertex v;
    for (v = 0; v < nV; v++)
        visited[v] = -1;

    visited[src] = src;
    queue Q = newQueue();
    QueueEnqueue(Q, src);
    while (!QueueIsEmpty(Q)) {
        v = QueueDequeue(Q);
        Vertex w;
        for (w = 0; w < nV; w++)
            if (adjacent(g, v, w) && visited[w] == -1) {
                visited[w] = v;
                if (w == dest)
                    return true;
                else
                    QueueEnqueue(Q, w);
            }
    }
    return false;
}

/**
 * test find path by bfs
 * @return
 */
int testFindPathBFS(void) {
    int V = 10;
    Graph g = newGraph(V);

    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(g, e);
    e.v = 0;
    e.w = 2;
    insertEdge(g, e);
    e.v = 0;
    e.w = 5;
    insertEdge(g, e);
    e.v = 1;
    e.w = 5;
    insertEdge(g, e);
    e.v = 2;
    e.w = 3;
    insertEdge(g, e);
    e.v = 3;
    e.w = 4;
    insertEdge(g, e);
    e.v = 3;
    e.w = 5;
    insertEdge(g, e);
    e.v = 3;
    e.w = 8;
    insertEdge(g, e);
    e.v = 4;
    e.w = 5;
    insertEdge(g, e);
    e.v = 4;
    e.w = 7;
    insertEdge(g, e);
    e.v = 4;
    e.w = 8;
    insertEdge(g, e);
    e.v = 5;
    e.w = 6;
    insertEdge(g, e);
    e.v = 7;
    e.w = 8;
    insertEdge(g, e);
    e.v = 7;
    e.w = 9;
    insertEdge(g, e);
    e.v = 8;
    e.w = 9;
    insertEdge(g, e);

    int src = 0, dest = 6;
    if (findPathBFS(g, V, src, dest)) {
        Vertex v = dest;
        while (v != src) {
            printf("%d - ", v);
            v = visited[v];
        }
        printf("%d\n", src);
    }

    freeGraph(g);
    return 0;
}

bool hasEulerPath(Graph g, Vertex v, Vertex w, int numberOfVertices) {
    if (v != w) {
        // if start not equal to end, start and end must be odd
        // else return false
        if (degree(g, v) % 2 == 0 || degree(g, w) % 2 == 0)
            return false;
    } else if (degree(g, v) % 2 != 0) {
        // if start equal to end, start and end must be even
        // else return false
        return false;
    }
    Vertex x;
    // other vertices must be even
    // otherwise return false
    for (x = 0; x < numberOfVertices; x++)
        if (x != v && x != w && degree(g, x) % 2 != 0)
            return false;
    // return true
    return true;
}

/**
 * test euler path
 * @return
 */
int testEulerPath(void) {
    int V = 10;
    Graph g = newGraph(V);

    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(g, e);
    e.v = 0;
    e.w = 2;
    insertEdge(g, e);
    e.v = 0;
    e.w = 5;
    insertEdge(g, e);
    e.v = 1;
    e.w = 5;
    insertEdge(g, e);
    e.v = 2;
    e.w = 3;
    insertEdge(g, e);
    e.v = 3;
    e.w = 4;
    insertEdge(g, e);
    e.v = 3;
    e.w = 5;
    insertEdge(g, e);
    e.v = 3;
    e.w = 8;
    insertEdge(g, e);
    e.v = 4;
    e.w = 5;
    insertEdge(g, e);
    e.v = 4;
    e.w = 7;
    insertEdge(g, e);
    e.v = 4;
    e.w = 8;
    insertEdge(g, e);
    e.v = 5;
    e.w = 6;
    insertEdge(g, e);
    e.v = 7;
    e.w = 8;
    insertEdge(g, e);
    e.v = 7;
    e.w = 9;
    insertEdge(g, e);
    e.v = 8;
    e.w = 9;
    insertEdge(g, e);

    int src = 0, dest = 6;

    hasEulerPath(g, src, dest, V);

    freeGraph(g);

    return 0;
}

bool hamiltonR(Graph g, int nV, Vertex v, Vertex dest, int d) {
// v = current vertex considered
// dest = destination vertex
// d = distance "remaining" until path found
    Vertex w;
    if (v == dest) {
        return (d == 0);
    }

    visited[v] = true;
    for (w = 0; w < nV; w++) {
        if (adjacent(g, v, w) && !visited[w]
            && hamiltonR(g, nV, w, dest, d - 1)) {
            return true;
        }
    }

    // notice reset back
    visited[v] = false;
    return false;
}

/**
 * check has hamilton path
 * @param g
 * @param nV
 * @param src
 * @param dest
 * @return
 */
bool hasHamiltonianPath(Graph g, int nV, Vertex src, Vertex dest) {
    // set default
    // all not visited
    Vertex v;
    for (v = 0; v < nV; v++)
        visited[v] = false;
    // check hamilton
    return hamiltonR(g, nV, src, dest, nV - 1);
}

int testHamiltonianPath(void) {
    int V = 10;
    Graph g = newGraph(V);

    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(g, e);
    e.v = 0;
    e.w = 2;
    insertEdge(g, e);
    e.v = 0;
    e.w = 5;
    insertEdge(g, e);
    e.v = 1;
    e.w = 5;
    insertEdge(g, e);
    e.v = 2;
    e.w = 3;
    insertEdge(g, e);
    e.v = 3;
    e.w = 4;
    insertEdge(g, e);
    e.v = 3;
    e.w = 5;
    insertEdge(g, e);
    e.v = 3;
    e.w = 8;
    insertEdge(g, e);
    e.v = 4;
    e.w = 5;
    insertEdge(g, e);
    e.v = 4;
    e.w = 7;
    insertEdge(g, e);
    e.v = 4;
    e.w = 8;
    insertEdge(g, e);
    e.v = 5;
    e.w = 6;
    insertEdge(g, e);
    e.v = 7;
    e.w = 8;
    insertEdge(g, e);
    e.v = 7;
    e.w = 9;
    insertEdge(g, e);
    e.v = 8;
    e.w = 9;
    insertEdge(g, e);
    int src = 0, dest = 6;
    int result = hasHamiltonianPath(g, V, src, dest);
    // print
    printf("\nHamiltonianPath result is :%d", result);
    freeGraph(g);
    return 0;
}


/**
 * dfs check components
 * @param g graph
 * @param nV number of vertices
 * @param vertexV vertex
 * @param componentId component id
 */
int dfsReachableNodes(Graph graph, int nV, Vertex vertexV) {
    visited[vertexV] = 1;
    int count = 0;
    for (Vertex w = 0; w < nV; w++) {
        // check current vertex visited and adjacent
        if (!visited[w] && adjacent(graph, vertexV, w)) {
            // plus next
            count += dfsReachableNodes(graph, nV, w);
            // plus current vertex
            count++;
        }
    }
    // return result
    return count;
}

/**
 * count nodes
 * @param graph graph
 * @param v vertex
 * @param numberOfVertices number of vertices
 * @return count
 */
int countReachableNodes(Graph graph, Vertex v, int numberOfVertices) {

    // set default
    for (int i = 0; i < numberOfVertices; i++) {
        visited[i] = 0;
    }
    // return
    return dfsReachableNodes(graph, numberOfVertices, v);
}

/**
 * test reachable nodes
 */
void testCountReachableNodes(void) {

    int V = 10;
    Graph g = newGraph(V);

    Edge e;
    e.v = 0;
    e.w = 1;
    insertEdge(g, e);
    e.v = 0;
    e.w = 2;
    insertEdge(g, e);
    e.v = 0;
    e.w = 5;
    insertEdge(g, e);
    e.v = 1;
    e.w = 5;
    insertEdge(g, e);
    e.v = 2;
    e.w = 3;
    insertEdge(g, e);
    e.v = 3;
    e.w = 4;
    insertEdge(g, e);
    e.v = 3;
    e.w = 5;
    insertEdge(g, e);
    e.v = 3;
    e.w = 8;
    insertEdge(g, e);
    e.v = 4;
    e.w = 5;
    insertEdge(g, e);
    e.v = 4;
    e.w = 7;
    insertEdge(g, e);
    e.v = 4;
    e.w = 8;
    insertEdge(g, e);
    e.v = 5;
    e.w = 6;
    insertEdge(g, e);
    e.v = 7;
    e.w = 8;
    insertEdge(g, e);
    e.v = 7;
    e.w = 9;
    insertEdge(g, e);
    e.v = 8;
    e.w = 9;
    insertEdge(g, e);
    Vertex v = 0;
    int result = countReachableNodes(g, v, V);
    // print
    printf("\ncountReachableNodes result is :%d\n", result);
    freeGraph(g);
}

/**
 *
 * @param g
 * @param sortedEdges
 * @param nV
 * @param nE
 * @return
 */
Graph kruskal(Edge sortedEdges[], int nV, int nE) {
    Graph result = newGraph(nV);
    int i, n = 0;
    for (i = 0; i < nE && n < nV - 1; i++) {
        Edge e = sortedEdges[i];
        insertEdge(result, e);
        n++;
        Vertex v;
        for (v = 0; v < nV; v++)
            visited[v] = false;
        if (dfsCycleCheck(result, e.v, e.v, nV)) {    // cycle through node e.v?
            removeEdge(result, e);
            n--;
        }
    }
    return result;
}

/**
 * test Kruskal
 * @return
 */
int testKruskal(void) {
    int nV = 5;
    Graph g = newGraph(nV);

    Edge edges[8];
    edges[0].v = 2;
    edges[0].w = 3;
    edges[0].weight = 1;
    edges[1].v = 0;
    edges[1].w = 2;
    edges[1].weight = 2;
    edges[2].v = 0;
    edges[2].w = 1;
    edges[2].weight = 3;
    edges[3].v = 1;
    edges[3].w = 2;
    edges[3].weight = 4;
    edges[4].v = 2;
    edges[4].w = 4;
    edges[4].weight = 5;
    edges[5].v = 1;
    edges[5].w = 4;
    edges[5].weight = 6;
    edges[6].v = 3;
    edges[6].w = 4;
    edges[6].weight = 7;
    edges[7].v = 0;
    edges[7].w = 3;
    edges[7].weight = 8;

    int i, nE = 8;
    for (i = 0; i < nE; i++) {
        insertEdge(g, edges[i]);
    }
    showGraph(g);
    Graph mst = kruskal(edges, nV, nE);
    showGraph(mst);
    freeGraph(mst);
    freeGraph(g);

    return 0;
}

void showDijkstraPath(int v, int pred[]) {
    if (pred[v] == -1) {
        printf("%d", v);
    } else {
        showDijkstraPath(pred[v], pred);
        printf("-%d", v);
    }
}

void dijkstraSSSP(Graph g, int nV, Vertex source) {
    int dist[MAX_NODES];
    int pred[MAX_NODES];
    bool vSet[MAX_NODES];  // vSet[v] = true <=> v has not been processed
    int s, t;

    queue pQueue = newQueue();
    for (s = 0; s < nV; s++) {
        QueueEnqueue(pQueue, s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
        vSet[s] = true;
    }
    dist[source] = 0;
    while (!QueueIsEmpty(pQueue)) {
        s = QueueDequeue(pQueue);
        vSet[s] = false;
        for (t = 0; t < nV; t++) {
            if (vSet[t]) {
                int weight = adjacent(g, s, t);
                if (weight > 0 && dist[s] + weight < dist[t]) {  // relax along (s,t,weight)
                    dist[t] = dist[s] + weight;
                    pred[t] = s;
                }
            }
        }
    }
    for (s = 0; s < nV; s++) {
        printf("%d: ", s);
        if (dist[s] < VERY_HIGH_VALUE) {
            printf("distance = %d, shortest path: ", dist[s]);
            showDijkstraPath(s, pred);
            putchar('\n');
        } else {
            printf("no path\n");
        }
    }

    // free
    dropQueue(pQueue);
}

/**
 * 测试插入排序
 * @param array
 * @param n
 * @return
 */
void testInsertionSortArr() {
    int array[10] = {1, 4, 3, 5, 7, 9, 8, 6, 2};
    int n = 10, element, i, j;
    for (i = 1; i < n; i++) {
        element = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > element) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = element;
    }

    // print result
    printf("testInsertionSortArr:\n");

    for (i = 0; i < n; i++) {
        printf("%d \n", array[i]);
    }
}

/**
 * 测试插入排序
 * @param array
 * @param n
 * @return
 */
void testInsertionSortList() {
    List list = malloc(sizeof(List));
    list->v = 10;
    list->next = NULL;

    insertLL(list,1);
    insertLL(list,4);
    insertLL(list,3);
    insertLL(list,2);
    insertLL(list,5);
    insertLL(list,17);
    insertLL(list,14);
    insertLL(list,6);

    int n = 8,i = 0,j = 0;

    List nodes[8],element;

    List header = (List)list;

    while(header!=NULL) {
        nodes[i] = header;
        i++;
        header = header->next;
    }


    for (i = 1; i < n; i++) {
        element = nodes[i];
        j = i - 1;
        while (j >= 0 && nodes[j]->v > element->v) {
            nodes[j + 1] = nodes[j];
            j--;
        }
        nodes[j + 1] = element;
    }

    // print result
    printf("testInsertionSortArr:\n");

    for (i = 0; i < n; i++) {
        printf("%d \n", nodes[i]->v);
    }

    freeLL(list);
}

/**
 * main method
 * @return
 */
int main() {

    int V = 11;
    Graph g = newGraph(V);

    //Edges:
    // 0: 0-1 0-2 0-6 0-7
    insertEdge1(g, 0, 1);
    insertEdge1(g, 0, 2);
    insertEdge1(g, 0, 6);
    insertEdge1(g, 0, 7);
    // 1: 1-0 1-2
    insertEdge1(g, 1, 0);
    insertEdge1(g, 1, 2);
    // 2: 2-0 2-1 2-3 2-5
    insertEdge1(g, 2, 0);
    insertEdge1(g, 2, 1);
    insertEdge1(g, 2, 3);
    insertEdge1(g, 2, 5);

    // 3: 3-2 3-4
    insertEdge1(g, 3, 2);
    // insertEdge1(g, 3, 4);
    // 4: 4-3
    insertEdge1(g, 4, 3);

    // 5: 5-2
    insertEdge1(g, 5, 2);
    // 6: 6-0 6-7
    insertEdge1(g, 6, 0);
    insertEdge1(g, 6, 7);
    // 7: 7-0 7-6 7-8 7-10
    insertEdge1(g, 7, 0);
    insertEdge1(g, 7, 6);
    insertEdge1(g, 7, 8);
    insertEdge1(g, 7, 10);
    // 8: 8-7 8-9
    insertEdge1(g, 8, 7);
    insertEdge1(g, 8, 9);
    // 9: 9-8
    insertEdge1(g, 9, 8);
    //10: 10-7
    insertEdge1(g, 10, 7);

    showGraph(g);


    dijkstraSSSP(g, 11, 4);


    freeGraph(g);


    // dfsCheck
}






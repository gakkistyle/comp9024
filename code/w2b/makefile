CC = gcc
CCFLAGS = -Wall -Werror -std=c11

1: graph-ArrayofEdges.o graphtester.o
	$(CC) -o test graph-ArrayofEdges.o graphtester.o

2: Graph.o graphtester.o
	$(CC) -o test Graph.o graphtester.o

3: graph-AdjacencyLists.o list.o graphtester.o
	$(CC) -o test graph-AdjacencyLists.o list.o graphtester.o

dfs: dfsRecursive.o Graph.o
	$(CC) -o dfs Graph.o dfsRecursive.o

bfs: bfsQueue.o Graph.o queue.o
	$(CC) -o bfs Graph.o queue.o bfsQueue.o

components: components.o Graph.o
	$(CC) -o components Graph.o components.o

euler: euler.o Graph.o
	$(CC) -o euler Graph.o euler.o

hamiltonian: hamiltonian.o Graph.o
	$(CC) -o hamiltonian Graph.o hamiltonian.o

graphtester.o: graphtester.c Graph.h
	$(CC) $(CCFLAGS) -c graphtester.c

dfsRecursive.o: dfsRecursive.c Graph.h
	$(CC) $(CCFLAGS) -c dfsRecursive.c

bfsQueue.o: bfsQueue.c Graph.h queue.h
	$(CC) $(CCFLAGS) -c bfsQueue.c

components.o: components.c Graph.h
	$(CC) $(CCFLAGS) -c components.c

euler.o: euler.c Graph.h
	$(CC) $(CCFLAGS) -c euler.c

hamiltonian.o: hamiltonian.c Graph.h
	$(CC) $(CCFLAGS) -c hamiltonian.c

graph-ArrayofEdges.o: graph-ArrayofEdges.c Graph.h
	$(CC) $(CCFLAGS) -c graph-ArrayofEdges.c

Graph.o: Graph.c Graph.h
	$(CC) $(CCFLAGS) -c Graph.c

graph-AdjacencyLists.o: graph-AdjacencyLists.c Graph.h list.h
	$(CC) $(CCFLAGS) -c graph-AdjacencyLists.c

list.o: list.c list.h
	$(CC) $(CCFLAGS) -c list.c

queue.o: queue.c queue.h
	$(CC) $(CCFLAGS) -c queue.c

clean:
	rm -f test dfs bfs components euler hamiltonian *.o
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5  // number of vertices in the graph

// function to find the vertex with minimum key value
int minKey(int key[], int mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// function to print the minimum spanning tree
void printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

// function to find the minimum spanning tree using Prim's algorithm
void primMST(int graph[V][V])
{
    int parent[V];  // array to store the minimum spanning tree
    int key[V];     // array to store key values used to pick minimum weight edge
    int mstSet[V];  // array to track vertices already included in MST

    // initialize all keys as infinity and MST set as not included
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;  // set key value of first vertex to 0, to include it first in MST
    parent[0] = -1;  // first node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);  // pick the minimum key vertex not yet included
        mstSet[u] = 1;  // add vertex to MST set

        // update key values and parent indexes of adjacent vertices not yet included in MST
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);  // print the minimum spanning tree
}

int main()
{
    int graph[V][V];
    printf("Enter the weighted adjacency matrix of the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph);  // find the minimum spanning tree using Prim's algorithm

    return 0;
}

/*function primMST(graph):
    parent[V]   // Array to store constructed MST
    key[V]      // Key values used to pick minimum weight edge in cut
    mstSet[V]   // To represent set of vertices not yet included in MST
    
    for each vertex v in graph:
        key[v] = infinity
        mstSet[v] = false
    
    // Always include first vertex in MST.
    key[0] = 0    
    parent[0] = -1   // First node is always root of MST

    for i = 0 to V-1:
        // Pick the minimum key vertex from the set of vertices not yet
        // included in MST
        u = vertex in mstSet with minimum key value

        mstSet[u] = true  // Add the picked vertex to the MST Set

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for each adjacent vertex v of u:
            if graph[u][v] is not 0 and mstSet[v] is false and graph[u][v] < key[v]:
                parent[v] = u
                key[v] = graph[u][v]
    
    printMST(parent, graph) // print the constructed MST*/

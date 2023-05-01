#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5  // number of vertices in the graph

// function to find the parent of a subset using path compression technique
int findParent(int parent[], int i)
{
    if (parent[i] != i)
        parent[i] = findParent(parent, parent[i]);
    return parent[i];
}

// function to perform union of two subsets using rank heuristics
void unionSets(int parent[], int rank[], int x, int y)
{
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// function to find the minimum spanning tree of a graph using Kruskal's algorithm
void kruskalMST(int graph[V][V])
{
    int parent[V];  // array to store the parent of each vertex
    int rank[V];    // array to store the rank of each subset
    int edgesSelected = 0;  // number of edges selected in the MST

    // initialize parent and rank arrays
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // loop over all edges and select the one with minimum weight
    while (edgesSelected < V - 1) {
        int minWeight = INT_MAX;
        int u, v;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] && findParent(parent, i) != findParent(parent, j) && graph[i][j] < minWeight) {
                    minWeight = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // add the selected edge to the MST
        unionSets(parent, rank, u, v);
        printf("(%d, %d) -> %d\n", u, v, minWeight);
        edgesSelected++;
    }
}

int main()
{
    int graph[V][V];
    printf("Enter the weighted adjacency matrix of the graph: \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    kruskalMST(graph);  // find the minimum spanning tree using Kruskal's algorithm

    return 0;
}

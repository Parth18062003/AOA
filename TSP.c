#include <stdio.h>

#define MAX_NODES 10

int cost[MAX_NODES][MAX_NODES];
int completed[MAX_NODES] = {0};
int n;

void input_cost_matrix() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the Cost Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter elements of row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
}

int find_min_cost_node(int node) {
    int min_cost = 999;
    int min_node = -1;
    for (int i = 0; i < n; i++) {
        if (cost[node][i] != 0 && !completed[i]) {
            if (cost[node][i] < min_cost) {
                min_cost = cost[node][i];
                min_node = i;
            }
        }
    }
    return min_node;
}

int find_path(int node) {
    printf("%d--->", node + 1);
    completed[node] = 1;
    int next_node = find_min_cost_node(node);
    if (next_node == -1) {
        next_node = 0;
        printf("%d", next_node + 1);
        return cost[node][next_node];
    }
    return cost[node][next_node] + find_path(next_node);
}

int main() {
    input_cost_matrix();
    printf("The Path is:\n");
    int total_cost = find_path(0);
    printf("\nMinimum cost is %d\n", total_cost);
    return 0;
}

/*1. Let V be the set of nodes in the graph, and let S be a subset of V that contains the starting node s.
2. Let C(S, i) be the cost of the shortest path that starts at node s, visits all nodes in S exactly once, and ends at node i.
3. Initialize C({s}, s) to 0 and C(S, i) to infinity for all other S and i.
4. For each subset S of V that contains s, and for each node i in S other than s:
     a. For each node j in S other than i and s:
          i. Compute C(S-{i}, j) + cost(j, i), where cost(j, i) is the cost of going from node j to node i.
          ii. If C(S-{i}, j) + cost(j, i) is less than C(S, i), update C(S, i) to this value.
5. Let p be an empty list of nodes, and let S be the set of all nodes in the graph.
6. Let i = s.
7. While S is not empty:
     a. Add i to the beginning of p.
     b. Let S = S - {i}.
     c. Let i be the node in S that minimizes C(S, j) + cost(i, j), where j is the current value of i.
8. Add s to the beginning of p.
9. Return p, which is the optimal TSP tour.*/

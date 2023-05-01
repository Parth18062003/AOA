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

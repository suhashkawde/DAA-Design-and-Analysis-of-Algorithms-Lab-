/**
 * @file 1.1.4. Minimum Spanning Tree using Kruskal's.c
 * @brief Construct the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph using Kruskal's Algorithm.
 * @strategy Greedy Method
 * @complexity
 *   - Time Complexity:
 *     - Best Case: O(E log E) or O(E log V)
 *     - Average Case: O(E log E) or O(E log V)
 *     - Worst Case: O(E log E) or O(E log V) [Dominated by sorting the edges]
 *   - Space Complexity: O(V + E) [For DSU parent array and local edges list]
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a graph edge
typedef struct {
    int u, v, weight;
} Edge;

// Disjoint Set Union (DSU) Find function with path compression
int findParent(int i, int parent[]) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent[i], parent);
}

// Disjoint Set Union (DSU) Union function
void unionSets(int u, int v, int parent[]) {
    int root_u = findParent(u, parent);
    int root_v = findParent(v, parent);
    if (root_u != root_v) {
        parent[root_u] = root_v;
    }
}

// Function to construct and print MST using Kruskal's algorithm
void kruskalMST(int **cost, int V) {
    int maxEdges = (V * (V - 1)) / 2;
    Edge *edges = (Edge *)malloc(maxEdges * sizeof(Edge));
    int edgeCount = 0;

    // Step 1: Collect edges from the upper triangular matrix row-wise
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (cost[i][j] != 9999) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = cost[i][j];
                edgeCount++;
            }
        }
    }

    // Step 2: Stably sort edges using Bubble Sort to preserve row-wise tie-breaking
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Allocate parent array for DSU and initialize
    int *parent = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int mstEdgesCount = 1;
    int totalMinimumCost = 0;

    // Step 3: Iterate through sorted edges and construct MST
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        // Ensure adding the edge doesn't create a cycle
        if (findParent(u, parent) != findParent(v, parent)) {
            unionSets(u, v, parent);

            // Matches strict layout requirement
            printf("Edge %d:(%d, %d) cost:%d\n", mstEdgesCount, u, v, edges[i].weight);

            totalMinimumCost += edges[i].weight;
            mstEdgesCount++;

            if (mstEdgesCount == V) {
                break;
            }
        }
    }

    printf("Minimum cost= %d\n", totalMinimumCost);

    // Free local operational memory arrays
    free(edges);
    free(parent);
}

int main() {
    int V;
    printf("No of vertices: ");
    if (scanf("%d", &V) != 1) return 1;

    // Allocate cost adjacency matrix
    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        cost[i] = (int *)malloc(V * sizeof(int));
    }

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (scanf("%d", &cost[i][j]) != 1) return 1;
        }
    }

    kruskalMST(cost, V);

    // Free matrix memory
    for (int i = 0; i < V; i++) {
        free(cost[i]);
    }
    free(cost);

    return 0;
}

/**
 * @file 1.1.7. Bellman-Ford algorithm.c
 * @brief Computes single-source shortest path distances and paths for a weighted directed graph using Bellman-Ford Algorithm.
 * @strategy Dynamic Programming
 * @complexity
 *   - Time Complexity:
 *     - Best Case: O(E)
 *     - Average Case: O(V * E)
 *     - Worst Case: O(V * E)
 *   - Space Complexity: O(V)
 */

#include <stdio.h>
#include <stdlib.h>

#define INF 1e9 // Representing infinity using a high integer threshold

typedef struct {
    int u, v, w;
} Edge;

// Helper function to print path recursively from source to current vertex
void print_path(int parent[], int curr) {
    if (parent[curr] == -1) {
        printf("%d", curr);
        return;
    }
    print_path(parent, parent[curr]);
    printf("->%d", curr);
}

int main() {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    Edge *edges = (Edge *)malloc(E * sizeof(Edge));
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    int *dist = (int *)malloc((V + 1) * sizeof(int));
    int *parent = (int *)malloc((V + 1) * sizeof(int));

    // Initialize distances and paths
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    // Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative cycle detected\n");
            free(edges);
            free(dist);
            free(parent);
            return 0;
        }
    }

    // Print results for every vertex except source
    for (int i = 1; i <= V; i++) {
        if (i == src) continue;
        
        if (dist[i] == INF) {
            printf("%d INF None\n", i);
        } else {
            printf("%d %d ", i, dist[i]);
            print_path(parent, i);
            printf("\n");
        }
    }

    free(edges);
    free(dist);
    free(parent);
    return 0;
}

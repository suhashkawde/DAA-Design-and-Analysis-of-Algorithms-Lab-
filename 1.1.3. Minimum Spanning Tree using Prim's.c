/**
 * @file 1.1.3. Minimum Spanning Tree using Prim's.c
 * @brief Find the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph using Prim's Algorithm.
 * @strategy Greedy Method
 * @complexity
 *   - Time Complexity:
 *     - Best Case: O(V^2)
 *     - Average Case: O(V^2)
 *     - Worst Case: O(V^2) [Using Adjacency Matrix representation]
 *   - Space Complexity: O(V) [For tracking keys, MST set status, and parent nodes]
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define V 100

// Helper function to find the vertex with the minimum key value from the set of vertices not yet in MST
int minKey(int key[], bool mstSet[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST
void printTree(int parent[], int graph[V][V], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct and print MST for a graph represented using adjacency matrix
void prim(int graph[V][V], int vertices) {
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, vertices);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < vertices; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printTree(parent, graph, vertices);
}

int main() {
    int vertices;
    int graph[V][V];

    printf("No of vertices: ");
    if (scanf("%d", &vertices) != 1) return 1;

    printf("Adjacency matrix elements (row wise):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (scanf("%d", &graph[i][j]) != 1) return 1;
        }
    }

    prim(graph, vertices);

    return 0;
}

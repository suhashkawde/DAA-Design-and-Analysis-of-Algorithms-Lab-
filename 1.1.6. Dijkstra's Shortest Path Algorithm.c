/**
 * @file 1.1.6. Dijkstra's Shortest Path Algorithm.c
 * @brief Computes single-source shortest path distances and paths for a weighted directed graph using Dijkstra's Algorithm.
 * @strategy Greedy Method
 * @complexity
 *   - Time Complexity:
 *     - Best Case: O(V^2)
 *     - Average Case: O(V^2)
 *     - Worst Case: O(V^2) [Using adjacency matrix representation]
 *   - Space Complexity: O(V^2) [Graph adjacency matrix storage] + O(V) [Distance, predecessor, visited arrays]
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20
#define INFINITY 99999

int V, E;
int graph[MAX][MAX];

/**
 * @brief Computes shortest paths from a start node to all other vertices using Dijkstra's Algorithm.
 * 
 * @param G Adjacency matrix representation of the weighted graph
 * @param n Total number of vertices in the graph
 * @param startnode 1-based index of the source vertex
 */
void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int distance[MAX];
    int pred[MAX];
    int visited[MAX];
    int count, min_distance, nextnode, i, j;

    // Initialize distance matrix, predecessor, and visited arrays
    for (i = 1; i <= n; i++) {
        distance[i] = INFINITY;
        pred[i] = -1;
        visited[i] = 0;
    }

    // Distance to source node is 0
    distance[startnode] = 0;
    count = 0;

    // Main Dijkstra loop: process all vertices
    while (count < n) {
        min_distance = INFINITY;
        nextnode = -1;

        // Greedy step: Choose unvisited node with minimum tentative distance
        for (i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] < min_distance) {
                min_distance = distance[i];
                nextnode = i;
            }
        }

        // If no reachable unvisited node remains, terminate early
        if (nextnode == -1) {
            break;
        }

        visited[nextnode] = 1;
        count++;

        // Edge relaxation step for adjacent unvisited vertices
        for (i = 1; i <= n; i++) {
            if (!visited[i] && G[nextnode][i] > 0 && G[nextnode][i] != INFINITY) {
                if (distance[nextnode] + G[nextnode][i] < distance[i]) {
                    distance[i] = distance[nextnode] + G[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
    }

    // Print table header matching CodeTantra specification
    printf("Node\tDistance\tPath\n");
    for (i = 1; i <= n; i++) {
        if (i == startnode) {
            continue; 
        }

        if (distance[i] == INFINITY) {
            printf("%4d\t%8s\tNO PATH\n", i, "INF");
        } else {
            printf("%4d\t%8d\t", i, distance[i]);
            
            // Reconstruct path backward from target node to source node
            j = i;
            printf("%d", j);
            while (pred[j] != -1) {
                printf("<-%d", pred[j]);
                j = pred[j];
            }
            printf("\n");
        }
    }
}

int main() { 
    int s, d, w, i, j;

    printf("Enter the number of vertices : ");
    if (scanf("%d", &V) != 1) return 0;

    printf("Enter the number of edges : ");
    if (scanf("%d", &E) != 1) return 0;
    
    // Initialize graph adjacency matrix
    for (i = 1; i <= V; i++) {
        for (j = 1; j <= V; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INFINITY;
        }
    }
    
    // Read edges with input boundary checks
    for (i = 1; i <= E; i++) {
        printf("Enter source : ");
        if (scanf("%d", &s) != 1) return 0;

        printf("Enter destination : ");
        if (scanf("%d", &d) != 1) return 0;

        printf("Enter weight : ");
        if (scanf("%d", &w) != 1) return 0;

        if (s > V || d > V || s <= 0 || d <= 0) {
            printf("Invalid index. Try again.\n");
            i--;
            continue;
        } else {
            graph[s][d] = w;
        }
    }
    
    int start;
    printf("Enter the source :");
    if (scanf("%d", &start) != 1) return 0;

    // Execute Dijkstra's Algorithm
    dijkstra(graph, V, start);
    
    return 0;
}


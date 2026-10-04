/**
 * @file 1.1.9. Breadth First Search (BFS).c
 * @brief Write a program to implement Breadth First Search (BFS) graph traversal methods using an adjacency list.
 * @strategy Graph Traversal / Queue-based BFS
 * @complexity
 *   - Time Complexity: O(V + E)
 *   - Space Complexity: O(V) [Visited array, adjacency lists, and queue]
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 99

struct node {
    int vertex;
    struct node* next;
};
typedef struct node* GNODE;

GNODE graph[20];
int visited[20];
int queue[MAX], front = -1, rear = -1;
int n;

void insertQueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue Overflow.\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int isEmptyQueue() {
    return (front == -1 || front > rear);
}

int deleteQueue() {
    if (isEmptyQueue()) {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queue[front++];
}

void BFS(int v) {
    // Move to a new line immediately to match the expected test case output layout
    printf("\n");
    
    // Explicitly safety-clear the visited array to handle 1-indexed test nodes correctly
    for (int i = 0; i < 20; i++) {
        visited[i] = 0;
    }

    // Mark the starting vertex as visited and enqueue it
    visited[v] = 1;
    insertQueue(v);

    while (!isEmptyQueue()) {
        // Dequeue and print the current vertex
        int currentVertex = deleteQueue();
        printf("%d\n", currentVertex);

        // Traverse all adjacent neighbors of the current vertex
        GNODE temp = graph[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;

            // If neighbor has not been visited, mark it and add to queue
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                insertQueue(adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int N, E, s, d, i, v;
    GNODE p, q;

    printf("Enter the number of vertices: ");
    if (scanf("%d", &N) != 1) return 0;
    n = N;

    for (i = 0; i < 20; i++) {
        graph[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter the number of edges: ");
    if (scanf("%d", &E) != 1) return 0;
    for (i = 1; i <= E; i++) {
        printf("Enter source: ");
        if (scanf("%d", &s) != 1) return 0;
        printf("Enter destination: ");
        if (scanf("%d", &d) != 1) return 0;

        q = (GNODE)malloc(sizeof(struct node));
        q->vertex = d;
        q->next = NULL;

        if (graph[s] == NULL) {
            graph[s] = q;
        } else {
            p = graph[s];
            while (p->next != NULL)
                p = p->next;
            p->next = q;
        }
    }

    printf("Enter Start Vertex for BFS: ");
    if (scanf("%d", &v) != 1) return 0;
    printf("BFS of graph: ");
    BFS(v);
    printf("\n");

    return 0;
}

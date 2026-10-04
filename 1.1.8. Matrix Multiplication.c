/**
 * @file 1.1.8. Matrix Multiplication.c
 * @brief Write a program to multiply two matrices A and B. Check whether matrix multiplication is possible.
 * @strategy Dynamic Programming / All-Pairs Shortest Path Matrix Operations
 * @complexity
 *   - Time Complexity: O(r1 * c1 * c2)
 *   - Space Complexity: O(r1 * c1 + r2 * c2 + r1 * c2)
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1;
    
    // Read dimensions of matrix A
    if (scanf("%d %d", &r1, &c1) != 2) return 0;
    
    // Dynamically allocate memory / declare matrix A
    int A[r1][c1];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    int r2, c2;
    // Read dimensions of matrix B
    if (scanf("%d %d", &r2, &c2) != 2) return 0;
    
    // Check whether matrix multiplication is possible
    if (c1 != r2) {
        printf("Invalid input\n");
        return 0; // Terminate early, skipping reading matrix B elements
    }
    
    // Dynamically allocate memory for matrix B (only if valid)
    int B[r2][c2];
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    // Compute product matrix C with dimensions r1 x c2 and display results
    int C[r1][c2];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

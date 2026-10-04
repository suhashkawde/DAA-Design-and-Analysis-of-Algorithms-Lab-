/**
 * @file 1.1.5. Implement Sum of Subset Problem Using Backtracking.c
 * @brief Find all subsets of a given set whose sum equals the target sum using Backtracking.
 * @strategy Backtracking
 * @complexity
 *   - Time Complexity:
 *     - Best Case: O(2^n)
 *     - Average Case: O(2^n)
 *     - Worst Case: O(2^n) [State-space tree with 2^n nodes]
 *   - Space Complexity: O(n) (recursion stack depth & temporary subset buffer)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2000
#define MAX_RESULTS 2000

static int arr[MAX_N];
static int n, target;
static int current_subset[MAX_N];

static int results[MAX_RESULTS][MAX_N];
static int result_sizes[MAX_RESULTS];
static int result_count = 0;

/**
 * @brief Recursively explores subsets using inclusion-exclusion decision tree.
 * 
 * @param index Current index in the input array being considered
 * @param current_sum Sum of elements included so far
 * @param subset_size Number of elements included in current_subset
 */
void backtrack(int index, int current_sum, int subset_size) {
    // Base Case: All elements evaluated
    if (index == n) {
        if (current_sum == target) {
            result_sizes[result_count] = subset_size;
            for (int i = 0; i < subset_size; i++) {
                results[result_count][i] = current_subset[i];
            }
            result_count++;
        }
        return;
    }
    
    // Choice 1: Include current element arr[index]
    current_subset[subset_size] = arr[index];
    backtrack(index + 1, current_sum + arr[index], subset_size + 1);
    
    // Choice 2: Exclude current element arr[index]
    backtrack(index + 1, current_sum, subset_size);
}

int main() {
    // Read number of elements
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_N) {
        printf("-1\n");
        return 0;
    }
    
    // Read set elements
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 0;
    }
    
    // Read target sum
    if (scanf("%d", &target) != 1) return 0;
    
    // Run backtracking algorithm
    backtrack(0, 0, 0);
    
    // Print subsets in reverse order of discovery
    if (result_count == 0) {
        printf("-1\n");
    } else {
        for (int i = result_count - 1; i >= 0; i--) {
            for (int j = 0; j < result_sizes[i]; j++) {
                printf("%d ", results[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}

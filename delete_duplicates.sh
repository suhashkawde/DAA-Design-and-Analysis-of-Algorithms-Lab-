#!/bin/bash
# Script to delete duplicate files with leading zeros

git rm "1.1.01. Quick sort.txt"
git rm "1.1.02. Merge Sort - Divide and Conquer.c"
git rm "1.1.03. Minimum Spanning Tree using Prim's.c"
git rm "1.1.04. Minimum Spanning Tree using Kruskal's.c"
git rm "1.1.05. Implement Sum of Subset Problem Using Backtracking.c"
git rm "1.1.06. Dijkstra's Shortest Path Algorithm.c"
git rm "1.1.07. Bellman-Ford algorithm.c"
git rm "1.1.08. Matrix Multiplication.c"
git rm "1.1.09. Breadth First Search (BFS).c"
git rm "1.1.10. Depth-First Search (DFS).c"
git rm "1.1.11. Knapsack Problem.c"
git rm "1.1.12. Longest Common Sub Sequence.c"
git rm "1.1.13. Travelling Salesman Problem.c"

git commit -m "Remove duplicate files with leading zeros (1.1.01-1.1.13)"
git push origin main

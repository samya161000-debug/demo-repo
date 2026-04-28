# Data Structures & Algorithms Lab Repository

This repository contains implementations of fundamental algorithms from multiple lab sessions. Each lab focuses on a specific category of problems such as sorting, searching, graph algorithms, and optimization techniques.

# Basics & Recursion

* Bubble Sort
* Selection Sort
* Horner’s Rule
* Linear Search
* Missing Number
* Permutations
* Xⁿ (Power using recursion)
* Velocity (No tips problem)
* Tower of Hanoi
* Truth Table

## Searching & Simple Sorting

* Binary Search
* Insertion

### Efficient Sorting

* Merge Sort
* Quick Sort

## Divide & Conquer

* Kth Smallest Element
* Min-Max

## Advanced Algorithms

* Convex Hull
* Knapsack Problem
* Matrix Multiplication
* Strassen’s Matrix Multiplication

## Greedy & Graphs

* Activity Selection
* Dijkstra’s Algorithm

## Minimum Spanning Tree

* Kruskal’s Algorithm
* Prim’s Algorithm

## Advanced Graph Problems

* Dijkstra Path Printing
* Cycle Detection
* Multistage Graph
* Traveling Salesman Problem (TSP)

---

# How to Run Programs

1. Compile the code:

```bash
g++ filename.cpp -o output
```

2. Run:

```bash
./output
```

---

# Important Complexities

| Algorithm         | Time Complexity    |
| ----------------- | ------------------ |
| Bubble Sort       | O(n²)              |
| Selection Sort    | O(n²)              |
| Insertion Sort    | O(n²)              |
| Merge Sort        | O(n log n)         |
| Quick Sort        | O(n log n) avg     |
| Binary Search     | O(log n)           |
| Dijkstra          | O(V²) / O(E log V) |
| Kruskal           | O(E log E)         |
| Prim              | O(E log V)         |
| Knapsack (DP)     | O(nW)              |
| TSP (Brute Force) | O(n!)              |

---

# Concepts Covered

* Sorting Algorithms
* Searching Techniques
* Divide and Conquer
* Greedy Algorithms
* Dynamic Programming
* Graph Algorithms
* Recursion & Backtracking

---

# 🔍 Algorithm Explanations

## Bubble Sort

Compares adjacent elements and swaps them if needed. Largest elements move to the end after each pass.

## Selection Sort

Selects the smallest element and places it at the correct position.

## Horner’s Rule

Efficient polynomial evaluation by reducing repeated multiplications.

## Linear Search

Checks each element sequentially until the target is found.

## Missing Number

Finds missing value using sum formula or XOR technique.

## Permutations

Generates all possible arrangements using recursion and swapping.

## Xⁿ (Power)

Uses recursion or fast exponentiation (divide & conquer).

## Velocity (No Tips Problem)

Applies formula-based logic to compute motion-related values.

## Tower of Hanoi

Recursive solution:
move n-1 disks → move largest → move n-1 again.

## Truth Table

Shows all logical input-output combinations.

## Binary Search

Divides sorted array repeatedly to find target efficiently.

## Insertion Sort

Builds sorted list by inserting elements at correct position.

## Merge Sort

Divides array, sorts recursively, then merges.

## Quick Sort

Partitions around pivot and sorts recursively.

## Kth Smallest Element

Finds kth smallest using sorting or QuickSelect.

## Min-Max

Uses divide & conquer to reduce comparisons.

## Convex Hull

Finds smallest boundary enclosing all points.

## Knapsack Problem

Maximizes value under weight constraint (DP/greedy).

## Matrix Multiplication

Row × column multiplication of matrices.

## Strassen’s Algorithm

Optimized matrix multiplication using divide & conquer.

## Activity Selection

Greedy method selecting max non-overlapping activities.

## Dijkstra’s Algorithm

Finds shortest path from source to all nodes.

## Kruskal’s Algorithm

Builds MST using smallest edges without cycles.

## Prim’s Algorithm

Builds MST by expanding from a starting node.

## Dijkstra Path Printing

Stores parent array to reconstruct shortest path.

## Cycle Detection

Detects cycles using DFS or Union-Find.

## Multistage Graph

Solves shortest path stage-by-stage using DP.

## Traveling Salesman Problem (TSP)

Finds minimum cost path visiting all nodes once.

---

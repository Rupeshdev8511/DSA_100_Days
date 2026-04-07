#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int** graph, int* graphSize, bool* visited, bool* recStack) {
    
    // Mark current node as visited and part of recursion stack
    visited[node] = true;
    recStack[node] = true;

    // Visit all neighbors
    for (int i = 0; i < graphSize[node]; i++) {
        int neighbor = graph[node][i];

        // If not visited, recurse
        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, graphSize, visited, recStack))
                return true;
        }
        // If neighbor is in recursion stack → cycle found
        else if (recStack[neighbor]) {
            return true;
        }
    }

    // Remove node from recursion stack
    recStack[node] = false;
    return false;
}

// Function to check cycle in graph
bool hasCycle(int V, int** graph, int* graphSize) {
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, graphSize, visited, recStack))
                return true;
        }
    }
    return false;
}

// Example usage
int main() {
    int V = 2;

    // Allocate graph
    int** graph = (int**)malloc(V * sizeof(int*));
    int* graphSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }

    // Example: 0 -> 1, 1 -> 0 (cycle)
    graph[0][graphSize[0]++] = 1;
    graph[1][graphSize[1]++] = 0;

    if (hasCycle(V, graph, graphSize))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
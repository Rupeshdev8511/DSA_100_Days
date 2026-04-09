#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];     // adjacency matrix
int indegree[MAX];     // indegree array
int queue[MAX];        // queue
int n;                 // number of vertices

void topologicalSort() {
    int front = 0, rear = 0;
    int i, j;

    // Step 1: Calculate indegree
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Add nodes with indegree 0 to queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 3: Process queue
    printf("Topological Order: ");
    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        // Reduce indegree of adjacent nodes
        for (j = 0; j < n; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    queue[rear++] = j;
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != n) {
        printf("\nGraph has a cycle! Topological sort not possible.\n");
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}

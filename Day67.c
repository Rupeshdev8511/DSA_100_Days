#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int V;

void push(int v) {
    stack[++top] = v;
}

void DFS(int v) {
    visited[v] = 1;

    for(int i = 0; i < V; i++) {
        if(graph[v][i] && !visited[i]) {
            DFS(i);
        }
    }

    push(v);
}

void topologicalSort() {
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            DFS(i);
        }
    }

    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int E;
    
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for(int i = 0; i < E; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort();

    return 0;
}
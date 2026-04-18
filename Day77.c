#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int visited[MAX];
int *adj[MAX];
int adjSize[MAX];

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int u, v;

    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}
#include <stdio.h>
#include <limits.h>

#define MAX 1005

int minKey(int key[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for(int v = 1; v <= n; v++) {
        if(!visited[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[n+1];
    int visited[n+1];

    for(int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;

    int total_weight = 0;

    for(int count = 1; count <= n; count++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;
        total_weight += key[u];

        for(int v = 1; v <= n; v++) {
            if(graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total_weight);

    return 0;
}

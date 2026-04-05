#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// BFS function
void bfs(int n, int adj[MAX][MAX], int s) {
    int visited[MAX] = {0};
    
    enqueue(s);
    visited[s] = 1;
    
    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        
        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int adj[MAX][MAX];
    
    // Input adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    int s;
    scanf("%d", &s);
    
    bfs(n, adj, s);
    
    return 0;
}
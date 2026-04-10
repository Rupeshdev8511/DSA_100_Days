#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

// ----------- Graph (Adjacency List) -----------
struct Edge {
    int to, weight;
    struct Edge* next;
};

struct Edge* graph[MAX];

// Add edge u -> v
void addEdge(int u, int v, int w) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->to = v;
    newEdge->weight = w;
    newEdge->next = graph[u];
    graph[u] = newEdge;
}

// ----------- Min Heap -----------
struct Node {
    int vertex, dist;
};

struct MinHeap {
    int size;
    struct Node heap[MAX];
};

// Swap
void swap(struct Node* a, struct Node* b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(struct MinHeap* h, int i) {
    while (i > 0 && h->heap[(i - 1) / 2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;
    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

// Push into heap
void push(struct MinHeap* h, int v, int dist) {
    h->heap[h->size].vertex = v;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// Pop minimum
struct Node pop(struct MinHeap* h) {
    struct Node root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

// Check if empty
int isEmpty(struct MinHeap* h) {
    return h->size == 0;
}

// ----------- Dijkstra -----------
void dijkstra(int n, int src) {
    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    while (!isEmpty(&heap)) {
        struct Node curr = pop(&heap);
        int u = curr.vertex;

        // Traverse neighbors
        struct Edge* temp = graph[u];
        while (temp) {
            int v = temp->to;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("Node %d: INF\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
}
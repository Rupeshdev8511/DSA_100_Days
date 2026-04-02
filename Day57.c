#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for level order
struct Queue {
    struct TreeNode** arr;
    int front, rear;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    q->front = q->rear = 0;
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue* q = createQueue(n);
    struct TreeNode* root = newNode(arr[0]);
    enqueue(q, root);

    int i = 1;

    while (i < n) {
        struct TreeNode* curr = dequeue(q);

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Mirror tree
void mirror(struct TreeNode* root) {
    if (root == NULL) return;

    // swap left and right
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    mirror(root);

    inorder(root);

    return 0;
}
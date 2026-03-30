#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Height function
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    return nodes[0];
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("%d\n", height(root));

    return 0;
}
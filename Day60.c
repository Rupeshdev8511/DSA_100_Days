#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n, int i) {
    if (i >= n) return NULL;

    struct TreeNode* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Count nodes
int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
bool isCBT(struct TreeNode* root, int index, int totalNodes) {
    if (!root) return true;

    if (index >= totalNodes)
        return false;

    return isCBT(root->left, 2*index + 1, totalNodes) &&
           isCBT(root->right, 2*index + 2, totalNodes);
}

// Check Min Heap property
bool isMinHeap(struct TreeNode* root) {
    if (!root->left && !root->right)
        return true;

    if (!root->right) {
        return (root->val <= root->left->val);
    }

    if (root->val <= root->left->val &&
        root->val <= root->right->val)
        return isMinHeap(root->left) && isMinHeap(root->right);

    return false;
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n, 0);

    int totalNodes = countNodes(root);

    if (isCBT(root, 0, totalNodes) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
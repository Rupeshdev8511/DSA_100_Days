#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
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

// Insert into BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    int n, key;
    scanf("%d", &n);

    struct Node* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Insert new key
    scanf("%d", &key);
    root = insert(root, key);

    // Print inorder traversal
    inorder(root);

    return 0;
}
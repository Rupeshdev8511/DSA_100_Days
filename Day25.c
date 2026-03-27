#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Count occurrences of key
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;

    while(temp != NULL) {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, key;

    // Input
    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &key);

    // Count occurrences
    int result = countOccurrences(head, key);

    // Output
    printf("%d", result);

    return 0;
} 
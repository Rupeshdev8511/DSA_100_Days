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

// Get length of list
int getLength(struct Node* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection (by value as per problem)
void findIntersection(struct Node* l1, struct Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    // Move pointer of longer list
    int diff = abs(len1 - len2);

    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            l1 = l1->next;
    } else {
        for(int i = 0; i < diff; i++)
            l2 = l2->next;
    }

    // Traverse both lists
    while(l1 != NULL && l2 != NULL) {
        if(l1->data == l2->data) {
            printf("%d", l1->data);
            return;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;

    // Input lists
    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    // Find intersection
    findIntersection(list1, list2);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create polynomial linked list
struct Node* createPoly(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
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

// Print polynomial
void printPoly(struct Node* head) {
    struct Node* temp = head;

    while(temp != NULL) {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    struct Node* poly = createPoly(n);

    printPoly(poly);

    return 0;
}
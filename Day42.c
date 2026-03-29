#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int queue[n];
    int stack[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    int top = -1;

    // Push queue elements into stack
    for (int i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }

    // Pop from stack (reversed order)
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
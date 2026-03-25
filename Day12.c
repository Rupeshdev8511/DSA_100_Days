#include <stdio.h>

int main() {
    int m, n, i, j;
    int A[100][100];
    int symmetric = 1;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    // Input matrix elements
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Check if square matrix
    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Check symmetry
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(A[i][j] != A[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }

    if(symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
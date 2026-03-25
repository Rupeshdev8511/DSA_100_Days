#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int start = 0, end, temp;

    // Input string
    scanf("%s", str);

    end = strlen(str) - 1;

    // Reverse using two-pointer approach
    while(start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    // Output reversed string
    printf("%s", str);

    return 0;
}
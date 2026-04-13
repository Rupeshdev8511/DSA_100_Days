#include <stdio.h>

int main() {
    char s[100005];
    scanf("%s", s);

    int visited[26] = {0}; // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (visited[index] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        visited[index] = 1;
    }

    // No repeated character
    printf("-1\n");

    return 0;
}
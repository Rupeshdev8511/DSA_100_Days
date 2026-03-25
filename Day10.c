#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int start = 0, end, palindrome = 1;

    // Input string
    scanf("%s", s);

    end = strlen(s) - 1;

    while(start < end) {
        if(s[start] != s[end]) {
            palindrome = 0;
            break;
        }
        start++;
        end--;
    }

    if(palindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
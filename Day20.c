#include <stdio.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    int count = 0;

    // Simple hashmap using array (for small constraints)
    // Range assumed: adjust if needed
    int freq[20001] = {0};  // supports sums from -10000 to +10000
    int offset = 10000;

    // Initialize
    freq[offset] = 1; // prefix sum = 0 initially

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // If this prefix sum seen before, add its frequency
        count += freq[prefix_sum + offset];

        // Increase frequency
        freq[prefix_sum + offset]++;
    }

    // Output result
    printf("%d", count);

    return 0;
}
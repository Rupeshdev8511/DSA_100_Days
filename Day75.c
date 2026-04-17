#include <stdio.h>

int maxLen(int arr[], int n) {
    int prefixSum = 0;
    int maxLength = 0;

    // hash table (prefix sum range handled with offset)
    int hash[20001];
    
    for(int i = 0; i < 20001; i++)
        hash[i] = -2;

    int offset = 10000;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(prefixSum == 0)
            maxLength = i + 1;

        if(hash[prefixSum + offset] == -2)
            hash[prefixSum + offset] = i;
        else {
            int length = i - hash[prefixSum + offset];
            if(length > maxLength)
                maxLength = length;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}
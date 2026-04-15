#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];

    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char winner[50];
    int maxVotes = 0;

    for(int i = 0; i < n; i++) {
        int count = 1;

        for(int j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }

        if(count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        }
        else if(count == maxVotes && strcmp(names[i], winner) < 0) {
            strcpy(winner, names[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
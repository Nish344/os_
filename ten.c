#include<stdio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of head: ");
    scanf("%d", &h);

    t[0] = 0;
    t[1] = h;

    printf("Enter the tracks: \n");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }

    // Sort the tracks using bubble sort
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find the position of the head in the sorted array
    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
            p = 0;
        }
    }

    // Arrange tracks in the seek sequence
    while (t[j] != 0) {
        atr[p] = t[j];
        j--;
        p++;
    }

    atr[p] = t[j]; // Include the track with position 0

    for (p = k + 1; p < n + 2; p++, k++) {
        atr[p] = t[k + 1];
    }

    printf("Seek sequence is:");

    // Calculate the seek distances and total head movements
    for (j = 0; j < n + 1; j++) {
        if (atr[j] > atr[j + 1]) {
            d[j] = atr[j] - atr[j + 1];
        } else {
            d[j] = atr[j + 1] - atr[j];
        }
        sum += d[j];
        printf("\n%d", atr[j]);
    }

    printf("\nTotal head movements: %d", sum);

    return 0;
}

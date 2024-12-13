#include <stdio.h>

void main() {
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;

    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);

    printf("\nEnter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("\nEnter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        m[i] = -1; // Initialize frames to -1 (empty)

    printf("\nThe Page Replacement Process is:\n");
    for (i = 0; i < n; i++) {
        // Check if page is already in frame
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i])
                break;
        }

        // If not found, replace using FIFO logic
        if (k == f) {
            m[count++] = rs[i];
            pf++;
        }

        // Print the current state of frames
        for (j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("\t%d", m[j]);
            else
                printf("\t-");
        }

        if (k == f)
            printf("\tPF No. %d", pf);

        printf("\n");

        // Reset count if it reaches the number of frames
        if (count == f)
            count = 0;
    }

    printf("\nThe number of Page Faults using FIFO are: %d\n", pf);
}

#include <stdio.h>

int main() {
    int i, j, k, min, rs[25], m[10], count[10], flag[25], n, f, pf = 0, next = 1;

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0; // Initialize the flag array to 0
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        count[i] = 0; // Initialize the count array to 0
        m[i] = -1;    // Initialize the frame array to -1 (empty)
    }

    printf("\nThe Page Replacement process is:\n");
    for (i = 0; i < n; i++) {
        // Check if the page is already in the frame
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;      // Page is found in frame
                count[j] = next;  // Update the last used time
                next++;
                break;
            }
        }

        // If page is not in frame, replace using LRU logic
        if (flag[i] == 0) {
            if (i < f) {
                // Directly place in the empty frame for initial iterations
                m[i] = rs[i];
                count[i] = next;
                next++;
            } else {
                // Find the least recently used page
                min = 0;
                for (j = 1; j < f; j++) {
                    if (count[min] > count[j]) {
                        min = j;
                    }
                }
                m[min] = rs[i];   // Replace the LRU page
                count[min] = next;
                next++;
            }
            pf++; // Increment the page fault count
        }

        // Print the current frame status
        for (j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("%d\t", m[j]);
            else
                printf("-\t");  // Empty frame
        }

        if (flag[i] == 0)
            printf("PF No. -- %d", pf);

        printf("\n");
    }

    printf("\nThe number of page faults using LRU are: %d\n", pf);
    return 0;
}

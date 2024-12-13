#include<stdio.h>
#define max 25 // Maximum number of blocks/files

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest;
    static int bf[max], ff[max]; // bf: Block flags, ff: File-to-block mapping

    // Input the number of blocks
    printf("\n\tMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);

    // Input the number of files
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input the sizes of blocks
    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    // Input the sizes of files
    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // Best Fit Allocation Logic
    for (i = 1; i <= nf; i++) { // Iterate over files
        lowest = 10000;        // Reset lowest for each file
        ff[i] = -1;            // Default to no block assigned

        for (j = 1; j <= nb; j++) { // Iterate over blocks
            if (bf[j] != 1) {  // Check if block is free
                temp = b[j] - f[i]; // Calculate remaining space
                if (temp >= 0 && temp < lowest) { // Find the best fit
                    ff[i] = j;    // Assign block `j` to file `i`
                    lowest = temp;
                }
            }
        }

        if (ff[i] != -1) { // If a block is assigned
            frag[i] = lowest;    // Record fragmentation
            bf[ff[i]] = 1;       // Mark block as allocated
        } else {
            frag[i] = -1;        // No block could be assigned
        }
    }

    // Output the Allocation Table
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 1; i <= nf; i++) {
        if (ff[i] != -1) { // Block is assigned
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", 
                i, f[i], ff[i], b[ff[i]], frag[i]);
        } else { // Block not assigned
            printf("\n%d\t\t%d\t\tNot Allocated\t-\t\t-", 
                i, f[i]);
        }
    }
}

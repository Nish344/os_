#include <stdio.h>
#define max 25 // Maximum number of blocks/files

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest;
    static int bf[max], ff[max]; // bf: Block flags, ff: File-to-block mapping

    // Input the number of memory blocks
    printf("Enter the Number of blocks\n");
    scanf("%d", &nb);

    // Input the number of files
    printf("Enter the Number of files\n");
    scanf("%d", &nf);

    // Input the sizes of memory blocks
    printf("Enter the size of each block\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    // Input the sizes of files
    printf("Enter the size of each file\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // Worst Fit Allocation Logic
    for (i = 1; i <= nf; i++) { // Iterate over files
        highest = -1;          // Reset highest for each file
        for (j = 1; j <= nb; j++) { // Iterate over blocks
            if (bf[j] != 1) {  // Check if block is not allocated
                temp = b[j] - f[i]; // Calculate remaining space
                if (temp >= 0 && temp > highest) { // Find the worst fit
                    ff[i] = j;   // Assign block `j` to file `i`
                    highest = temp;
                }
            }
        }
        frag[i] = highest; // Record fragmentation for file `i`
        bf[ff[i]] = 1;     // Mark block as allocated
    }

    // Output the Allocation Table
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
    for (i = 1; i <= nf; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", 
            i, f[i], ff[i], b[ff[i]], frag[i]);
    }
}

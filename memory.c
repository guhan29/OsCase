#include <stdio.h>

// Initialize the process alloction to -1
void initialize(int processAllocation[], int n) {
    for(int i=0; i<n; i++)
        processAllocation[i] = -1;
}

// Print the allocated processes
void printAllocated(int processSize[], int processAllocation[], int n) {
    printf("Process No.\tProcess Size\tBlock no.\n");

    for(int i=0; i<n; i++) {
        printf(" %d \t\t   %d \t\t", i+1, processSize[i]);
        if(processAllocation[i] != -1) {
            printf("%d\n", processAllocation[i]+1);
        } else {
            printf("Un-allocated\n");
        }
    }
}

// Firt Fit algorithm
void firstFit(int blockSize[], int processSize[], int blockLen, int processLen) {
    printf("\n---First Fit algorithm---\n");
    int processAllocation[processLen];
    initialize(processAllocation, processLen);

    for(int i=0; i<processLen; i++) {
        for(int j=0; j<blockLen; j++) {
            // Getting the first required size block
            if(processSize[i] <= blockSize[j]) {
                processAllocation[i] = j;
                blockSize[j] = 0;
                break; // Break and go to next process
            }
        }
    }

    printAllocated(processSize, processAllocation, processLen);
}

// Best Fit algorithm
void bestFit(int blockSize[], int processSize[], int blockLen, int processLen) {
    printf("\n---Best Fit algorithm---\n");
    int processAllocation[processLen];
    initialize(processAllocation, processLen);

    for(int i=0; i<processLen; i++) {
        int best = -1;
        for(int j=0; j<blockLen; j++) {
            // Getting the minimum of the required size
            if(processSize[i] <= blockSize[j]) {
                if(best == -1 || blockSize[best] > blockSize[j]) {
                    best = j;
                }
            }
        }
        if(best != -1) {
            processAllocation[i] = best;
            blockSize[best] = 0;
        }
    }

    printAllocated(processSize, processAllocation, processLen);
}

// Worst Fit algorithm
void worstFit(int blockSize[], int processSize[], int blockLen, int processLen) {
    printf("\n---Worst Fit algorithm---\n");
    int processAllocation[processLen];
    initialize(processAllocation, processLen);

    for(int i=0; i<processLen; i++) {
        int worst = -1;
        for(int j=0; j<blockLen; j++) {
            // Getting the maximum of the required size
            if(processSize[i] <= blockSize[j]) {
                if(worst == -1 || blockSize[worst] < blockSize[j]) {
                    worst = j;
                }
            }
        }
        if(worst != -1) {
            processAllocation[i] = worst;
            blockSize[worst] = 0;
        }
    }

    printAllocated(processSize, processAllocation, processLen);
}

int main() {
    int blockSize[] = {50, 100, 90, 200, 50};
    int processSize[] = {90, 20, 50, 10, 100};

    // Get the length of the blocks and processes
    int blockLen = sizeof(blockSize) / sizeof(int);
    int processLen = sizeof(processSize) / sizeof(int);

    puts("Select the algorithm");
    // Get the option
    int option;
    printf("1 - First Fit \n2 - Best Fit \n3 - Worst Fit \nEnter your option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            firstFit(blockSize, processSize, blockLen, processLen);
            break;
        case 2:
            bestFit(blockSize, processSize, blockLen, processLen);
            break;
        case 3:
            worstFit(blockSize, processSize, blockLen, processLen);
            break;
        default:
            printf("\nInvalid Entry");
    }

    return 0;
}

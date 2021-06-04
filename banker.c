#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k, noOfProcess = 0, noOfResources=0;
    scanf("%d", &noOfProcess);
    scanf("%d", &noOfResources);
    
    int instances[noOfResources];
    
    for(i=0; i<noOfResources; i++) {
        scanf("%d", &instances[i]);
    }
    
    int maximumClaim[noOfProcess][noOfResources], currrentAllocation[noOfProcess][noOfResources];
    
    for(i=0; i<noOfProcess; i++) {
        for(j=0; j<noOfResources; j++) {
            scanf("%d", &maximumClaim[i][j]);
        }
    }
    
    for(i=0; i<noOfProcess; i++) {
        for(j=0; j<noOfResources; j++) {
            scanf("%d", &currrentAllocation[i][j]);
        }
    }
    
    int need[noOfProcess][noOfResources];
    for(i=0; i<noOfProcess; i++) {
        for(j=0; j<noOfResources; j++) {
            need[i][j] = (int) abs(maximumClaim[i][j] - currrentAllocation[i][j]);
        }
    }
    
    printf("Need Matrix:\n");
    for(i=0; i<noOfProcess; i++) {
        for(j=0; j<noOfResources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    
    int finished[noOfProcess], sequence[noOfProcess], index=0;
    for(i=0; i<noOfProcess; i++) {
        finished[i] = 0;
        sequence[i] = 0;
    }
    
    
    for(i=0; i<noOfProcess; i++) {
        for(j=0; j<noOfProcess; j++) {
            if(finished[j] == 0) {
                int flag = 1;
                for(k=0; k<noOfResources; k++) {
                    if(instances[k] < need[j][k]) {
                        flag = 0;
                        break;
                    }
                }
                
                if(flag == 1) {
                    finished[j] = 1;
                    
                    sequence[index] = j;
                    index++;
                    
                    for(k=0; k<noOfResources; k++) {
                        instances[k] += currrentAllocation[j][k];
                    }
                }
            }
        }
    }
    
    int flag = 1;
    for(i=0; i<noOfProcess; i++) {
        if(finished[i] != 1) {
            flag = 0;
        }
    }
    
    printf("\n");
    if(flag) {
        printf("Safe sequence is: ");
        for(i=0; i<noOfProcess-1; i++) {
            printf("%d->", sequence[i]);
        }
        printf("%d", sequence[noOfProcess-1]);
    } else {
        printf("Deadlock");
    }
    
    
    return 0;
}

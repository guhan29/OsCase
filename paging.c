#include <stdio.h>

#define PAGE_SIZE 100
#define PAGE_TABLE_SIZE 128

struct pageTable {
    int no;
    int startAddr;
} ptable[PAGE_TABLE_SIZE];

char memory[PAGE_SIZE * PAGE_TABLE_SIZE];

int getPhysicalAddress(int logicalAddress) {
    int pageNo = logicalAddress / PAGE_SIZE;
    int offset  = logicalAddress % PAGE_SIZE;
    return ptable[pageNo].startAddr + offset;
}

int main() {
    int entryFlag=0, translateFlag=0, phyAddr, logicalAddr;
    char data, choice;
    int n, i;
    printf("Enter the number of pages to allocate: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("Enter Starting Address for Page %d: ", i);
        scanf("%d", &ptable[i].startAddr);
        ptable[i].no = i;
    }

    printf("\nEnter the logical address of data to be modified: ");
    scanf("%d", &logicalAddr);

    printf("\nEnter the data to be set at the given location: ");
    scanf("%s", &data);

    phyAddr = getPhysicalAddress(logicalAddr);
    memory[phyAddr] = data;

    printf("\nData successfully stored at physical address %d \n", phyAddr);

    printf("\nEnter the logical address to be translated: ");
    scanf("%d", &logicalAddr);

    phyAddr = getPhysicalAddress(logicalAddr);
    data = memory[phyAddr];
    printf("\nLogical Address %d = Physical Address %d. Data is %d\n", logicalAddr, phyAddr, data);

    return 0;
}
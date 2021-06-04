#include <stdio.h>
#include <stdlib.h>

void fcfs(int arr[], int size, int head) {
    int distance, currTrack, seekCount = 0;

    for (int i=0; i<size; i++) {
        currTrack = arr[i];
        distance = abs(currTrack - head);
        seekCount += distance;
        head = currTrack;
    }

    printf("Seek time is: %d\n", seekCount);

    printf("Access time = Seek time + Rotational latency + Transfer time and it depends on system\n");
    printf("Access time = %d\n", seekCount+size);
    printf("The order of seek sequence is: \n");

    for (int i=0; i<size; i++) {
        printf("%d\n", arr[i]);
    }

}

int main() {
    int seekRequest[] = {98,37,14,121,65,67};
    int head = 32; // Initial head position
    fcfs (seekRequest, sizeof(seekRequest)/sizeof(int), head);
    return 0;
}

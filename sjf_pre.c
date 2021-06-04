#include <stdio.h>

typedef struct Process {
    int pid;
    int arrival;
    int burst;
    int rt;
    int turnaround;
    int wait;
} Process;

int main() {
    int size, i;
    printf("Enter the no of processes: ");
    scanf("%d", &size);
    Process p[size+1];
    double avgwt=0, avgtr=0;

    // Get the inputs
    for(i=0; i<size; i++) {
        p[i].pid = i+1;
        printf("\nArrival time of P%d: ", i+1);
        scanf("%d", &p[i].arrival);
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &p[i].burst);
        p[i].rt = p[i].burst;
    }
    printf("\n\nGantt Chart:\n");

    p[size].burst = 9999999;
    p[size].rt = p[size].burst;
    int flag=0, count=0, time=0, minFlag=-1;
    while(count < size) {
        int min = size;

        // Get Process with minimum arrival time and minimum remaining time
        for(i=0; i<size; i++) {
            if(p[i].arrival <= time && p[i].rt < p[min].rt && p[i].rt > 0) {
                min = i;
                flag = 1;
            }
        }

        if(flag != 1) {
            time++;
            continue;
        }

        p[min].rt--;

        // Gantt Chart
        if(minFlag == -1) {
            printf("P%d->%d-", min+1, time);
            minFlag = min;
        } else if(minFlag == min) {
            printf("--");
        } else {
            minFlag = min;
            printf("P%d->%d-", min+1, time);
        }

        /* After completion of process increment the count calculate waiting time and turn around time
         * waitTime = completionTime - arrivalTime - burstTime
         * turnAround time = waitTime + burstTime
        */
        if(p[min].rt <= 0) {
            count++;
            p[min].wait = time + 1 - p[min].arrival - p[min].burst;
            p[min].turnaround = p[min].wait + p[min].burst;
        }

        // Increment the time
        time++;
    }
    printf("%d", time);
    printf("\n\nProcess\t Arrival Time\t Burst Time\t Wait Time\t Turnaround Time\n");
    for(i=0; i<size; i++) {
        printf("   P%d\t\t %d\t\t %d\t   %d\t\t   %d\n", i+1, p[i].arrival, p[i].burst, p[i].wait, p[i].turnaround);
        avgwt += p[i].wait;
        avgtr += p[i].turnaround;
    }
    avgwt /= size;
    avgtr /= size;
    printf("\n\nAverage Waiting Time: %.2lf\n", avgwt);
    printf("Average Turnaround Time: %.2lf\n", avgtr);
    return 0;
}

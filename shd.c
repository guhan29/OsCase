#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int policy;

    if (argc < 2)
        pid = 0;
    else
        pid = atoi(argv[1]);

    printf("Scheduler Policy for PID: %d  -> ", pid);

    policy = sched_getscheduler(pid);

    switch(policy) {
        case SCHED_OTHER: printf("SCHED_OTHER\n"); break;
        case SCHED_RR:   printf("SCHED_RR\n"); break;
        case SCHED_FIFO:  printf("SCHED_FIFO\n"); break;
        default:   printf("Unknown...\n");
    }

    return 0;
}

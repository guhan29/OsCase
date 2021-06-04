#include<stdio.h>

int main(){
    int i, n, sum=0,count=0, y, qt, wt=0, tat=0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf("Enter the No.of Process : ");
    scanf("%d", &n);
    y=n;
    for(i=0;i<n;i++) {
        printf("\nEnter the Arrival and Burst time of the Process[%d]\n", i+1);
        printf("Arrival time is: ");
        scanf("%d", &at[i]);
        printf("Burst time is: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    printf("\nEnter the Time Quantum for the process: ");
    scanf("%d", &qt);
    printf("\nProcess No. \t BT\t CT\t TAT\t WT");
    for(i= 0;y!=0;) {
        if(temp[i]<=qt && temp[i]>0) {
            sum = sum+temp[i];
            temp[i]=0;
            count=1;
        }
        else if(temp[i]>0) {
            temp[i]=temp[i]-qt;
            sum=sum+qt;
        }
        if(temp[i]==0&&count==1) {
            y--;
            printf("\nProcess No[%d] \t %d\t %d\t %d\t %d", i+1, bt[i],sum, sum-at[i], sum-at[i]-bt[i]);
            wt=wt+sum-at[i]-bt[i];
            tat=tat+sum-at[i];
            count=0;
        }
        if(i==n-1) {
            i=0;
        }
        else if(at[i+1]<=sum) {
            i++;
        }
        else {
            i=0;
        }
    }
    avg_wt=wt*1.0/n;
    avg_tat=tat*1.0/n;
    printf("\nAverage Turn Around Time: %f",avg_tat);
    printf("\nAverage Waiting Time: %f\n",avg_wt);

    return 0;
}

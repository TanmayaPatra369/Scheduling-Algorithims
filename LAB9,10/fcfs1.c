#include <stdio.h>

int main() {
    int pid;
    int bt;
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter process id of all the processes: ");
    int pid_arr[n]; // Changed pid to pid_arr to avoid redeclaration of pid
    for(int i=0;i<n;i++) {
        scanf("%d",&pid_arr[i]);
    }
    printf("Enter burst time of all the processes: ");
    int burst_time[n]; // Changed bt to burst_time to avoid redeclaration of bt
    for(int i=0;i<n;i++) {
        scanf("%d",&burst_time[i]);
    }
    int i, wt[n];
    wt[0] = 0; //for calculating waiting time of each process
    for(i=1; i<n; i++) {
        wt[i]= burst_time[i-1]+ wt[i-1];
    }
    printf("Process ID Burst Time Waiting Time TurnAround Time\n");
    float twt=0.0;
    float tat= 0.0;
    for(i=0; i<n; i++) {
        printf("%d\t\t", pid_arr[i]);
        printf("%d\t\t", burst_time[i]);
        printf("%d\t\t", wt[i]); //calculating and printing turnaround time of each process
        printf("%d\t\t", burst_time[i]+wt[i]);
        printf("\n");
        //for calculating total waiting time
        twt += wt[i];
        //for calculating total turnaround time
        tat += (wt[i]+burst_time[i]);
    }
    float awt, att; //for calculating average waiting time
    awt = twt/n;
    att = tat/n;
    printf("Average waiting time = %f\n",awt);
    printf("Average turnaround time = %f\n",att);
    return 0;
}
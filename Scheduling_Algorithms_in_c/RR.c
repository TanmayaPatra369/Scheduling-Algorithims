#ROUND ROBBIN SCHEDULING


#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, quantum, total_waiting_time = 0, total_turnaround_time = 0;
    float avg_waiting_time, avg_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
        proc[i].pid = i + 1;
        proc[i].remaining_time = proc[i].burst_time;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    int current_time = 0, completed = 0;

    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                if (proc[i].remaining_time > quantum) {
                    current_time += quantum;
                    proc[i].remaining_time -= quantum;
                } else {
                    current_time += proc[i].remaining_time;
                    proc[i].waiting_time = current_time - proc[i].burst_time - proc[i].arrival_time;
                    if (proc[i].waiting_time < 0) {
                        proc[i].waiting_time = 0;
                    }
                    proc[i].turnaround_time = current_time - proc[i].arrival_time;
                    proc[i].remaining_time = 0;
                    completed++;
                    total_waiting_time += proc[i].waiting_time;
                    total_turnaround_time += proc[i].turnaround_time;
                }
            }
        }
    }

    avg_waiting_time = (float)total_waiting_time / n;
    avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

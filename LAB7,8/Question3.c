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
    int n, total_waiting_time = 0, total_turnaround_time = 0;
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

    int current_time = 0, completed = 0, shortest = 0, min_burst = 9999;

    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= current_time && proc[i].remaining_time < min_burst && proc[i].remaining_time > 0) {
                min_burst = proc[i].remaining_time;
                shortest = i;
            }
        }

        proc[shortest].remaining_time--;

        if (proc[shortest].remaining_time == 0) {
            completed++;
            min_burst = 9999;
            int finish_time = current_time + 1;
            proc[shortest].waiting_time = finish_time - proc[shortest].burst_time - proc[shortest].arrival_time;
            if (proc[shortest].waiting_time < 0) {
                proc[shortest].waiting_time = 0;
            }
            proc[shortest].turnaround_time = finish_time - proc[shortest].arrival_time;

            total_waiting_time += proc[shortest].waiting_time;
            total_turnaround_time += proc[shortest].turnaround_time;
        }

        current_time++;
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
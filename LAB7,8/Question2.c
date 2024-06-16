#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void findWaitingTime(struct Process proc[], int n) {
    proc[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].burst_time + proc[i - 1].waiting_time;
    }
}

void findTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

int main() {
    struct Process proc[10]; // Assuming a maximum of 10 processes
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst_time);
        proc[i].pid = i + 1;
    }

    float total_waiting_time = 0, total_turnaround_time = 0;

    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }

    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;

    // Display results including averages
    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
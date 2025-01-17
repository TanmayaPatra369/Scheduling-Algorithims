#include <stdio.h>

int main()
{
    int n, bt[10], tat[10], wt[10];
    float avgtat = 0, avgwt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 10)
    {
        printf("Invalid number of processes. Please enter a value between 1 and 10.\n");
        return 1;
    }

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);

        if (bt[i] < 0)
        {
            printf("Burst time cannot be negative. Please restart the program.\n");
            return 1;
        }
    }

    // Calculating Turnaround Time and Waiting Time
    tat[0] = bt[0]; // First process TAT is equal to its BT
    wt[0] = 0;      // First process has no waiting time

    avgtat = tat[0];
    avgwt = wt[0];

    for (int i = 1; i < n; i++)
    {
        tat[i] = tat[i - 1] + bt[i]; // TAT = cumulative BT
        wt[i] = tat[i] - bt[i];      // WT = TAT - BT

        avgtat += tat[i];
        avgwt += wt[i];
    }

    avgtat = avgtat / n;
    avgwt = avgwt / n;

    // Displaying Results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n", avgtat);

    return 0;
}

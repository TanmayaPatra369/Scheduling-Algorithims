#include <stdio.h>

int main()
{
    int n, bt[10], tat[10], wt[10];
    float avgtat = 0, avgwt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    tat[0] = bt[0];
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        tat[i] = tat[i - 1] + bt[i];
        wt[i] = tat[i] - bt[i];
        avgtat += tat[i];
        avgwt += wt[i];
    }

    avgtat = avgtat / n;
    avgwt = avgwt / n;

    printf("\n");
    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    
    for (int j = 0; j < n; j++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", j+1, bt[j], wt[j], tat[j]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n", avgtat);

    return 0;
}

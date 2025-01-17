#SHORTEST TIME REMAINING FIRST

#include<stdio.h>
#define max 30

void main()
{
    int i,j,n,bt[max],at[max],wt[max],tat[max],temp[max];
    float awt, atat;

    printf("Enter the number of processes:");
    scanf("%d",&n);

    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++) // Changed the loop condition from i<=n to i<n
    {
        scanf("%d",&bt[i]);
    }

    printf("\nEnter Arrival Time:\n");
    for(i=0;i<n;i++) // Changed the loop condition from i<=n to i<n
    {
        scanf( "%d", &at[i] );
    }

    temp[0]=0;
    printf("process \t bt\t at\t wt\t tat\t \n");
    for(i=0;i<n;i++) // Changed the loop condition from i<=n to i<n
    {
        wt[i]=0;
        tat[i]=0;
        temp[i+1] = temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
            
        tat[i]=wt[i]+bt[i];
        awt+=wt[i];
        atat+=tat[i];
        printf("%d\t %d\t %d\t %d\t %d\t \n",i+1,bt[i],at[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time=%f",awt/n);
    printf("\nAverage turn around time=%f",atat/n);
}

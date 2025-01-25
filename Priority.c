#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int n, i, j, pos, temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int p[n], bt[n], pr[n], wt[n], tat[n];
    float avg_wt, avg_tat, total = 0;

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter Priority for process %d: ", i + 1);
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
            {
                pos = j;
            }
        }

        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    total = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        total += wt[i];
    }
    avg_wt = total / n;

    total = 0;
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
    }
    avg_tat = total / n;

    printf("Process \tBurst Time \tPriority \tW.T \t\tT.A.T \t\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);
    return 0;
}
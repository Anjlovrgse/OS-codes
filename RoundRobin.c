#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int n, i, qt, temp, sq = 0, count = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int p[n], bt[n], rem_bt[n], tat[n], wt[n];

    printf("Enter the Process IDs: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst time of process P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d", &qt);
    while (1)
    {
        count = 0;
        for (i = 0; i < n; i++)
        {
            temp = qt;
            if (rem_bt[i] == 0)
            {
                count++;
                continue;
            }

            if (rem_bt[i] > qt)
            {
                rem_bt[i] -= qt;
            }
            else
            {
                temp = rem_bt[i];
                rem_bt[i] = 0;
            }

            sq += temp;
            tat[i] = sq;
        }

        if (count == n)
        {
            break;
        }
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);
    return 0;
}
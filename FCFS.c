#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int at[10], bt[10], ct[10], tat[10], wt[10], p[10];
    int temp, n, i, j;
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter %d process IDs: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter %d arrival times: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter %d burst times: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Sort based on arrival time (using Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap process IDs
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                // Swap arrival times
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    // Compute Completion Time
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        if (ct[i - 1] < at[i]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    // Calculate Turnaround Time and Waiting Time
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i]; // Turnaround Time
        wt[i] = tat[i] - bt[i]; // Waiting Time
        atat += tat[i];         // Accumulate total TAT
        awt += wt[i];           // Accumulate total WT
    }

    atat /= n; // Average Turnaround Time
    awt /= n;  // Average Waiting Time

    // Display results
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Average Turnaround Time: %.2f\n", atat);
    printf("Average Waiting Time: %.2f\n", awt);

    return 0;
}

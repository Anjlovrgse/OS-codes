#include <stdio.h>
int main()
{
    int blk, p, i, j;
    int blk_size[10], process_size[10], allocation[10];
    printf("Enter Number of Blocks: ");
    scanf("%d", &blk);
    for (i = 0; i < blk; i++)
    {
        printf("Enter Size of Block %d: ", i + 1);
        scanf("%d", &blk_size[i]);
    }
    printf("Enter Number of Processes: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++)
    {
        printf("Enter Size of Process %d: ", i + 1);
        scanf("%d", &process_size[i]);
        allocation[i] = -1;
    }
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < blk; j++)
        {
            if (process_size[i] <= blk_size[j])
            {
                allocation[i] = j;
                blk_size[j] -= process_size[i];
                break;
            }
        }
    }
    printf("\nAllocation Results:\n");
    printf("Process No\tProcess Size\tBlock No\n");
    for (i = 0; i < p; i++)
    {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, process_size[i], allocation[i] + 1);
        else
            printf("%d\t\t%d\t\tnot allocated\n", i + 1, process_size[i]);
    }

    return 0;
}
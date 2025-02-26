#include <stdio.h>
#define MAX 10
int main()
{
    int blk, p;
    int blk_size[MAX], process_size[MAX], frag[MAX];
    int bf[MAX] = {0}, ff[MAX] = {-1};

    printf("Enter Number of Blocks: ");
    scanf("%d", &blk);

    for (int i = 0; i < blk; i++)
    {
        printf("Enter Size of Block %d: ", i + 1);
        scanf("%d", &blk_size[i]);
        bf[i] = 0;
    }

    printf("Enter Number of Processes: ");
    scanf("%d", &p);

    for (int i = 0; i < p; i++)
    {
        printf("Enter Size of Process %d: ", i + 1);
        scanf("%d", &process_size[i]);
        ff[i] = -1;
    }

    for (int i = 0; i < p; i++)
    {
        int largest = -1;
        int worst_idx = -1;
        for (int j = 0; j < blk; j++)
        {
            if (bf[j] != 1)
            {
                int temp = blk_size[j] - process_size[i];
                if (temp >= 0 && temp > largest)
                {
                    worst_idx = j;
                    largest = temp;
                }
            }
        }
        if (worst_idx != -1)
        {
            ff[i] = worst_idx;
            bf[worst_idx] = 1;
            frag[i] = largest;
        }
        else
        {
            frag[i] = -1;
        }
    }

    printf("Process No Process Size Block No Block Size Fragment\n");
    for (int i = 0; i < p; i++)
    {
        printf("%d %d", i + 1, process_size[i]);
        if (ff[i] != -1)
        {
            printf(" %d %d %d\n", ff[i] + 1, blk_size[ff[i]], frag[i]);
        }
        else
        {
            printf(" Not Allocated - -\n");
        }
    }
    return 0;
}

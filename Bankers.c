#include <stdio.h>
int main()
{
    int k = 0, d = 0, t = 0, count = 0, rz, pno;
    int output[10], ins[5], avail[5], allocated[10][5], need[10][5], maxi[10][5];
    int p[10];
    printf("Enter the number of resources: ");
    scanf("%d", &rz);

    printf("Enter the maximum instances of each resource\n");
    for (int i = 0; i < rz; i++)
    {
        avail[i] = 0;
        printf("Resource (%c): ", 'a' + i);
        scanf("%d", &ins[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    printf("Enter the allocation matrix:\n");
    printf("a b c\n");
    for (int i = 0; i < pno; i++)
    {
        p[i] = i;
        printf("p[%d]:", i);
        for (int j = 0; j < rz; j++)
        {
            scanf("%d", &allocated[i][j]);
            avail[j] += allocated[i][j];
        }
    }

    printf("Enter the MAX matrix:\n");
    printf("a b c\n");
    for (int i = 0; i < pno; i++)
    {
        printf("p[%d]:", i);
        for (int j = 0; j < rz; j++)
        {
            scanf("%d", &maxi[i][j]);
        }
    }
A:
    d = -1;
    for (int i = 0; i < pno; i++)
    {
        count = 0;
        t = p[i];
        for (int j = 0; j < rz; j++)
        {
            need[t][j] = maxi[t][j] - allocated[t][j];
            if (need[t][j] <= avail[j])
            {
                count++;
            }
        }
        if (count == rz)
        {
            output[k++] = p[i];
            for (int j = 0; j < rz; j++)
            {
                avail[j] += allocated[t][j];
            }
        }
        else
        {
            p[++d] = p[i];
        }
    }
    if (d != -1)
    {
        pno = d + 1;
        goto A;
    }

    printf("Safe Sequence: <");
    for (int i = 0; i < k; i++)
    {
        printf("p[%d] ", output[i]);
    }
    printf(">\n");
    return 0;
}

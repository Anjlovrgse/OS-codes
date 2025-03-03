#include <stdio.h>
void lruPageReplacement(int pages[], int n, int frames)
{
    int frameArray[frames];
    int recent[frames];
    int pageFaults = 0;

    for (int i = 0; i < frames; i++)
    {
        frameArray[i] = -1;
        recent[i] = -1;
    }
    printf("\nPage Replacement Process:\n");

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        int hit = -1;

        for (int j = 0; j < frames; j++)
        {
            if (frameArray[j] == page)
            {
                hit = j;
                break;
            }
        }

        if (hit != -1)
        {
            recent[hit] = i;
        }
        else
        {
            int lruIndex = 0;
            for (int j = 1; j < frames; j++)
            {
                if (recent[j] < recent[lruIndex])
                {

                    lruIndex = j;
                }
            }

            frameArray[lruIndex] = page;
            recent[lruIndex] = i;
            pageFaults++;
        }

        printf("Page %d -> [ ", page);
        for (int j = 0; j < frames; j++)
        {
            if (frameArray[j] != -1)
                printf("%d ", frameArray[j]);
            else
                printf("- ");
        }
        if (hit == -1)
            printf("] (Page Fault)\n");
        else
            printf("] (Hit)\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}
int main()
{
    int n, frames;

    printf("Enter the number of page requests: ");
    scanf("%d", &n);
    int pages[n];

    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    lruPageReplacement(pages, n, frames);
    return 0;
}
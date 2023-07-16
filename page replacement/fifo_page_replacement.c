#include<stdio.h>
int main()
{
    int incomingStream[20];
    int pageFaults = 0;
    int i, m, n, s, pages, frames;

    printf("Enter the length of the Reference string: ");
    scanf("%d", &pages);

    printf("Enter the reference string: ");
    for (i = 0; i <pages; i++)
        scanf("%d", &incomingStream[i]);

    printf("Enter the number of Frames: ");
    scanf("%d", &frames);

    printf("\nIncoming \t Frame 1 \t Frame 2 \t Frame 3");
    int temp[frames];

    for(m = 0; m < frames; m++)
        temp[m] = -1;

    for(m = 0; m < pages; m++)
    {
        s = 0;

        for(n = 0; n < frames; n++)
        {
            if(incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;

        if((pageFaults <= frames) && (s == 0))
            temp[m] = incomingStream[m];

        else if(s == 0)
            temp[(pageFaults - 1) % frames] = incomingStream[m];

        printf("\n");
        printf("%d\t\t",incomingStream[m]);

        for(n = 0; n < frames; n++)
        {
            if(temp[n] != -1)
                printf(" %d\t\t", temp[n]);
            else
                printf(" - \t\t");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}

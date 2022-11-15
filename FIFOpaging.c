#include <stdio.h>
#include <string.h>

int main()
{
    int page_frames = 0, no_of_pages = 0, page_faults = 0;
    printf("Enter the number of page frames: ");
    scanf("%d", &page_frames);
    printf("Enter the number of pages: ");
    scanf("%d", &no_of_pages);

    int input[no_of_pages], frames[page_frames];

    for (int i = 0; i < page_frames; i++)
    {
        frames[i] = -1;
    }

    printf("Enter the page sequence: ");
    for (int i = 0; i < no_of_pages; i++)
    {
        scanf("%d", &input[i]);
    }

    for (int i = 0; i < no_of_pages; i++)
    {
        int local_page_fault = 1;
        for (int j = 0; j < page_frames; j++)
        {
            if (input[i] == frames[j])
            {
                local_page_fault = 0;
            }
        }

        if (local_page_fault == 1)
        {
            frames[page_faults % page_frames] = input[i];
            page_faults++;
        }

        printf("\n");
        for (int j = 0; j < page_frames; j++)
        {
            if (frames[j] == -1)
                printf("-\t");
            else
                printf("%d\t", frames[j]);
        }
    }

    printf("\n\nFinal Page Fault Count = %d", page_faults);

    return 0;
}
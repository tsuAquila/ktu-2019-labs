#include <stdio.h>

int main()
{
    int hit = 0, miss = 0;
    int page_n, frame_n, frame_index = -1;

    printf("No. of page requests: ");
    scanf("%d", &page_n);

    printf("Frame No.: ");
    scanf("%d", &frame_n);
    int frames[frame_n];

    int pages[page_n];
    printf("Page Queue: ");
    for (int i = 0; i < page_n; i++)
        scanf("%d", &pages[i]);

    for (int i = 0; i < page_n; i++)
    {
        if (frame_index == -1)
        {
            frame_index++;
            frames[frame_index] = pages[i];
            hit++;
        }
        
        else
        {
            
        }
        
    }
    

        return 0;
}
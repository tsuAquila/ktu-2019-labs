#include <stdio.h>
#include <stdlib.h>

int main()
{
    int RQ[100], n, totalHeadMovement = 0, initial;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Initial Head Position: ");
    scanf("%d", &initial);

    printf("Enter the Requests Sequence:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &RQ[i]);
    }

    for (int i = 0; i < n; i++)
    {
        totalHeadMovement += abs(RQ[i] - initial);
        initial = RQ[i];
    }

    printf("\nScheduling Pattern: %d\t", initial);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", &RQ[i]);
    }

    printf("Total Head Moment is %d\n", totalHeadMovement);
    return 0;
}
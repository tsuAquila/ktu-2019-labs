#include <stdio.h>

void main()
{
    int f = -1, r = -1;
    int Q[10];
    int choice, n, elt;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    do
    {
        printf("Enter the choice\n");
        printf("(1)-Insert, (2)-Delete, (3)-View, (4)-Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (r != n - 1)
            {
                r++;
                printf("Enter the element: ");
                scanf("%d", &elt);
                Q[r] = elt;
                if (f == -1)
                {
                    f = 0;
                }
            }
            else
            {
                printf("Queue Overflow!\n");
            }

            printf("\n");
            break;

        case 2:
            if (f != -1)
            {
                elt = Q[f];
                printf("Deleted element is %d.\n", elt);

                if (f == r)
                {
                    f = -1;
                    r = -1;
                }
                else
                {
                    f++;
                }
            }
            else
            {
                printf("Queue Underflow! / Queue is Empty!\n");
            }
            printf("\n");
            break;

        case 3:
            if (r != -1)
            {
                for (int i = f; i <= r; i++)
                {
                    printf("%d\t", Q[i]);
                }
                printf("\n");
            }
            else
            {
                printf("Queue Underflow! / Queue is Empty!\n");
            }
            printf("\n");
            break;

        case 4:
            printf("\n");
            break;

        default:
            printf("Enter a valid choice!\n");
            printf("\n");
            break;
        }

    } while (choice != 4);
}
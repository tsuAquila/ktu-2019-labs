#include <stdio.h>

void main()
{
    int f = -1, r = -1;
    int CQ[10];
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
            if ((r == n - 1 && f == 0) || (f == r + 1))
            {
                printf("Queue Overflow!\n");
            }

            else
            {
                if (r == n - 1)
                {
                    r = 0;
                }
                else
                {
                    r++;
                }

                printf("Enter the element: ");
                scanf("%d", &elt);
                CQ[r] = elt;
                if (f == -1)
                {
                    f = 0;
                }
            }

            printf("\n");
            break;

        case 2:
            if (f == -1)
            {
                printf("Queue Underflow! / Queue is Empty!\n");
            }
            else
            {
                elt = CQ[f];
                printf("Deleted element is %d.\n", elt);

                if (f == r)
                {
                    f = -1;
                    r = -1;
                }

                else if (f == n - 1)
                {
                    f = 0;
                }

                else
                {
                    f++;
                }
            }
            printf("\n");
            break;

        case 3:
            printf("f=%d, r=%d\n", f, r);
            if (f < r)
            {
                for (int i = f; i <= r; i++)
                {
                    printf("%d\t", CQ[i]);
                }
                printf("\n");
            }

            else if (f > r)
            {
                for (int i = f; i < n; i++)
                {
                    printf("%d\t", CQ[i]);
                }
                for (int i = 0; i <= r; i++)
                {
                    printf("%d\t", CQ[i]);
                }

                printf("\n");
            }

            else if (f == r)
            {
                printf("%d", CQ[f]);
            }
            else if (f == -1)
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

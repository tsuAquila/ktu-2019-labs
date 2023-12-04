// Implementation of DEQue

#include <stdio.h>

void main()
{
    int Q[10];
    int n; // size
    int f = -1, r = -1;
    int e;

    int choice_dq;
    int choice;

    printf("Enter size: ");
    scanf("%d", &n);
    do
    {
        printf("Enter choice\n(1)Input restricted DQ (2)Output restricted DQ (3)EXIT: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            do
            {
                printf("Enter Choice\n(1)ADD Rear (2)DEL Front (3)DEL Back (4)Display (5)Exit: ");
                scanf("%d", &choice_dq);

                switch (choice_dq)
                {
                case 1:

                    if (f == 0 && r == n - 1 || f == r + 1)
                    {
                        printf("Q overflow\n");
                    }
                    else
                    {
                        printf("Enter element to add: ");
                        scanf("%d", &e);

                        if (r == n - 1)
                        {
                            r = 0;
                        }
                        else
                        {
                            r++;
                        }

                        Q[r] = e;

                        if (f == -1)
                        {
                            f = 0;
                        }
                    }
                    break;

                case 2:

                    if (f == -1)
                    {
                        printf("Q underflow!\n");
                    }
                    else
                    {
                        e = Q[f];

                        if (f == r)
                        {
                            f = r = -1;
                        }
                        else
                        {
                            if (f == n - 1)
                            {
                                f = 0;
                            }
                            else
                            {
                                f++;
                            }
                        }

                        printf("Removed element is %d\n", e);
                    }
                    break;

                case 3:

                    if (r == -1)
                    {
                        printf("Q underflow!\n");
                    }
                    else
                    {
                        e = Q[r];

                        if (f == r)
                        {
                            f = r = -1;
                        }
                        else
                        {
                            if (r == 0)
                            {
                                r = n - 1;
                            }
                            else
                            {
                                r--;
                            }
                        }

                        printf("Removed element is %d\n", e);
                    }
                    break;

                case 4:

                    if (r == -1)
                    {
                        printf("Empty Q!\n");
                    }
                    else
                    {
                        printf("elements in Q are: ");

                        if (f <= r)
                        {
                            for (int i = f; i <= r; i++)
                            {
                                printf("%d\n", Q[i]);
                            }
                        }
                        else
                        {
                            for (int i = f; i < n; i++)
                            {
                                printf("%d\n", Q[i]);
                            }
                            for (int i = 0; i <= r; i++)
                            {
                                printf("%d\n", Q[i]);
                            }
                        }
                    }
                    break;
                }
            } while (choice_dq != 5);
            break;

        case 2:
            do
            {
                printf("Enter Choice\n(1)ADD Front (2)ADD Rear (3)DEL Back (4)Display (5)Exit: ");
                scanf("%d", &choice_dq);

                switch (choice_dq)
                {
                case 1:

                    if (f == 0 && r == n - 1 || f == r + 1)
                    {
                        printf("Q overflow!\n");
                    }
                    else
                    {
                        printf("Enter element to add: ");
                        scanf("%d", &e);

                        if (f == -1 || f == 0)
                        {
                            f = n - 1;
                        }
                        else
                        {
                            f--;
                        }

                        Q[f] = e;

                        if (r == -1)
                        {
                            r = n - 1;
                        }
                    }
                    break;

                case 2:

                    if (f == 0 && r == n - 1 || f == r + 1)
                    {
                        printf("Q overflow!\n");
                    }
                    else
                    {
                        printf("Enter element to add: ");
                        scanf("%d", &e);

                        if (r == n - 1)
                        {
                            r = 0;
                        }
                        else
                        {
                            r++;
                        }

                        Q[r] = e;

                        if (f == -1)
                        {
                            f = 0;
                        }
                    }
                    break;

                case 3:

                    if (r == -1)
                    {
                        printf("Q underflow!\n");
                    }
                    else
                    {
                        e = Q[r];

                        if (f == r)
                        {
                            f = r = -1;
                        }
                        else
                        {
                            if (r == 0)
                            {
                                r = n - 1;
                            }
                            else
                            {
                                r--;
                            }
                        }

                        printf("Removed element is %d\n", e);
                    }
                    break;

                case 4:

                    if (r == -1)
                    {
                        printf("Empty Q\n");
                    }
                    else
                    {
                        printf("elements in Q are: ");

                        if (f <= r)
                        {
                            for (int i = f; i <= r; i++)
                            {
                                printf("%d\n", Q[i]);
                            }
                        }
                        else
                        {
                            for (int i = f; i < n; i++)
                            {
                                printf("%d\n", Q[i]);
                            }
                            for (int i = 0; i <= r; i++)
                            {
                                printf("%d\n", Q[i]);
                            }
                        }
                    }
                    break;
                }
            } while (choice_dq != 5);

            break;

        case 3:
            break;

        default:
            printf("Invalid operation\n");
            break;
        }
    } while (choice != 3);
}
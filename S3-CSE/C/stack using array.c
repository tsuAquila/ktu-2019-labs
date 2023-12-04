#include <stdio.h>

void main()
{
    int s[10];
    int n, choice, top = -1, elt;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    do
    {
        printf("Enter the choice\n");
        printf("(1)-PUSH, (2)-POP, (3)-View, (4)-Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (top != n - 1)
            {
                top++;
                printf("Enter the element: ");
                scanf("%d", &elt);
                s[top] = elt;
            }
            else
            {
                printf("Stack Overflow!\n");
            }
            printf("\n");
            break;

        case 2:
            if (top != -1)
            {
                elt = s[top];
                printf("Popped element is %d.\n", elt);
                top--;
            }
            else
            {
                printf("Stack Underflow! / Stack is Empty!\n");
            }
            printf("\n");
            break;

        case 3:
            if (top != -1)
            {
                for (int i = 0; i <= top; i++)
                {
                    printf("%d\t", s[i]);
                }
                printf("\n");
            }
            else
            {
                printf("Stack Underflow! / Stack is Empty!\n");
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
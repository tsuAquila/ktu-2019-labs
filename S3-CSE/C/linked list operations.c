#include <stdio.h>
#include <stdlib.h>
void main()
{
    int choice;
    int elt;
    int S;
    struct node
    {
        int data;
        struct node *link;
    };
    struct node *start = NULL, *ptr = NULL, *prev = NULL, *next = NULL;
    struct node *newnode = NULL;

    printf("(1)-Insert at Beginning\n(2)-Insert at End\n(3)-Insert after Element S\n(4)-Delete from Beginning\n(5)- Delete from End\n(6)-Delete S\n(7)-Display\n(8)-Exit");

    do
    {
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter element: ");
            scanf("%d", &elt);
            newnode->data = elt;
            newnode->link = NULL;
            if (start == NULL)
            {
                start = newnode;
                ptr = newnode;
            }
            else
            {
                newnode->link = start;
                ptr = start;
                start = newnode;
            }
            break;

        case 2:
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter element: ");
            scanf("%d", &elt);
            newnode->data = elt;
            newnode->link = NULL;
            if (start == NULL)
            {
                start = newnode;
                ptr = newnode;
            }
            else
            {
                ptr = start;
                while ((*ptr).link != NULL)
                {
                    ptr = (*ptr).link;
                }

                ptr->link = newnode;
                ptr = newnode;
            }
            break;

        case 3:
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the element S: ");
            scanf("%d", &S);
            printf("Enter element: ");
            scanf("%d", &elt);
            newnode->data = elt;
            newnode->link = NULL;
            ptr = start;
            while ((*ptr).data != S)
            {
                ptr = (*ptr).link;
            }
            if ((*ptr).link != NULL)
            {
                newnode->link = (*ptr).link;
                ptr->link = newnode;
                printf("%d inserted after %d.\n", elt, S);
            }
            else
            {
                ptr->link = newnode;
            }
            break;

        case 4:
            ptr = start;
            printf("%d is deleted.\n", (*ptr).data);
            start = (*ptr).link;
            break;

        case 5:

            if (start == NULL)
            {
                printf("Empty List!\n");
            }
            else
            {
                ptr = start;
                while ((*ptr).link != NULL)
                {
                    prev = ptr;
                    ptr = (*ptr).link;
                }
                elt = (*ptr).data;
                (*prev).link = NULL;
                printf("Deleted element is %d.\n", elt);
                if (ptr == start)
                {
                    start = NULL;
                }
            }
            break;

        case 6:
            ptr = start;
            printf("Enter the element S: ");
            scanf("%d", &S);
            while ((*ptr).data != S)
            {
                prev = ptr;
                ptr = (*ptr).link;
            }
            if (ptr == start)
            {
                start = (*ptr).link;
            }
            else
            {
                (*prev).link = (*ptr).link;
            }
            printf("%d is deleted.\n", S);
            break;

        case 7:
            if (start == NULL)
            {
                printf("List Underflow!!\n");
            }
            else
            {
                printf("Entered List is:");

                ptr = start;
                while ((*ptr).link != NULL)
                {
                    printf("%d, ", (*ptr).data);
                    ptr = (*ptr).link;
                }
                printf("%d\n", (*ptr).data);
            }
            break;

        case 8:
            break;

        default:
            printf("Enter a valid choice!");
            break;
        }

    } while (choice != 8);
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void main()
{
    struct node *start = NULL, *ptr = NULL, *newnode = NULL;
    int choice, data;

    do
    {
        printf("\nEnter choice\n\t(1)-Insert\t(2)-View\t(3)-Sort\t(4)-Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &newnode->data);
            newnode->next = NULL;

            if (start == NULL)
            {
                start = newnode;
                ptr = start;
            }
            else
            {
                ptr->next = newnode;
                ptr = newnode;
            }
            break;

        case 2:
            ptr = start;
            while (ptr != NULL)
            {
                printf("%d\t", ptr->data);
                ptr = ptr->next;
            }
        
        case 3:
            

        case 4:
            break;

        default:
            break;
        }

    } while (choice != 4);
}

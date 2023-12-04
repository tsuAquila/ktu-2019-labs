#include <stdio.h>
#include <stdlib.h>

void main()
{
    struct node
    {
        int data;
        struct node *lchild;
        struct node *rchild;
    };

    struct node *root = NULL, *newnode, *ptr, *parent;
    int choice, elt;

    do
    {
        printf("Enter choice (1)-Insert (2)-Search:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter value: ");
            scanf("%d", &elt);
            newnode->data = elt;
            if (root == NULL)
            {
                root = newnode;
            }
            else
            {
                ptr = root;
                while (ptr != NULL)
                {
                    parent = ptr;
                    if (elt > ptr->data)
                        ptr = ptr->rchild;
                    if (elt < ptr->data)
                        ptr = ptr->lchild;
                }
                if (elt > parent->data)
                    parent->rchild = newnode;
                if (elt < parent->data)
                    parent->lchild = newnode;
            }

            break;

        default:
            break;
        }

    } while (choice != 4);
}
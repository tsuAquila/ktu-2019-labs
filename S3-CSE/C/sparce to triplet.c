#include <stdio.h>

void main()
{
    int a[10][10], a_trip[33][3], temp;

    int r, c;
    printf("Enter the number of Rows & Columns: ");
    scanf("%d%d", &r, &c);

    int non_zero_elm = 0;
    printf("Enter the elements:");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
            temp = a[i][j];
            if (temp != 0)
            {
                non_zero_elm++;
            }
        }
    }

    printf("The entered matrix is:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // check if triplet form is efficient
    if ((3 * (non_zero_elm + 1)) < (r * c))
    {
        // converting sparce matrix to triplet
        int rt = 1;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (a[i][j] != 0)
                {
                    a_trip[rt][0] = i;
                    a_trip[rt][1] = j;
                    a_trip[rt][2] = a[i][j];

                    rt++;
                }
            }
        }

        a_trip[0][0] = r;
        a_trip[0][1] = c;
        a_trip[0][2] = non_zero_elm;

        // printing triplet matrix
        printf("The Sparce Matrix in Triplet form is:\n");

        for (int i = 0; i < rt; i++)
        {
            printf("%d\t%d\t%d\n", a_trip[i][0], a_trip[i][1], a_trip[i][2]);
        }
    }

    else
    {
        printf("Normal Matrix is efficient!\n");

        for (int i = 0; i <= r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                printf("%d\t", a[i][j]);
            }
            printf("\n");
        }
    }
}
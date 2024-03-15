#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool is_empty()
{
    return front == -1;
}

bool is_full()
{
    return rear == MAX_SIZE - 1;
}

void enqueue(int value)
{
    if (is_full())
    {
        printf("Queue is full\n");
        return;
    }
    if (is_empty())
    {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

int dequeue()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return value;
}

int peek()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

void display()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

struct rr
{
    int pid, at, bt, r_bt, ct, tat, rt;
};

void swap(struct rr *a, struct rr *b) // struct swap function (cuz using temp everytime is too much)
{
    struct rr t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int n;
    printf("No. of Processes: ");
    scanf("%d", &n);

    struct rr P[n];
    printf("Enter\nPID\tAT\tBT\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &P[i].pid, &P[i].at, &P[i].bt);
        P[i].r_bt = P[i].bt;
    }

    // bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (P[j].at > P[j + 1].at) // sort based on at
                swap(&P[j], &P[j + 1]);

            else if (P[j].at == P[j + 1].at) // if at is same
            {
                if (P[j].pid > P[j + 1].pid) // sort based on pid
                    swap(&P[j], &P[j + 1]);
            }
        }
    }

    int quanta;
    printf("Time Quanta: ");
    scanf("%d", &quanta);

    int gantt[100], g_index = -1;
    for (int i = 0; i < n; i++)
    {
    }

    printf("The Sorted Processes:\n");
    printf("PID\tAT\tBT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", P[i].pid, P[i].at, P[i].bt);

    return 0;
}

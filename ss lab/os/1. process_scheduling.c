#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int pid, at, bt, p;
  int st, rbt;
  int ct;
} process;

void swap(process *a, process *b) {
  process t = *a;
  *a = *b;
  *b = t;
}

int arr[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int x) {
  if (rear == MAX_SIZE - 1) {
    printf("Queue is full\n");
    return;
  }
  if (front == -1)
    front = 0;

  rear++;
  arr[rear] = x;
}

int dequeue() {
  if (front == -1 || front > rear) {
    printf("Queue is empty\n");
    return -1;
  }
  int x = arr[front];
  front++;
  return x;
}

int isEmpty() { return (front == -1 || front > rear); }

void print_chart(process p[], int size) {
  for (int i = 0; i < size - 1; ++i)
    for (int j = 0; j < size - i - 1; ++j)
      if (p[j].pid > p[j + 1].pid)
        swap(&p[j], &p[j + 1]);

  printf("\n\nCompletion Chart:");
  printf("\nPID\tAT\tBT\tP\tCT\tTAT\tWT\tRT\n");
  float tat = 0, wt = 0, rt = 0;
  for (int i = 0; i < size; ++i) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt,
           p[i].p, p[i].ct, p[i].ct - p[i].at, p[i].ct - p[i].at - p[i].bt,
           p[i].st - p[i].at);
    tat += p[i].ct - p[i].at;
    wt += p[i].ct - p[i].at - p[i].bt;
    rt += p[i].st - p[i].at;
  }
  printf("\nAverage Turnaround Time is %f.\n", tat / size);
  printf("Average Waiting Time is %f.\n", wt / size);
  printf("Average Response Time is %f.\n", rt / size);
}

void fcfs(process *p, int size) {
  printf("FCFS Scheduling\n");

  for (int i = 0; i < size - 1; ++i)
    for (int j = 0; j < size - i - 1; ++j) {
      if (p[j].at > p[j + 1].at)
        swap(&p[j], &p[j + 1]);
      if (p[j].at == p[j + 1].at)
        if (p[j].pid > p[j + 1].pid)
          swap(&p[j], &p[j + 1]);
    }

  p[0].ct = p[0].at + p[0].bt;
  p[0].st = p[0].ct - p[0].bt;

  for (int i = 1; i < size; ++i) {
    if (p[i].at < p[i - 1].ct)
      p[i].ct = p[i - 1].ct + p[i].bt;
    else
      p[i].ct = p[i].at + p[i].bt;
    p[i].st = p[i].ct - p[i].bt;
  }

  print_chart(p, size);
}

void sjf(process *p, int size) {
  printf("SJF Scheduling\n");

  for (int i = 0; i < size - 1; ++i)
    for (int j = 0; j < size - i - 1; ++j) {
      if (p[j].at > p[j + 1].at)
        swap(&p[j], &p[j + 1]);
      if (p[j].at == p[j + 1].at)
        if (p[j].bt > p[j + 1].bt)
          swap(&p[j], &p[j + 1]);
    }

  int clk = 0;
  clk = p[0].ct = p[0].at + p[0].bt;
  p[0].st = p[0].ct - p[0].bt;

  for (int i = 1; i < size; ++i) {
    int index = i - 1;
    while (p[index + 1].at <= clk && (index + 1) < size)
      index++;
    // tsu
    if (index >= i)
      for (int j = i; j < index; ++j)
        for (int k = i; k < index + i - j; ++k)
          if (p[k].bt > p[k + 1].bt)
            swap(&p[k], &p[k + 1]);

    if (p[i].at > clk)
      clk = p[i].at + p[i].bt;
    else
      clk += p[i].bt;

    p[i].ct = clk;
    p[i].st = p[i].ct - p[i].bt;
  }

  print_chart(p, size);
}

void rr(process *p, int size) {
  printf("Round Robin Scheduling\n");

  int tq;
  printf("Time Quanta: ");
  scanf("%d", &tq);

  for (int i = 0; i < size - 1; ++i)
    for (int j = 0; j < size - i - 1; ++j) {
      if (p[j].at > p[j + 1].at)
        swap(&p[j], &p[j + 1]);
      if (p[j].at == p[j + 1].at)
        if (p[j].pid > p[j + 1].pid)
          swap(&p[j], &p[j + 1]);
    }

  int ipi = -1;
  int completed = 0;
  int clk = 0;

  while (completed < size) {
    if (isEmpty()) {
      enqueue(++ipi);
      if (p[ipi].at > clk)
        clk = p[ipi].at;
    } else {
      int deq = dequeue();

      if (p[deq].st == -1)
        p[deq].st = clk;

      if (p[deq].rbt > tq) {
        p[deq].rbt -= tq;
        clk += tq;

        while (ipi + 1 < size && p[ipi + 1].at <= clk)
          enqueue(++ipi);

        enqueue(deq);
      } else if (p[deq].rbt == tq) {
        p[deq].rbt = 0;
        clk += tq;
        p[deq].ct = clk;
        completed += 1;
      } else if (p[deq].rbt < tq) {
        clk += p[deq].rbt;
        p[deq].rbt = 0;
        p[deq].ct = clk;
        completed += 1;
      }
    }
  }

  print_chart(p, size);
}

void priority(process *p, int size) {
  printf("Priority Scheduling\n");

  for (int i = 0; i < size - 1; ++i)
    for (int j = 0; j < size - i - 1; ++j) {
      if (p[j].at > p[j + 1].at)
        swap(&p[j], &p[j + 1]);
      if (p[j].at == p[j + 1].at)
        if (p[j].p > p[j + 1].p)
          swap(&p[j], &p[j + 1]);
    }

  int clk = 0;
  clk = p[0].ct = p[0].at + p[0].bt;
  p[0].st = p[0].ct - p[0].bt;

  for (int i = 1; i < size; ++i) {
    int index = i - 1;
    while (p[index + 1].at <= clk && (index + 1) < size)
      index++;

    if (index >= i)
      for (int j = i; j < index; ++j)
        for (int k = i; k < index + i - j; ++k)
          if (p[k].p > p[k + 1].p)
            swap(&p[k], &p[k + 1]);

    if (p[i].at > clk)
      clk = p[i].at + p[i].bt;
    else
      clk += p[i].bt;

    p[i].ct = clk;
    p[i].st = p[i].ct - p[i].bt;
  }

  print_chart(p, size);
}

int main() {
  printf("Simulation of Process Scheduling Algorithms\n\n");

  int n;
  printf("No. of processes: ");
  scanf("%d", &n);

  process p[n];

  printf("\n\nProcess Details\n");
  printf("*Use 0 for priority if you don't wish to run priority scheduling*\n");
  printf("PID AT BT P\n");
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i].pid);
    scanf("%d", &p[i].at);
    scanf("%d", &p[i].bt);
    scanf("%d", &p[i].p);
    p[i].rbt = p[i].bt;
    p[i].st = -1;
  }

  int choice;
  while (1) {
    printf("\nMenu:\n");
    printf("1. FCFS Scheduling\n");
    printf("2. SJF Scheduling\n");
    printf("3. Round Robin Scheduling\n");
    printf("4. Priority Scheduling\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      fcfs(p, n);
      break;
    case 2:
      sjf(p, n);
      break;
    case 3:
      rr(p, n);
      break;
    case 4:
      priority(p, n);
      break;
    case 0:
      exit(0);
    default:
      printf("Invalid choice. Please enter a valid option.\n");
    }
  }

  return 0;
}

/*
OUTPUT

1.FCFS

a. No. of processes: 5

Process Details
PID AT BT
1   0  4
2   1  3
3   2  1
4   3  2
5   4  5

Menu:
1. FCFS Scheduling
2. SJF Scheduling
3. Round Robin Scheduling
4. Priority Scheduling
0. Exit
Enter your choice: 1
FCFS Scheduling

Completion Chart:
PID	AT	BT	P	CT	TAT	WT	RT
P1	0	4	0	4	4	0	0
P2	1	3	0	7	6	3	3
P3	2	1	0	8	6	5	5
P4	3	2	0	10	7	5	5
P5	4	5	0	15	11	6	6

Average Turnaround Time is 6.800000.
Average Waiting Time is 3.800000.

b. No. of processes: 3

Process Details
PID AT BT
1   0  24
2   0  3
3   0  3

Menu:
1. FCFS Scheduling
2. SJF Scheduling
3. Round Robin Scheduling
4. Priority Scheduling
0. Exit
Enter your choice: 1
FCFS Scheduling

Completion Chart:
PID	AT	BT	P	CT	TAT	WT	RT
P1	0	24	0	24	24	0	0
P2	0	3	0	27	27	24	24
P3	0	3	0	30	30	27	27

Average Turnaround Time is 27.000000.
Average Waiting Time is 17.000000.

c. No. of processes: 3

Process Details
PID AT BT
1   0  24
2   2  3
3   3  3

Menu:
1. FCFS Scheduling
2. SJF Scheduling
3. Round Robin Scheduling
4. Priority Scheduling
0. Exit
Enter your choice: 1
FCFS Scheduling

Completion Chart:
PID	AT	BT	P	CT	TAT	WT	RT
P1	0	24	0	24	24	0	0
P2	2	3	0	27	25	22	22
P3	3	3	0	30	27	24	24

Average Turnaround Time is 25.333334.
Average Waiting Time is 15.333333.

2. SJF

a. No. of processes: 5

Process Details
PID AT BT
1   0  7
2   1  5
3   2  1
4   3  2
5   4  8

Menu:
1. FCFS Scheduling
2. SJF Scheduling
3. Round Robin Scheduling
4. Priority Scheduling
0. Exit
Enter your choice: 2
SJF Scheduling

Completion Chart:
PID	AT	BT	P	CT	TAT	WT	RT
P1	0	7	0	7	7	0	0
P2	1	5	0	15	14	9	9
P3	2	1	0	8	6	5	5
P4	3	2	0	10	7	5	5
P5	4	8	0	23	19	11	11

Average Turnaround Time is 10.600000.
Average Waiting Time is 6.000000.

b. No. of processes: 4

Process Details
PID AT BT
1   0  7
2   2  4
3   4  1
4   5  4

Menu:
1. FCFS Scheduling
2. SJF Scheduling
3. Round Robin Scheduling
4. Priority Scheduling
0. Exit
Enter your choice: 2
SJF Scheduling

Completion Chart:
PID	AT	BT	P	CT	TAT	WT	RT
P1	0	7	0	7	7	0	0
P2	2	4	0	12	10	6	6
P3	4	1	0	8	4	3	3
P4	5	4	0	16	11	7	7

Average Turnaround Time is 8.000000.
Average Waiting Time is 4.000000.

3. Round Robin (Pre-emptive)

No. of processes: 4

Process Details
PID AT BT
1   0  9
2   1  5
3   2  3
4   3  4

Menu:
1. FCFS Scheduling
2. SJF Scheduling
3. Round Robin Scheduling
4. Priority Scheduling
0. Exit
Enter your choice: 3
Round Robin Scheduling
Time Quanta: 5

Completion Chart:
PID	AT	BT	P	CT	TAT	WT	RT
P1	0	9	0	21	21	12	0
P2	1	5	0	10	9	4	4
P3	2	3	0	13	11	8	8
P4	3	4	0	17	14	10	10

Average Turnaround Time is 13.750000.
Average Waiting Time is 8.500000.
Average Response Time is 5.500000.

4. Priority

No. of processes: 3

Process Details
PID AT BT P
1 0 15 3
2 0 10 2
3 0 90 1

Menu:
1. FCFS Scheduling
2. SJF Scheduling
3. Round Robin Scheduling
4. Priority Scheduling
0. Exit
Enter your choice: 4
Priority Scheduling

Completion Chart:
PID	AT	BT	P	CT	TAT	WT	RT
P1	0	15	3	115	115	100	100
P2	0	10	2	100	100	90	90
P3	0	90	1	90	90	0	0

Average Turnaround Time is 101.666664.
Average Waiting Time is 63.333332.
*/
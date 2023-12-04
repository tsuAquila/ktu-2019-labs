#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b) {
  int t = * a;
  * a = * b;
  * b = t;
}

void fcfs(int RQ[], int n) {
  printf("\nFCFS\n");

  int totalHeadMovement = 0;

  for (int i = 1; i < n; i++)
    totalHeadMovement += abs(RQ[i] - RQ[i - 1]);

  printf("\nScheduling Pattern: ");
  for (int i = 0; i < n; i++)
    printf("%d\t", RQ[i]);

  printf("\nTotal Head Movement is %d.\n", totalHeadMovement);
}

void scan(int RQ[], int initial, int size, int n) {
  printf("\nSCAN\n");

  int move, index, totalHeadMovement = 0;
  printf("Enter the head movement direction for high 1 and for low 0: ");
  scanf("%d", & move);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - i; j++)
      if (RQ[j] > RQ[j + 1])
        swap( & RQ[j], & RQ[j + 1]);

  for (int i = 0; i < n; i++) {
    if (RQ[i] == initial)
      index = i;
  }

  if (move == 1) {
    printf("Scheduling Pattern:");
    for (int i = index; i < n; i++)
      printf("\t%d", RQ[i]);
    printf("\t%d", size - 1);
    for (int i = index - 1; i >= 0; i--)
      printf("\t%d", RQ[i]);

    totalHeadMovement = (size - 1) * 2 - RQ[0] - initial;
  }

  if (move == 0) {
    printf("Scheduling Pattern:");
    for (int i = index; i >= 0; i--)
      printf("\t%d", RQ[i]);
    printf("\t%d", 0);
    for (int i = index + 1; i < n; i++)
      printf("\t%d", RQ[i]);

    totalHeadMovement = RQ[n - 1] + initial;
  }

  printf("\nTotal Head Movement is %d.\n", totalHeadMovement);
}

void cscan(int RQ[], int initial, int size, int n) {
  printf("\nC-SCAN\n");

  int move, index, totalHeadMovement = 0;

  printf("Enter the head movement direction for high 1 and for low 0: ");
  scanf("%d", & move);

  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (RQ[j] > RQ[j + 1])
        swap( & RQ[j], & RQ[j + 1]);

  for (int i = 0; i < n; i++)
    if (RQ[i] == initial)
      index = i;

  if (move == 1) {
    printf("Scheduling Pattern:");
    int i;
    for (i = index; i < n; i++)
      printf("\t%d", RQ[i]);
    printf("\t%d\t%d", size - 1, 0);
    for (i = 0; i <= index - 1; i++)
      printf("\t%d", RQ[i]);

    totalHeadMovement = (size - 1) * 2 - (RQ[index] - RQ[index - 1]);
  }

  if (move == 0) {
    printf("Scheduling Pattern:");
    int i;
    for (i = index; i >= 0; i--)
      printf("\t%d", RQ[i]);
    printf("\t%d\t%d", 0, size - 1);
    for (i = n - 1; i >= index + 1; i--)
      printf("\t%d", RQ[i]);

    totalHeadMovement = (size - 1) * 2 - (RQ[index + 1] - RQ[index]);
  }

  printf("\nTotal Head Movement is %d.\n", totalHeadMovement);
}

int main() {
  printf("Disk Scheduling\n");

  int RQ[100], n, totalHeadMovement = 0, initial, size, index = 0;

  printf("Enter the number of Requests: ");
  scanf("%d", & n);

  printf("Enter the total disk size: ");
  scanf("%d", & size);

  printf("Enter the initial Head Position: ");
  scanf("%d", & initial);
  RQ[0] = initial;

  printf("Enter the Requests Sequence:\n");

  for (int i = 1; i <= n; i++)
    scanf("%d", & RQ[i]);

  int choice;
  while (1) {
    printf("\nEnter your choice:\n");
    printf("1. FCFS\n");
    printf("2. SCAN\n");
    printf("3. C-SCAN\n");
    printf("0. Exit\n");
    scanf("%d", & choice);

    switch (choice) {
    case 1:
      fcfs(RQ, n + 1);
      break;
    case 2:
      scan(RQ, initial, size, n + 1);
      break;
    case 3:
      cscan(RQ, initial, size, n + 1);
      break;
    case 0:
      return 0;
    default:
      printf("Invalid choice\n");
      break;
    }
  }
  return 0;
}

OUTPUT

FCFS

Enter the number of Requests: 5
Enter the total disk size: 200
Enter the initial Head Position: 100
Enter the Requests Sequence:
23 89 132 42 187           

Enter your choice:
1. FCFS
2. SCAN
3. C-SCAN
0. Exit
1

FCFS

Scheduling Pattern: 100	23	89	132	42	187	
Total Head Movement is 421.

SCAN
Enter the number of Requests: 8
Enter the total disk size: 200
Enter the initial Head Position: 53
Enter the Requests Sequence:
98 183 37 122 14 124 65 67

Enter your choice:
1. FCFS
2. SCAN
3. C-SCAN
0. Exit
2

SCAN
Enter the head movement direction (for high: 1 and for low: 0) : 0
Scheduling Pattern:	53  37	14  0  65  67  98  122  124  183
Total Head Movement is 236.

Enter your choice:
1. FCFS
2. SCAN
3. C-SCAN
0. Exit
2

SCAN
Enter the head movement direction (for high: 1 and for low: 0) : 1
Scheduling Pattern:	53  65  67  98  122  124  183  199  37  14
Total Head Movement is 331.

C-SCAN

Enter the number of Requests: 8
Enter the total disk size: 200
Enter the initial Head Position: 50
Enter the Requests Sequence:
90 120 35 122 38 128 65 68

Enter your choice:
1. FCFS
2. SCAN
3. C-SCAN
0. Exit
3

C-SCAN
Enter the head movement direction (for high: 1 and for low: 0) : 0
Scheduling Pattern:	50  38  35  0  199  128  122  120  90  68  65
Total Head Movement is 383.

Enter your choice:
1. FCFS
2. SCAN
3. C-SCAN
0. Exit
3

C-SCAN
Enter the head movement direction (for high: 1 and for low: 0) : 1
Scheduling Pattern:	50  65  68  90  120  122  128  199  0  35  38
Total Head Movement is 386.

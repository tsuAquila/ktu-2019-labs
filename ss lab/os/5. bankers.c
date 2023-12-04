#include <stdio.h>

int main() {
  int np, nr;
  printf("No. of Processes: ");
  scanf("%d", & np);
  printf("No. of Resources: ");
  scanf("%d", & nr);

  int allocated[np][nr], max[np][nr], need[np][nr], available[nr];

  printf("Allocation Matrix:\n");
  for (int i = 0; i < np; ++i)
    for (int j = 0; j < nr; ++j)
      scanf("%d", & allocated[i][j]);

  printf("Max Matrix:\n");
  for (int i = 0; i < np; ++i)
    for (int j = 0; j < nr; ++j)
      scanf("%d", & max[i][j]);

  printf("Available Resources: ");
  for (int i = 0; i < nr; ++i)
    scanf("%d", & available[i]);

  printf("\nNeed Matrix:\n");
  for (int i = 0; i < np; ++i) {
    for (int j = 0; j < nr; ++j) {
      need[i][j] = max[i][j] - allocated[i][j];
      printf("%d\t", need[i][j]);
    }
    printf("\n");
  }

  int safe[np], completed[np], flag, k = -1;

  for (int i = 0; i < np; ++i)
    completed[i] = 0;

  for (int i = 0; i < np; ++i) {
    flag = 0;
    if (completed[i] == 0) {
      for (int j = 0; j < nr; ++j) {
        if (need[i][j] > available[j]) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        completed[i] = 1;
        safe[++k] = i;

        for (int j = 0; j < nr; ++j)
          available[j] += allocated[i][j];

        i = -1;
      }
    }
  }

  flag = 0;
  for (int i = 0; i < np; ++i)
    if (completed[i] == 0) {
      printf("\nSystem is in Deadlock!!");
      flag = 1;
      break;
    }

  if (flag == 0) {
    printf("\nSystem is in Safe State.");
    printf("\nSafe Sequence: ");
    for (int i = 0; i < np; ++i)
      printf("\tP%d", safe[i]);
  }

  return 0;
}

OUTPUT

No. of Processes: 5
No. of Resources: 3
Allocation Matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Max Matrix:
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Available Resources: 3 3 2

Need Matrix:
7	4	3	
1	2	2	
6	0	0	
2	1	1	
5	3	1	

System is in Safe State.
Safe Sequence: 	P1	P3	P0	P2	P4

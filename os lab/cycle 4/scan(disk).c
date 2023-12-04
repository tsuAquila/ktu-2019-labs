#include <stdio.h>

int main() {
  int RQ[100], n, totalHeadMovement = 0, initial, size, move, index = 0;

  printf("Enter the number of Requests: ");
  scanf("%d", &n);

  printf("Enter the total disk size: ");
  scanf("%d", &size);

  printf("Enter the initial Head Position: ");
  scanf("%d", &initial);
  RQ[0] = initial;

  printf("Enter the Requests Sequence:\n");

  for (int i = 1; i <= n; i++) {
    scanf("%d", &RQ[i]);
  }

  printf("Enter the head movement direction for high 1 and for low 0: ");
  scanf("%d", &move);

  for (int i = 0; i < n; i++) // bubble sort
  {
    for (int j = 0; j < n - i; j++) {
      if (RQ[j] > RQ[j + 1]) {
        int temp;
        temp = RQ[j];
        RQ[j] = RQ[j + 1];
        RQ[j + 1] = temp;
      }
    }
  }

  // find index of initial
  for (int i = 0; i < n; i++) {
    if (RQ[i] == initial) {
      index = i;
    }
  }

  // check move direction
  if (move == 1) {
    printf("Scheduling Pattern:");
    for (int i = index; i <= n; i++) {
      printf("\t%d", RQ[i]);
    }
    printf("\t%d", size - 1);
    for (int i = index - 1; i >= 0; i--) {
      printf("\t%d", RQ[i]);
    }

    totalHeadMovement = (size - 1) * 2 - RQ[0] - initial;
  }

  if (move == 0) {
    printf("Scheduling Pattern:");
    for (int i = index; i >= 0; i--) {
      printf("\t%d", RQ[i]);
    }
    printf("\t%d", 0);
    for (int i = index + 1; i <= n; i++) {
      printf("\t%d", RQ[i]);
    }

    totalHeadMovement = RQ[n] + initial;
  }

  printf("\nTotal Head Movement is %d.\n", totalHeadMovement);

  return 0;
}
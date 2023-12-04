#include <stdio.h>

void main() {
  int a, i, f = 0;
  printf("Enter the Natural Number: ");
  scanf("%d", &a);
  for (i = 2; i <= a / 2; i++) {
    if (a % i == 0) {
      f = 1;
      break;
    }
  }
  if (f == 0) {
    printf("%d is a Prime Number!", a);
  } else {
    printf("%d is not a Prime Number!", a);
  }
}
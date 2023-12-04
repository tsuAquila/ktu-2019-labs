#include <stdio.h>

void main() {
  int n, sum = 0, t, d;
  printf("Enter the Number: ");
  scanf("%d", &n);
  t = n;
  while (n > 0) {
    d = n % 10;
    sum = sum + (d * d * d);
    n = n / 10;
  }
  if (t == sum) {
    printf("%d is an Armstrong number.", t);
  } else {
    printf("%d is not an Armstrong number.", t);
  }
}
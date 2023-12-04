#include <math.h>
#include <stdio.h>

void main() {
  int n, sum = 0, t, d, digits = 0;
  printf("Enter the Number: ");
  scanf("%d", &n);

  t = n;
  for (digits = 0; t > 0; digits++)
    t /= 10;

  t = n;
  while (t > 0) {
    d = t % 10;
    sum = sum + pow(d, digits);
    t = t / 10;
  }
  if (n == sum)
    printf("%d is an Armstrong number.\n", t);
  else
    printf("%d is not an Armstrong number.\n", t);
}
#include <stdio.h>

void main() {
  int n;
  long fact;
  long factorial(int n);
  printf("Enter the number: ");
  scanf("%d", &n);
  fact = factorial(n);
  printf("The factorial is %d.", fact);
}

long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
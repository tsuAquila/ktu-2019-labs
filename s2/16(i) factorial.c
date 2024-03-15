#include <stdio.h>

unsigned long long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

void main() {
  int n;
  unsigned long long fact;
  printf("Enter the number: ");
  scanf("%d", &n);
  fact = factorial(n);
  printf("The factorial is %llu.", fact);
}

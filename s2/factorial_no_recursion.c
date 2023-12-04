#include <stdio.h>

void main() {
  int n;
  long fact;
  long factorial(int n);
  printf("Enter the number: ");
  scanf("%d", &n);
  fact = factorial(n);
  printf("The factorial is %ld.", fact);
}

long factorial(int n) {
  long int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact = fact * i;
  }
  return fact;
}
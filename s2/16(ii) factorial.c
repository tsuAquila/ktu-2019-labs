#include <stdio.h>

unsigned long long factorial(int n) {
  unsigned long long fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

int main() {
  int n;
  unsigned long long fact;
  printf("Enter the number: ");
  scanf("%d", &n);
  fact = factorial(n);
  printf("The factorial is %llu.\n", fact);
  return 0;
}

#include <stdio.h>

int main() {
  int a, b, sum;
  printf("C Program to add 2 numbers\n\n");
  printf("Enter the first number: ");
  scanf("%d", &a);
  printf("Enter the second number: ");
  scanf("%d", &b);
  sum = a + b;
  printf("The sum of %d and %d is %d", a, b, sum);
}
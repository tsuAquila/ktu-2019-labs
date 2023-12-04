#include <stdio.h>

int main() {
  int a, b, t;
  printf("Program to swap 2 variables using temporary variable\n\n");
  printf("Enter the first number: ");
  scanf("%d", &a);
  printf("Enter the second number: ");
  scanf("%d", &b);
  t = a;
  a = b;
  b = t;
  printf("Swapping Completed!\n");
  printf("a = %d\nb = %d", a, b);
}
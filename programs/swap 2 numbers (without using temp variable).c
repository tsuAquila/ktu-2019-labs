#include <stdio.h>

int main() {
  int a, b;
  printf("Program to swap 2 variables without using temporary variable\n\n");
  printf("Enter the first number: ");
  scanf("%d", &a);
  printf("Enter the second number: ");
  scanf("%d", &b);
  a = a + b;
  b = a - b;
  a = a - b;
  printf("Swapping Completed!\n");
  printf("a = %d\nb = %d", a, b);
}
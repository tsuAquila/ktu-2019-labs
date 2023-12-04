#include <stdio.h>

int main() {
  int a, b, c;
  printf("Program to find the greatest of 2 numbers using conditional "
         "operator\n\n");
  printf("Enter the first number: ");
  scanf("%d", &a);
  printf("Enter the second number: ");
  scanf("%d", &b);
  c = a > b ? a : b;
  printf("The greatest of %d and %d is %d.", a, b, c);
}
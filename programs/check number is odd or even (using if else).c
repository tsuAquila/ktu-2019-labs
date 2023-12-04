#include <stdio.h>

int main() {
  int a;
  printf("Program to check if the number is odd or even using if else "
         "statements.\n\n");
  printf("Enter the number: ");
  scanf("%d", &a);
  if (a % 2 == 0)
    printf("%d is EVEN.", a);
  else
    printf("%d is ODD.", a);
}
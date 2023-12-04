#include <stdio.h>

int main() {
  int a;
  printf("Program to check if the number is positive, negative or 0 using if "
         "statements.\n\n");

  printf("Enter the number: ");
  scanf("%d", &a);
  if (a == 0)
    printf("The number is 0.");
  if (a > 0)
    printf("%d is Positive.", a);
  if (a < 0)
    printf("%d is Negative.", a);
}
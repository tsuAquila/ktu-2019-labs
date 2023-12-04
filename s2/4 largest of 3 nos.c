#include <stdio.h>

int main() {
  int a, b, c;
  printf("Enter the corresponding values for a, b, c: ");
  scanf("%d %d %d", &a, &b, &c);
  printf("Largest No. is: ");
  if (a > b) {
    if (a > c)
      printf("%d", a);
    else if (a < c)
      printf("%d", c);
  } else if (b > a) {
    if (b > c)
      printf("%d", b);
    else if (b < c)
      printf("%d", c);
  }

  return 0;
}
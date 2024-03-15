#include <stdio.h>

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int a, b, temp;
  printf("Enter the first number: ");
  scanf("%d", &a);
  printf("Enter the second number: ");
  scanf("%d", &b);
  printf("Before swapping: a = %d, b = %d\n", a, b);
  swap(&a, &b);
  printf("After swapping: a = %d, b = %d\n", a, b);
  return 0;
}
#include <conio.h>
#include <stdio.h>

void main() {
  char a[30], b[10];
  int i = 0, j = 0;

  printf("Enter the first string: ");
  while ((a[i] = getchar()) != '$') {
    i++;
  }
  printf("Enter the second string: ");
  a[i] = '\0';
  while ((b[j] = getchar()) != '$') {
    j++;
  }
  b[j] = '\0';

  j = 0;
  while (b[j] != '\0') {
    a[i - 1] = b[j];
    i++;
    j++;
  }

  a[i - 1] = '\0';

  j = 0;
  printf("The concatenated string is:\n");
  puts(a);
}
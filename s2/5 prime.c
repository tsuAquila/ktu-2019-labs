#include <stdio.h>

int main() {
  int n;
  printf("Number: ");
  scanf("%d", &n);

  int flag = 0;
  for (int i = 2; i * i < n; i++) {
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }

  if (flag == 0)
    printf("Prime\n");
  else
    printf("Not Prime\n");

  return 0;
}
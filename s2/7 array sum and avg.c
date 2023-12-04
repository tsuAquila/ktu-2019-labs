#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  printf("No. of elements: ");
  scanf("%d", &n);
  float arr[n];

  printf("Enter array elements: ");
  for (int i = 0; i < n; i++)
    scanf("%f", &arr[i]);

  float sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];

  printf("\nSum: %f\nAverage: %f\n", sum, sum / n);

  return 0;
}

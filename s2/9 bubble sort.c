#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  printf("No. of elements: ");
  scanf("%d", &n);
  int arr[n];

  printf("Array Elements: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1]) {
        int t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
      }

  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
    printf("\t%d", arr[i]);
  printf("\n");

  return 0;
}

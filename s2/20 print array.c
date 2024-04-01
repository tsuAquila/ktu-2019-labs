#include <stdio.h>

void print_array(int *arr, int n) {
  printf("The elements are: ");
  for (int i = 0; i < n; i++)
    printf("%d ", *(arr + i));
}

int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  print_array(arr, n);

  return 0;
}
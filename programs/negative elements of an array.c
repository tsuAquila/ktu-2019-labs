#include <stdio.h>

int main() {
  int arr[10], n, i;
  printf("C Program to find the negative numbers in an array\n\n");
  printf("Enter the size of array(<11): ");
  scanf("%d", &n);
  printf("Enter the elements of array: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("The negative elements of the array are: ");
  for (i = 0; i < n; i++) {
    if (arr[i] < 0) {
      printf("%d ", arr[i]);
    }
  }
}
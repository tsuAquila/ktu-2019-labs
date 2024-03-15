#include <stdio.h>

int binarySearch(int arr[], int n, int elt) {
  int first = 0;
  int last = n;
  while (first <= last) {
    int mid = (first + last) / 2;
    if (arr[mid] == elt)
      return mid;
    else if (arr[mid] < elt)
      first = mid + 1;
    else
      last = mid - 1;
  }
  return -1;
}

int linearSearch(int arr[], int n, int elt) {
  for (int i = 0; i < n; i++) {
    if (*(arr + i) == elt)
      return i;
  }
  return -1;
}

void position(int pos, int elt) {
  if (pos != -1)
    printf("%d found at %d", elt, pos);
  else
    printf("%d is not in array!", elt);
}

void main() {
  int arr[10], n, elt, choice;

  do {
    printf("\n\nEnter choice (1)-Binary Search (2)-Linear Search (3)-Exit: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter number of elements: ");
      scanf("%d", &n);
      printf("Enter sorted array for Binary Search:\n");
      for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
      printf("Enter element to search: ");
      scanf("%d", &elt);
      position(binarySearch(arr, n, elt), elt);
      break;

    case 2:
      printf("Enter number of elements: ");
      scanf("%d", &n);
      printf("Enter array for Linear Search:\n");
      for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
      printf("Enter element to search: ");
      scanf("%d", &elt);
      position(linearSearch(arr, n, elt), elt);
      break;

    case 3:
      break;

    default:
      printf("!!Enter valid choice!!");
      break;
    }
  } while (choice != 3);
}
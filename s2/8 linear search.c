#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  printf("No. of elements: ");
  scanf("%d", &n);
  int arr[n];

  printf("Array Elements: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  int elt;
  printf("Enter element to search for: ");
  scanf("%d", &elt);

  int flag = -1;
  for (int i = 0; i < n; i++)
    if (arr[i] == elt)
      flag = i;

  if (flag == -1)
    printf("Element not in array!\n");
  else
    printf("Element found at position %d.\n", flag);

  return 0;
}

#include <stdio.h>

int main() {
  char str1[100], str2[100], result[200];
  int i, j;

  // Reading the first string
  printf("Enter the first string (end with $): ");
  scanf("%[^$]s", str1);

  // Clearing the input buffer
  while (getchar() != '$' || getchar() != '\n')
    ;

  // Reading the second string
  printf("Enter the second string (end with $): ");
  scanf("%[^$]s", str2);

  // Concatenating the strings
  i = 0;
  while (str1[i] != '\0') {
    result[i] = str1[i];
    i++;
  }
  j = 0;
  while (str2[j] != '\0') {
    result[i] = str2[j];
    i++;
    j++;
  }
  result[i] = '\0';

  // Printing the concatenated string
  puts("");
  printf("Concatenated string: %s\n", result);

  return 0;
}

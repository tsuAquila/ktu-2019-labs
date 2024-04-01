#include <stdio.h>

int main() {
  char str[100];
  int vowels = 0, consonants = 0, spaces = 0, i = 0;

  // Reading the string
  printf("Enter a string (end with $): ");
  scanf("%[^$]s", str);

  // Counting vowels, consonants, and spaces
  while (str[i] != '\0') {
    // Checking for vowels
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
        str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
        str[i] == 'O' || str[i] == 'U') {
      vowels++;
    }
    // Checking for consonants
    else if ((str[i] >= 'a' && str[i] <= 'z') ||
             (str[i] >= 'A' && str[i] <= 'Z')) {
      consonants++;
    }
    // Checking for spaces
    else if (str[i] == ' ') {
      spaces++;
    }
    i++;
  }

  // Displaying the counts
  printf("Number of vowels: %d\n", vowels);
  printf("Number of consonants: %d\n", consonants);
  printf("Number of spaces: %d\n", spaces);

  return 0;
}

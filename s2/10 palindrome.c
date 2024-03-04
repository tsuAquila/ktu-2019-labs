#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(char s[], size_t s_count) {
  for (size_t i = 0; i < s_count / 2; ++i)
    if (tolower(s[i]) != tolower(s[s_count - 1 - i]))
      return false;
  return true;
}

int main(int argc, char const *argv[]) {
  char s[100];
  printf("String: ");
  gets(s);
  size_t s_size;
  for (s_size = 0; s[s_size] != '\0'; s_size++) {
  }

  if (isPalindrome(s, s_size))
    printf("String is a Palindrome");
  else
    printf("String is not a Palindrome");

  printf("\n");

  return 0;
}

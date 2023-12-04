#include <stdio.h>

void main() {
  char Str[100], temp;
  int len = 0;

  void revString(char Str[], int i, int len);

  printf("Enter the String/Word: ");
  gets(Str);

  for (int i = 0; i < 100; i++) {
    if (Str[i] == '\0') {
      break;
    } else {
      len = len + 1;
    }
  }
  revString(Str, 0, len - 1);

  printf("Reversed String/Word is %s", Str);
}

void revString(char Str[], int i, int len) {
  char temp;
  temp = Str[i];
  Str[i] = Str[len - i];
  Str[len - i] = temp;

  if (i == len / 2) {
    return;
  }
  revString(Str, i + 1, len);
}
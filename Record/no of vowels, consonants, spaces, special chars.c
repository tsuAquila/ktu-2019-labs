#include <stdio.h>
void main() {

  char a[100];
  int v, c, d, s, sc;

  v = c = d = s = sc = 0;

  printf("Enter a line of string: ");
  gets(a);

  for (int i = 0; a[i] != '\0'; ++i) {
    if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' ||
        a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' ||
        a[i] == 'O' || a[i] == 'U') {
      ++v;
    } else if ((a[i] >= 'b' && a[i] <= 'z') || (a[i] >= 'B' && a[i] <= 'Z')) {
      ++c;
    } else if (a[i] >= '0' && a[i] <= '9') {
      ++d;
    } else if (a[i] == ' ') {
      ++s;
    } else {
      ++sc;
    }
  }
  printf("Vowels: %d", v);
  printf("\nConsonants: %d", c);
  printf("\nNumbers: %d", d);
  printf("\nWhite Spaces: %d", s);
  printf("\nOther Characters: %d", sc);
}

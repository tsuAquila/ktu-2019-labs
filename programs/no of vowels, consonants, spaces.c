#include <stdio.h>

void main() {
  char a[30], vow[5] = {'a', 'e', 'i', 'o', 'u'},
              con[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
                         'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'y', 'z'};
  int v = 0, s = 0, c = 0;
  printf("Enter the String (in lowercase): ");
  gets(a);
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 5; j++) {
      if (a[i] == vow[j]) {
        v = v + 1;
      }
    }
    if (a[i] == ' ') {
      s = s + 1;
    }
  }
  printf("There are %d Vowel/Vowels.\n", v);
  printf("There are %d Consonant/Consonants.\n", c);
  printf("There are %d Space/Spaces.", s);
}
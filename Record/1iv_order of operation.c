#include <stdio.h>

void main() {
  int a, b, c, d, e, f, g;
  float r;
  printf("Enter the corresponding values for a, b, c, d, e, f, g: ");
  scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
  r = ((a - b / c * d + e) * (f + g));
  printf("%f", r);
}
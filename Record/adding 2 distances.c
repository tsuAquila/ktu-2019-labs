#include <stdio.h>

void main() {
  struct addit {
    float x;
    float y;
  } a, b, c;
  printf("Enter the x and y values of first distance: ");
  scanf("%f%f", &a.x, &a.y);
  printf("Enter the x and y values of second distance: ");
  scanf("%f%f", &b.x, &b.y);
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  printf("The sum of both the distances is: (%f,%f).", c.x, c.y);
}
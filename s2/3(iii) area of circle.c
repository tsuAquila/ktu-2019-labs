#include <stdio.h>

int main() {
  float r, a;
  printf("Program to find the area of a circle\n\n");
  printf("Enter the radius of the circle: ");
  scanf("%f", &r);
  a = 22 * r * r / 7;
  printf("The area of the circle of radius %f is %f", r, a);
}
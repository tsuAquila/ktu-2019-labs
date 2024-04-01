#include <stdio.h>

struct point {
  int distance;
};

int main(int argc, char const *argv[]) {
  struct point p1, p2;

  printf("Enter first distance: ");
  scanf("%d", &p1.distance);

  printf("Enter second distance: ");
  scanf("%d", &p2.distance);

  int sum = p1.distance + p2.distance;

  printf("Sum of distances: %d\n", sum);

  return 0;
}

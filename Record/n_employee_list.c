#include <stdio.h>

void main() {
  struct employee {
    char name[20];
    int id;
    long salary;
  } E[10];

  int n;
  printf("Enter the number of employees: ");
  scanf("%d", &n);
  printf("\n");

  for (int i = 0; i < n; i++) {
    printf("Enter the name: ");
    getchar();
    gets(E[i].name);
    printf("Enter the Employee ID: ");
    scanf("%d", &E[i].id);
    printf("Enter the salary: ");
    scanf("%ld", &E[i].salary);
    printf("\n");
  }

  for (int i = 0; i < n; i++) {
    printf("Name: ");
    puts(E[i].name);
    printf("Employee ID: %d", E[i].id);
    printf("\nSalary: %ld\n\n", E[i].salary);
  }
}
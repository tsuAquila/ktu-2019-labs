#include <stdio.h>

// Define the structure for an employee
struct Employee {
  char name[50];
  int employeeID;
  float salary;
};

int main() {
  int n;

  // Read the number of employees
  printf("Enter the number of employees: ");
  scanf("%d", &n);

  // Declare an array of structs to store employee data
  struct Employee employees[n];

  // Clear the input buffer
  while (getchar() != '\n')
    ;

  // Read data for each employee
  for (int i = 0; i < n; i++) {
    printf("\nEnter details for employee %d:\n", i + 1);

    printf("Name: ");
    fgets(employees[i].name, sizeof(employees[i].name),
          stdin); // Allowing spaces in the name

    printf("Employee ID: ");
    scanf("%d", &employees[i].employeeID);

    printf("Salary: ");
    scanf("%f", &employees[i].salary);

    // Clear the input buffer
    while (getchar() != '\n')
      ;
  }

  // Print data for each employee
  printf("\nEmployee Data:\n");
  for (int i = 0; i < n; i++) {
    printf("\nEmployee %d:\n", i + 1);
    printf("Name: %s", employees[i].name);
    printf("Employee ID: %d\n", employees[i].employeeID);
    printf("Salary: %.2f\n", employees[i].salary);
  }

  return 0;
}

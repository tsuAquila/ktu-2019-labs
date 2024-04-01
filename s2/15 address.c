#include <stdio.h>
#include <string.h>

// Define the maximum length for string variables
#define C_SIZE 50

// Define a union for the address
union Address {
  char Name[C_SIZE];
  char HouseName[C_SIZE];
  char CityName[C_SIZE];
  char State[C_SIZE];
  char Pincode[C_SIZE];
};

int main() {
  union Address address;

  // Read address details
  printf("Enter Name: ");
  fgets(address.Name, C_SIZE, stdin);
  address.Name[strcspn(address.Name, "\n")] = 0; // Remove newline character

  printf("Enter House Name: ");
  fgets(address.HouseName, C_SIZE, stdin);
  address.HouseName[strcspn(address.HouseName, "\n")] =
      0; // Remove newline character

  printf("Enter City Name: ");
  fgets(address.CityName, C_SIZE, stdin);
  address.CityName[strcspn(address.CityName, "\n")] =
      0; // Remove newline character

  printf("Enter State: ");
  fgets(address.State, C_SIZE, stdin);
  address.State[strcspn(address.State, "\n")] = 0; // Remove newline character

  printf("Enter Pincode: ");
  fgets(address.Pincode, C_SIZE, stdin);
  address.Pincode[strcspn(address.Pincode, "\n")] =
      0; // Remove newline character

  // Display the address
  printf("\nAddress:\n");
  printf("Name: %s\n", address.Name);
  printf("House Name: %s\n", address.HouseName);
  printf("City Name: %s\n", address.CityName);
  printf("State: %s\n", address.State);
  printf("Pincode: %s\n", address.Pincode);

  return 0;
}

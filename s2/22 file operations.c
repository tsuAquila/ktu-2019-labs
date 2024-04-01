#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  char filename[50];
  char data[100];

  // Open file for writing
  printf("Enter the filename: ");
  scanf("%s", filename);

  file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  // Write data to the file
  printf("Enter data to write to the file (max 100 characters):\n");
  scanf(" %[^\n]", data);
  fprintf(file, "%s\n", data);

  // Close the file
  fclose(file);

  // Open file for reading
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  // Read and display contents of the file
  printf("\nContents of the file:\n");
  while (fgets(data, sizeof(data), file) != NULL) {
    printf("%s", data);
  }

  // Close the file
  fclose(file);

  // Open file for appending
  file = fopen(filename, "a");
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  // Append new data to the file
  printf("\nEnter new data to append to the file (max 100 characters):\n");
  scanf(" %[^\n]", data);
  fprintf(file, "%s\n", data);

  // Close the file
  fclose(file);

  // Open file for reading again
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  // Read and display contents of the file after appending
  printf("\nContents of the file after appending:\n");
  while (fgets(data, sizeof(data), file) != NULL) {
    printf("%s", data);
  }

  // Close the file
  fclose(file);

  return 0;
}

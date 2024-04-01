#include <stdio.h>

// Maximum size for the matrices
#define MAX_SIZE 10

// Function prototypes
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE],
                 int matrix2[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int rows1, int cols1,
                      int matrix2[MAX_SIZE][MAX_SIZE], int cols2);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
  int choice;
  int rows1, cols1, rows2, cols2;
  int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];

  // Menu
  printf("Menu:\n");
  printf("1. Read Matrices\n");
  printf("2. Display Matrices\n");
  printf("3. Add Matrices\n");
  printf("4. Multiply Matrices\n");
  printf("5. Transpose Matrix\n");
  printf("6. Exit\n");

  // Main loop
  do {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the number of rows and columns for matrix 1: ");
      scanf("%d %d", &rows1, &cols1);
      printf("Enter elements for matrix 1:\n");
      readMatrix(matrix1, rows1, cols1);

      printf("Enter the number of rows and columns for matrix 2: ");
      scanf("%d %d", &rows2, &cols2);
      printf("Enter elements for matrix 2:\n");
      readMatrix(matrix2, rows2, cols2);
      break;
    case 2:
      printf("Matrix 1:\n");
      displayMatrix(matrix1, rows1, cols1);
      printf("Matrix 2:\n");
      displayMatrix(matrix2, rows2, cols2);
      break;
    case 3:
      if (rows1 == rows2 && cols1 == cols2)
        addMatrices(matrix1, matrix2, rows1, cols1);
      else
        printf("Matrices must have the same dimensions for addition.\n");
      break;
    case 4:
      if (cols1 == rows2)
        multiplyMatrices(matrix1, rows1, cols1, matrix2, cols2);
      else
        printf("Number of columns in matrix 1 must be equal to the number of "
               "rows in matrix 2 for multiplication.\n");
      break;
    case 5:
      printf("Transpose of Matrix 1:\n");
      transposeMatrix(matrix1, rows1, cols1);
      printf("Transpose of Matrix 2:\n");
      transposeMatrix(matrix2, rows2, cols2);
      break;
    case 6:
      printf("Exiting program...\n");
      break;
    default:
      printf("Invalid choice. Please enter a number between 1 and 6.\n");
    }
  } while (choice != 6);

  return 0;
}

// Function to read a matrix
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE],
                 int matrix2[MAX_SIZE][MAX_SIZE], int rows, int cols) {
  int result[MAX_SIZE][MAX_SIZE];

  printf("Sum of matrices:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int rows1, int cols1,
                      int matrix2[MAX_SIZE][MAX_SIZE], int cols2) {
  int result[MAX_SIZE][MAX_SIZE] = {0};

  printf("Product of matrices:\n");
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols2; j++) {
      for (int k = 0; k < cols1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
}

// Function to find the transpose of a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
  int transpose[MAX_SIZE][MAX_SIZE];

  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      transpose[i][j] = matrix[j][i];
      printf("%d ", transpose[i][j]);
    }
    printf("\n");
  }
}

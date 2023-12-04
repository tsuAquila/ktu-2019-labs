#include <stdio.h>

void main() {
  int matA[10][10], matB[10][10], matC[10][10];
  int a, r, c;
  printf("Enter the corresponding value for the operation (1 = Add, 2 = "
         "Subtract, 3 = Multiply, 4 = Inverse):");
  scanf("%d", &a);
  if (a == 1) {
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    printf("Enter the elements of the First Matrix: ");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", &matA[i][j]);
      }
    }
    printf("Enter the elements of the Second Matrix: ");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", &matB[i][j]);
      }
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        matC[i][j] = matA[i][j] + matB[i][j];
      }
    }
    printf("The added matrix is:\n");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        printf("%d\t", matC[i][j]);
      }
      printf("\n");
    }
  } else if (a == 2) {
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    printf("Enter the elements of the First Matrix: ");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", &matA[i][j]);
      }
    }
    printf("Enter the elements of the Second Matrix: ");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", &matB[i][j]);
      }
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        matC[i][j] = matA[i][j] - matB[i][j];
      }
    }
    printf("The subtracted matrix is:\n");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        printf("%d\t", matC[i][j]);
      }
      printf("\n");
    }
  } else if (a == 3) {
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    printf("Enter the elements of the First Matrix: ");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", &matA[i][j]);
      }
    }
    printf("Enter the elements of the Second Matrix: ");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", &matB[i][j]);
      }
    }
  } else if (a == 4) {
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    printf("Enter the elements of the Matrix: ");
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", &matA[i][j]);
      }
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        matC[i][j] = matA[j][i];
      }
    }
    printf("The transpose matrix is:\n");
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < r; j++) {
        printf("%d\t", matC[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("Enter a Valid Number!");
  }
}
import java.util.Scanner;

class MatMultiplication {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		System.out.print("Enter number of rows of first matrix: ");
		int r1 = s.nextInt();
		System.out.print("Enter number of columns of first matrix: ");
		int c1 = s.nextInt();
		int A[][] = new int[r1][c1];
		System.out.println("\nEnter elements:");
		for (int i = 0; i < r1; i++) {
			for (int j = 0; j < c1; j++) {
				A[i][j] = s.nextInt();
			}
		}

		System.out.print("\nEnter number of rows of second matrix: ");
		int r2 = s.nextInt();
		System.out.print("Enter number of columns of second matrix: ");
		int c2 = s.nextInt();
		int B[][] = new int[r2][c2];
		System.out.println("\nEnter elements:");
		for (int i = 0; i < r2; i++) {
			for (int j = 0; j < c2; j++) {
				B[i][j] = s.nextInt();
			}
		}

		int P[][] = new int[r1][c2];

		if (c1 == r2) {
			for (int i = 0; i < r1; i++) {
				for (int j = 0; j < c2; j++) {
					P[i][j] = 0;
					for (int k = 0; k < r2; k++) {
						P[i][j] = P[i][j] + (A[i][k] * B[k][j]);
					}
				}
			}
			System.out.println("\nProduct Matrix is:");
			for (int i = 0; i < r1; i++) {
				for (int j = 0; j < c2; j++) {
					System.out.print(P[i][j] + "\t");
				}
				System.out.print("\n");
			}
		} else {
			System.out.println(
					"ERROR!!!\nCannot perform matrix multiplication as no. of columns of first matrix and no. of rows of second matrix are not same.");
		}
		s.close();
	}
}

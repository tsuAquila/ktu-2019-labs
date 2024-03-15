import java.util.Scanner;

class MatTranspose {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		System.out.print("Enter number of rows of matrix: ");
		int r = s.nextInt();
		System.out.print("Enter number of columns of matrix: ");
		int c = s.nextInt();
		int mat[][] = new int[r][c];
		int transpose[][] = new int[c][r];
		System.out.println("\nEnter elements:");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				mat[i][j] = transpose[j][i] = s.nextInt();
			}
		}

		System.out.println("\nTranspose Matrix is:");
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				System.out.print(transpose[i][j] + "\t");
			}
			System.out.print("\n");
		}
		s.close();
	}
}

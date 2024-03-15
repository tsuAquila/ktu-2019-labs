import java.util.Scanner;

class QuickSort {

	public void qs(int A[], int p, int r) {
		if (p < r) {
			int q = partition(A, p, r);
			qs(A, p, q - 1);
			qs(A, q + 1, r);
		}
	}

	public int partition(int A[], int p, int r) {
		int pivot = A[r];
		int i = p - 1;
		for (int j = p; j <= r - 1; j++) {
			if (A[j] <= pivot) {
				i++;
				if (A[i] != A[j]) {
					int t = A[j];
					A[j] = A[i];
					A[i] = t;
				}
			}
		}
		int t = A[i + 1];
		A[i + 1] = A[r];
		A[r] = t;
		return i + 1;
	}

	public void display(int[] A) {
		for (int i : A) {
			System.out.print(i + "\t");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of elements: ");
		int n = sc.nextInt();
		int[] A = new int[n];
		System.out.println("\nEnter the elements: ");
		for (int i = 0; i < n; i++) {
			A[i] = sc.nextInt();
		}
		QuickSort qsObj = new QuickSort();
		qsObj.qs(A, 0, n - 1);
		System.out.println("\nSorted Array is: ");
		qsObj.display(A);
		sc.close();
	}
}

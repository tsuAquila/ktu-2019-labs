import java.util.Scanner;

class SecondSmallestElement {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter number of elements: ");
		int n = sc.nextInt();
		int A[] = new int[n];
		System.out.println("Enter the elements:");
		for (int i = 0; i < n; i++) {
			A[i] = sc.nextInt();
		}

		int smallest = A[0];
		int secondSmallest = A[1];

		for (int i : A) {
			if (i < smallest) {
				secondSmallest = smallest;
				smallest = i;
			} else if ((i < secondSmallest) && (i != smallest)) {
				secondSmallest = i;
			}
		}
		System.out.println("Second Smallest element is " + secondSmallest);
		sc.close();
	}
}

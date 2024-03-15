import java.util.Scanner;

class PrimeCheck {
	public static void main(String[] args) {

		int flag = 0;

		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the Number to check Prime: ");
		int n = sc.nextInt();

		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			System.out.println("The number is a Prime number!");
		} else {
			System.out.println("The number is not a Prime number!");
		}
		sc.close();
	}
}

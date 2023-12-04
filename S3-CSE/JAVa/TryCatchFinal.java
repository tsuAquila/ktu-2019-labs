import java.util.Scanner;

class TryCatchFinal {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int x = sc.nextInt();
		try {
			System.out.println("\nTry Block {\n\tAn error is about to occur. }");
			int a = x / 0;
			System.out.println("The Quotient is " + a + "}");
		} catch (ArithmeticException e) {
			System.out.println("\nCatch Block {\n\tError has occured.");
			System.out.println("\t" + e.getMessage() + "}");
		} finally {
			System.out.println("\nFinally Block {\n\t" + x + " is the input number. }");
		}
		sc.close();
	}
}

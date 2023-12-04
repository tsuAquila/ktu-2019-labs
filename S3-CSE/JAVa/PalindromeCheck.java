import java.util.Scanner;

class PalindromeCheck {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the String: ");
		String s = sc.nextLine();
		String fS = s.toLowerCase();
		int flag = 1;
		for (int i = 0; i < (fS.length() / 2) + 1; i++) {
			if (fS.charAt(i) != fS.charAt(fS.length() - 1 - i)) {
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			System.out.println(s + " is a Palindrome.");
		else
			System.out.println(s + " is not a Palindrome.");

		sc.close();
	}
}

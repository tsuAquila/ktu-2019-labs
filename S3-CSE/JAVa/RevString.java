import java.util.Scanner;

class RevString {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the String to reverse: ");
		String s = sc.nextLine();
		String rev = "";
		for (int i = 0; i < s.length(); i++)
			rev = rev + (s.charAt(s.length() - 1 - i));
		System.out.println("Reversed String is: " + rev);
		sc.close();
	}
}

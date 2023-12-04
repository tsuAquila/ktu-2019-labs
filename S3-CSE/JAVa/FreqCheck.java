import java.util.Scanner;

class FreqCheck {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the String: ");
		String s = sc.nextLine();
		System.out.print("Enter the character to search: ");
		char x = sc.next().charAt(0);
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == x)
				count++;
		}
		System.out.println(x + " is present in '" + s + "' " + count + " times.");
		sc.close();
	}
}

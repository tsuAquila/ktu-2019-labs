import java.util.Scanner;

class MTable extends Thread {
	private int a, n;

	public MTable(int a, int n) {
		this.a = a;
		this.n = n;
	}

	public synchronized void display(int a, int n) {
		for (int i = 1; i <= n; i++) {
			System.out.println("\t" + a + " * " + i + " = " + (a * i));
		}
	}

	public void run() {
		display(a, n);
	}
}

class ThreadSynchronization {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("Enter number of multiples of 5 & 10: ");
		int n1 = s.nextInt();
		int n2 = s.nextInt();
		System.out.println();
		MTable m1 = new MTable(5, n1);
		MTable m2 = new MTable(10, n2);
		try {
			m1.start();
			m2.start();
			m1.join();
			m2.join();
		} catch (InterruptedException e) {
			System.out.println(e.getMessage());
		}
		s.close();
	}
}

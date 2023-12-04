class OddDisplay extends Thread {
	public void run() {
		for (int i = 1; i < 100; i = i + 2)
			System.out.println("Odd: " + i);
	}
}

class EvenDisplay extends Thread {
	public void run() {
		for (int i = 2; i < 100; i = i + 2)
			System.out.println("Even: " + i);
	}
}

class ThreadPractise {
	public static void main(String[] args) {
		OddDisplay o = new OddDisplay();
		EvenDisplay e = new EvenDisplay();
		o.start();
		e.start();

		try {
			o.join();
			e.join();
		} catch (InterruptedException f) {
			System.out.println(f.getMessage());
		}
	}
}

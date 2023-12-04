import java.util.Scanner;

class Area {

	public void area(float r) {
		System.out.println("The area of Circle is " + (3.14 * r * r) + "\n");
	}

	public void area(int l, int w) {
		System.out.println("The area of Rectangle is " + (l * w) + "\n");
	}

	public void area(int h, float b) {
		System.out.println("The area of Triangle is " + (0.5 * b * h) + "\n");
	}
}

class MethodOverloading {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		Area a = new Area();

		System.out.println("Enter the radius (float) of Circle:");
		float r = sc.nextFloat();
		a.area(r);

		System.out.println("Enter the length (int) and width (int) of Rectangle:");
		int l = sc.nextInt();
		int w = sc.nextInt();
		a.area(l, w);

		System.out.println("Enter the height (int) and base length (float) of Triangle:");
		int h = sc.nextInt();
		float b = sc.nextFloat();
		a.area(h, b);
		sc.close();
	}
}

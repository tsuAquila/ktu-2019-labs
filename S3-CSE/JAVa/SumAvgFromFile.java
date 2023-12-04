import java.io.*;

class SumAvgFromFile {
	public static void main(String[] args) {
		try {
			Integer sum = 0, count = 0;
			FileReader fr = new FileReader("Integers.txt");
			BufferedReader br = new BufferedReader(fr);
			String sOriginal = br.readLine();
			String sArr[] = sOriginal.split("\\s+");
			for (String i : sArr) {
				sum = sum + Integer.parseInt(i);
				count++;
			}
			fr.close();
			System.out.println("Sum = " + sum + "\nAverage = " + (sum / count));
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}
}

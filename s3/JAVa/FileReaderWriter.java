import java.io.*;

class FileReaderWriter {
	public static void main(String[] args) {
		try {
			FileWriter fw = new FileWriter("copy.txt");
			FileReader fr = new FileReader("A.txt");
			BufferedReader br = new BufferedReader(fr);
			String s;
			while ((s = br.readLine()) != null) {
				fw.write(s);
			}
			fw.close();
			fr.close();
			System.out.println("String Copying Completed!");
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}
}

import java.io.*;

class FileStreams {
	public static void main(String[] args) {
		try {
			FileInputStream fin = new FileInputStream("A.txt");
			FileOutputStream fout = new FileOutputStream("copy.txt");
			int i;
			while ((i = fin.read()) != -1) {
				fout.write(i);
			}
			fin.close();
			fout.close();
			System.out.println("File Copying Completed!");
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}
}

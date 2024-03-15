import java.io.*;

class Person implements Serializable {
	private String name;
	private int age;

	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
}

class SerializableTest {
	public static void main(String[] args) {
		try {
			Person p = new Person("John", 19);
			FileOutputStream fout = new FileOutputStream("John.txt");
			ObjectOutputStream obj = new ObjectOutputStream(fout);
			obj.writeObject(p);
			fout.close();
			System.out.println("The object has been converted to byte stream and stored in file.");
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}
}

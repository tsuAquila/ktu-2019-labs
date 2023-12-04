class Employee {
	private String name;
	private int age;
	private int phoneNumber;
	private String address;
	private int salary;

	public void setVals(String name, int age, int phoneNumber, String address, int salary) {
		this.name = name;
		this.age = age;
		this.phoneNumber = phoneNumber;
		this.address = address;
		this.salary = salary;
	}

	public void getVals() {
		System.out.println("\tName: " + name);
		System.out.println("\tAge: " + age);
		System.out.println("\tPhone Number: " + phoneNumber);
		System.out.println("\tAddress: " + address);
	}

	public void print_Salary() {
		System.out.println("\tSalary: " + salary);
	}
}

class Officer extends Employee {
	private String specialisation;

	public void setSpec(String specialisation) {
		this.specialisation = specialisation;
	}

	public String getSpec() {
		return specialisation;
	}
}

class Manager extends Employee {
	private String department;

	public void setDept(String department) {
		this.department = department;
	}

	public String getDept() {
		return department;
	}
}

class InheritenceHierarchy {
	public static void main(String args[]) {

		Officer o1 = new Officer();
		Manager m1 = new Manager();

		o1.setVals("Abhishek", 20, 302243, "Marian Engineering College, Kazhakkoottam", 20000);
		o1.setSpec("Alpha");

		m1.setVals("Deepu", 23, 54856, "Neyyattinkara, Thiruvananthapuram", 28000);
		m1.setDept("Health");

		System.out.println("Officer Details:\n");
		o1.getVals();
		o1.print_Salary();
		System.out.println("\tSpecialisation: " + o1.getSpec());
		System.out.println("\n");

		System.out.println("Manager Details:\n");
		m1.getVals();
		m1.print_Salary();
		System.out.println("\tDepartment: " + m1.getDept());
	}

}

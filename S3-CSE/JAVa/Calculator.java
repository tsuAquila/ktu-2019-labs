import java.awt.event.*;
import javax.swing.*;

class Calculator extends JFrame implements ActionListener {
	private JLabel l1;
	private JLabel l2;
	private JLabel l3;
	private JLabel l4;
	private JTextField t1;
	private JTextField t2;
	private JButton b1;
	private JButton b2;
	private JButton b3;
	private JButton b4;

	public Calculator() {
		setSize(600, 600);
		setLayout(null);

		l1 = new JLabel("First No.:");
		l1.setBounds(100, 100, 75, 50);
		add(l1);
		l2 = new JLabel("Second No.:");
		l2.setBounds(100, 200, 90, 50);
		add(l2);
		l3 = new JLabel("Answer: ");
		l3.setBounds(250, 500, 90, 50);
		add(l3);
		l4 = new JLabel();
		l4.setBounds(350, 500, 90, 50);
		add(l4);

		t1 = new JTextField();
		t1.setBounds(300, 100, 75, 50);
		add(t1);
		t2 = new JTextField();
		t2.setBounds(300, 200, 75, 50);
		add(t2);

		b1 = new JButton("+");
		b1.setBounds(100, 350, 75, 50);
		add(b1);
		b2 = new JButton("-");
		b2.setBounds(200, 350, 75, 50);
		add(b2);
		b3 = new JButton("*");
		b3.setBounds(300, 350, 75, 50);
		add(b3);
		b4 = new JButton("/");
		b4.setBounds(400, 350, 75, 50);
		add(b4);

		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) {
		Integer a = Integer.parseInt(t1.getText());
		Integer b = Integer.parseInt(t2.getText());
		Integer result = 0;

		if (e.getSource() == b1)
			result = a + b;
		else if (e.getSource() == b2)
			result = a - b;
		else if (e.getSource() == b3)
			result = a * b;
		else if (e.getSource() == b4)
			result = a / b;

		l4.setText(result.toString());
	}

	public static void main(String[] args) {
		Calculator c = new Calculator();
		c.setVisible(true);
	}
}

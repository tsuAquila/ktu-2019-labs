import java.awt.event.*;
import javax.swing.*;

class NoOfWords extends JFrame implements ActionListener {
	private JLabel l1;
	private JLabel l2;
	private JTextField t1;
	private JButton b1;

	public NoOfWords() {
		setSize(600, 600);
		setLayout(null);

		l1 = new JLabel("Enter the String:");
		l1.setBounds(100, 100, 150, 50);
		add(l1);
		t1 = new JTextField();
		t1.setBounds(300, 100, 200, 50);
		add(t1);
		b1 = new JButton("Enter");
		b1.setBounds(250, 350, 75, 50);
		add(b1);
		l2 = new JLabel();
		l2.setBounds(175, 400, 300, 50);
		add(l2);
		b1.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) {
		String s = t1.getText();
		String arr[] = s.split("\\s+");
		l2.setText("There are " + arr.length + " words in the string.");
	}

	public static void main(String[] args) {
		NoOfWords w = new NoOfWords();
		w.setVisible(true);
	}
}

import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int month = input.nextInt();
		int day = input.nextInt();

		if (month >= 3)
			System.out.print("After");
		else if (month <= 1)
			System.out.print("Before");
		else if (day <= 17)
			System.out.print("Before");
		else if (day >= 19)
			System.out.print("After");
		else
			System.out.print("Special");
	}
}
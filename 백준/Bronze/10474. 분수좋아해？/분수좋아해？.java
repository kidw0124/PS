import java.util.Scanner;

public class Main {
	public static void main(String... args) {
		Scanner input = new Scanner(System.in);

		while (true) {
			int first = input.nextInt();
			int second = input.nextInt();

			if (first == 0 && second == 0)
				break;

			System.out.println((first / second) + " " + (first % second) + " / " + second);
		}
	}
}
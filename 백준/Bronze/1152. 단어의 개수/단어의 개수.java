import java.util.Scanner;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine().trim();
        if(line.isEmpty()) {
            System.out.print( 0 );
            return;
        }
        System.out.println( line.split(" ").length );
    }
}
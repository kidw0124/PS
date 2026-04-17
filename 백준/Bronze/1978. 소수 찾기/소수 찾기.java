import java.util.Scanner;
public class Main {
	static boolean isPrime(int n) {
        if( n<2 ) return false;
        for( int i=2; i<=(int)Math.sqrt(n); i++)
            if( n%i == 0) return false;
        return true;
    }
	public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int prime_count = 0;
        int n;
        for(int i=0; i<size; i++) {
            n = sc.nextInt();
            if( isPrime(n) ) prime_count++;
        }
        System.out.println( prime_count );
    }
}
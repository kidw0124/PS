import java.util.*;
public class Main {
    private static int scoring(String str) {
        int score = 0;
        int point = 0;
        for(int i=0; i<str.length(); i++) {
            if( str.charAt(i) == 'O' ) {
                point++;
            }
            else {
                point = 0;                
            }
            score += point;
        }
        return score;
    }
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for(int i=0; i<n; i++) {
            String str = sc.next();
            System.out.println(scoring(str));
        }
    }
}
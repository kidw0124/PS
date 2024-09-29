import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        final int MOD = 1_000_000_007;
        int n = Integer.parseInt(br.readLine());
        Long sum = 0L,ans=0L;
        String[] input = br.readLine().split(" ");
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i]=Integer.parseInt(input[i]);
            sum+=arr[i];
        }
        for(int i=0;i<n;i++){
            sum-=arr[i];
            ans+=arr[i]*sum % MOD;
        }
        bw.write(ans%MOD+"\n");
        bw.flush();
        bw.close();
    }
}
/*
3
1 2 3
 */
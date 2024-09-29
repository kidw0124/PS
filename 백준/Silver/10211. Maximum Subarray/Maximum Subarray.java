import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t=Integer.parseInt(br.readLine());
        for(int tc=0;tc<t;tc++) {
            int n, m;
            n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            String[] br_tmp = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(br_tmp[i]);
            }
            int ans=arr[0];
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = i; j < n; j++) {
                    sum += arr[j];
                    if (sum > ans) {
                        ans = sum;
                    }
                }
            }
            bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }
}
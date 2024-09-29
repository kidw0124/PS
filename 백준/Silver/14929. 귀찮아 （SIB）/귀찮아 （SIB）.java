import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new java.io.OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        String[] arr = br.readLine().split(" ");
        Long[] arrInt = new Long[n];
        Long sum = 0L, sqsum = 0L;
        for (int i = 0; i < n; i++) {
            arrInt[i] = Long.parseLong(arr[i]);
            sum+=arrInt[i];
            sqsum+=arrInt[i]*arrInt[i];
        }
        bw.write((sum*sum-sqsum)/2+"\n");
        bw.flush();
        bw.close();
    }
}
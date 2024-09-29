import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int ans=0;
        int n,m;
        String[] br_tmp = br.readLine().split(" ");
        n = Integer.parseInt(br_tmp[0]);
        m = Integer.parseInt(br_tmp[1]);
        int[] arr = new int[n];
        br_tmp = br.readLine().split(" ");
        for(int i=0;i<n;i++){
            arr[i] = Integer.parseInt(br_tmp[i]);
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==m){
                    ans++;
                }
            }
        }
        bw.write(ans+"\n");
        bw.flush();
        bw.close();
    }
}
/*
3
1 2 3
 */
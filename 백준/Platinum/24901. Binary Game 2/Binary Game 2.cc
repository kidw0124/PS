//; # \u000a import java.util.Scanner;
//; # \u000a public class Main{
//; # \u000a	public static void main(String[] args) {
//; # \u000a        Scanner sc = new Scanner(System.in);
//; # \u000a        int n = sc.nextInt();
//; # \u000a        String arr[]={"0","1","10","11","100","101","110","111","1000","1001","1010"};
//; # \u000a        for(int i=0;i<=n;i++){
//; # \u000a			System.out.print(arr[i]);
//; # \u000a        }
//; # \u000a    }
//; # \u000a } /*
#if true /*
n = gets.chomp.to_i
arr=["0","1","10","11","100","101","110","111","1000","1001","1010"]
for i in 0..n
	print "#{arr[i]}"
end
=begin
/* */ // \u000a /*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string arr[15]={"0",
                  "1",
                  "10",
                  "11",
                  "100",
                  "101",
                  "110",
                  "111",
                  "1000",
                  "1001",
                  "1010"
                 };
    for(int i=0;i<=n;i++){
        std::cout<<arr[i];
    }
}
// */
// */ var arr=["0","1","10","11","100","101","110","111","1000","1001","1010"] /*/**/
// */let n = Int(readLine()!)!/*/**/
// */for x in 0...n{/*/**/
// */print(arr[x],terminator:"")/*/**/
// */}
 // \u000a /*
#endif
/*
=end
# */
using System;

public class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        long l=1,r=1000000000000000000;
        while(l<r){
            long mid=(l+r)>>1;
            long now=0;
            foreach(int k in times){
                now+=mid/k;
            }
            if(now<n){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
}
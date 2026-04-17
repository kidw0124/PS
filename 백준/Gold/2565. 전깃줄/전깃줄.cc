#include<bits/stdc++.h>
using namespace std;
 
int dp[1000],M,N;
 
struct data{
    int x,y;
    bool operator<(const data&r)const{
        return x<r.x;
    }
}arr[1000];
 
 
int main(){
    scanf("%d",&N);
    int i,j;
    for(i=0;i<N;i++){
        scanf("%d %d",&arr[i].x,&arr[i].y);
    }
    sort(arr,arr+N);
    for(i=0;i<N;i++){
        dp[i]=1;
        for(j=0;j<i;j++){
            if(arr[j].y<arr[i].y&&dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
            }
        }
        if(dp[i]>M) M=dp[i];
    }
    printf("%d",N-M);
}
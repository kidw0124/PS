#include<bits/stdc++.h>
using namespace std;
 
int n,s;
 
long long price,dp[310000];
 
struct data{
    int h,c;
    bool operator<(const data&r)const{
        return h<r.h;
    }
}arr[310000];
 
int main(){
    scanf("%d %d",&n,&s);
    int i,j;
    for(i=1;i<=n;i++){
        scanf("%d %d",&arr[i].h,&arr[i].c);
    }
    sort(arr,arr+n+1);
    j=0;
    for(i=1;i<=n;i++){
        dp[i]=arr[i].c;
        while(arr[i].h-arr[++j].h>=s);
        j--;
        dp[i]+=dp[j];
        if(price<dp[i]) price=dp[i];
        if(dp[i]<dp[i-1])dp[i]=dp[i-1];
    }
    printf("%lld",price);
}
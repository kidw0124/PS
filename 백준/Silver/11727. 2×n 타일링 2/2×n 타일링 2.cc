#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[1010101];

int main(){
    ll i,j,k,l,m,n;
    scanf("%lld",&n);
    dp[1]=1;
    dp[2]=3;
    for(i=3;i<=n;i++){
        dp[i]=dp[i-1]+2*dp[i-2];
        dp[i]=dp[i]%10007;
    }
    
    printf("%lld",dp[n]);
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll b,n;
vector<ll>arr,prefix,prefix2;
double vunsan(ll a, ll b){
    return (prefix2[b+1]-prefix2[a])-(prefix[b+1]-prefix[a])*(prefix[b+1]-prefix[a])/(double)(b-a+1);
}

int main(){
    ll i,j;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>b>>n;
    arr.resize(n),prefix.resize(n+1),prefix2.resize(n+1);
    vector<vector<double>>dp(b+1,vector<double>(n+1,2000000000));
    for(i=0;i<n;i++){
        cin>>arr[i];
        prefix[i+1]=prefix[i]+arr[i];
        prefix2[i+1]=prefix2[i]+arr[i]*arr[i];
    }
    for(i=0;i<n;i++){
        dp[1][i]=vunsan(i,n-1);
    }
    for(i=2;i<=b;i++){
        for(j=0;j<n;j++){
            for(ll k=j;k<n;k++){
                dp[i][j]=min(dp[i][j],vunsan(j,k)+(k+1==n?0:dp[i-1][k+1]));
            }
        }
    }
    cout<<fixed<<setprecision(6)<<dp[b][0];
}

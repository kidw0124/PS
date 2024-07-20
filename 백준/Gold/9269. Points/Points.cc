#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod=1e9+7;

void solve(){
    ll i,j;
    ll n;
    cin>>n;
    vector<vector<ll>>arr(n,vector<ll>(3));
    vector<vector<ll>>dp(n,vector<ll>(3,INT_MIN));
    // 0 : 내가 안먹음
    // 1 : 내가 먹고 다음이 먹어야함
    // 2 : 내가 먹고 다음이 안먹어야 함
    for(i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    dp[0][0]=0;
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][0];
    for(i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][2]);
        dp[i][1]=max(dp[i-1][0]+arr[i][1],dp[i-1][1]+arr[i][2]);
        dp[i][2]=max(dp[i-1][0]+arr[i][0],dp[i-1][1]+arr[i][1]);
    }
    cout<<max(dp[n-1][0],dp[n-1][2]);
}

int main(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    solve();
}
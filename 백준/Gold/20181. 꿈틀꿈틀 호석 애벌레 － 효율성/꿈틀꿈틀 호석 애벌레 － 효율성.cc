#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()

void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

//ll n;
//vector<ll>arr;
//void func(ll rsum, ll sum, ll now, vector<vector<vector<ll>>>&a,vector<ll>b){
//    if(now==n-1){
//        for(ll i=0;i<=min(sum,arr[now]);i++){
//            b.push_back(i);
//            a[rsum+i].push_back(b);
//            b.pop_back();
//        }
//    }
//    else{
//        for(ll i=0;i<=min(sum,arr[now]);i++){
//            b.push_back(i);
//            func(rsum+i, sum-i,now+1,a,b);
//            b.pop_back();
//        }
//    }
//}

void solve(){
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n),dp(n),sum(n+1);
    for(i=0;i<n;i++){
        cin>>arr[i];
        sum[i+1]=sum[i]+arr[i];
    }
    if(arr[0]>=m)dp[0]=arr[0]-m;
    ll l=0,r=1;
    while(r<n){
        dp[r]=dp[r-1];
        while(sum[r+1]-sum[l]>=m){
            dp[r]=max((l?dp[l-1]:0)+sum[r+1]-sum[l]-m,dp[r]);
            l++;
        }
        r++;
    }
    cout<<dp[n-1];

}

int main() {
    setup();
    ll t=1;
    //cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve();
    }
    return 0;
}

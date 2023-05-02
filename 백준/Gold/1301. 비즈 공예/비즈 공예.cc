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

ll n;
vector<ll>arr;
void func(ll rsum, ll sum, ll now, vector<vector<vector<ll>>>&a,vector<ll>b){
    if(now==n-1){
        for(ll i=0;i<=min(sum,arr[now]);i++){
            b.push_back(i);
            a[rsum+i].push_back(b);
            b.pop_back();
        }
    }
    else{
        for(ll i=0;i<=min(sum,arr[now]);i++){
            b.push_back(i);
            func(rsum+i, sum-i,now+1,a,b);
            b.pop_back();
        }
    }
}


void solve(){
    ll i,j,k;
    cin>>n;
    ll ans=0,sum=0;
    arr.resize(n);
    for(i=0;i<n;i++)cin>>arr[i],sum+=arr[i];
    vector<vector<vector<ll>>>brr(sum+1);
    func(0, sum, 0, brr,vector<ll>());
//    for(i=0;i<=sum;i++){
//        for(auto k:brr[i]){
//            for(auto kk:k){
//                cout<<kk<<' ';
//            }
//            cout<<'\n';
//        }
//        cout<<'\n';
//    }
    vector<vector<ll>>crr;
    for(auto k:brr){
        for(auto kk:k){
            crr.push_back(kk);
        }
    }
    map<pair<pll,vector<ll>>,ll>dp;
    dp[{{-1,-1},brr[0][0]}]=1;
    for(i=1;i<=sum;i++){
        for(auto k:brr[i]){
            for(j=0;j<n;j++){
                vector<ll> kk = k;
                kk[j]--;
                if(kk[j]<0)continue;
                for(ll p=-1;p<n;p++) {
                    for(ll pp=-1;pp<n;pp++) {
                        if (p == j || pp == j)continue;
                        if (dp.find({{p,pp}, kk}) != dp.end())dp[{{pp,j}, k}] += dp[{{p,pp}, kk}];
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) {
            ans += dp[{{i,j}, brr[sum][0]}];
        }
    }
    cout<<ans;
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

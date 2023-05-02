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
//    ll i,j,k;
//    cin>>n;
//    ll ans=0,sum=0;
//    arr.resize(n);
//    for(i=0;i<n;i++)cin>>arr[i],sum+=arr[i];
//    vector<vector<vector<ll>>>brr(sum+1);
//    func(0, sum, 0, brr,vector<ll>());
////    for(i=0;i<=sum;i++){
////        for(auto k:brr[i]){
////            for(auto kk:k){
////                cout<<kk<<' ';
////            }
////            cout<<'\n';
////        }
////        cout<<'\n';
////    }
//    vector<vector<ll>>crr;
//    for(auto k:brr){
//        for(auto kk:k){
//            crr.push_back(kk);
//        }
//    }
//    map<pair<ll,vector<ll>>,ll>dp;
//    for(auto k:brr[1]){
//        ll x=find(all(k),1)-k.begin();
//        dp[{x,k}]=1;
//    }
//    for(i=2;i<=sum;i++){
//        for(auto k:brr[i]){
//            for(j=0;j<n;j++){
//                vector<ll> kk = k;
//                kk[j]--;
//                if(kk[j]<0)continue;
//                for(ll p=0;p<n;p++) {
//                    if(p==j)continue;
//                    if(dp.find({p,kk})!=dp.end())dp[{j,k}] += dp[{p,kk}];
//                }
//            }
//        }
//    }
//    for(i=0;i<n;i++){
//        ans+=dp[{i,brr[sum][0]}];
//    }
//    cout<<ans;
    ll i,j;
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(m+1,vector<ll>(k+1)));
    vector<pll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    ll ans=0;
    if(arr[0].first<=m&&arr[0].second<=k){
        dp[0][arr[0].first][arr[0].second]=1;
        ans=max(dp[0][arr[0].first][arr[0].second],ans);
    }
    for(i=1;i<n;i++){
        for(j=0;j<m;j++){
            for(ll l=0;l<k;l++){
                dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l]);
                if(j+arr[i].first<=m&&l+arr[i].second<=k){
                    dp[i][j+arr[i].first][l+arr[i].second]=max(dp[i-1][j][l]+1,dp[i][j+arr[i].first][l+arr[i].second]);
                    ans=max(ans,dp[i][j+arr[i].first][l+arr[i].second]);
                }
                ans=max(ans,dp[i][j][l]);
            }
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

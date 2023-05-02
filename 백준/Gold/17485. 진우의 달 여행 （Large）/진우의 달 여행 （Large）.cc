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

void solve(){
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>arr(n,vector<ll>(m));
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(m,vector<ll>(3,INT_MAX)));
    for(i=0;i<n;i++) {
        for (j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(!i){
                dp[i][j][0]=arr[i][j];
                dp[i][j][1]=arr[i][j];
                dp[i][j][2]=arr[i][j];
            }
        }
    }
    for(i=1;i<n;i++){
        for(j=0;j<m;j++){
            for(ll k=0;k<3;k++) {
                for(ll l=0;l<3;l++) {
                    if(l==k)continue;
                    if (j&&k==0) {
                        dp[i][j][k] = min(dp[i - 1][j - 1][l] + arr[i][j], dp[i][j][k]);
                    }
                    if (j != m - 1&&k==2) {
                        dp[i][j][k] = min(dp[i - 1][j + 1][l] + arr[i][j], dp[i][j][k]);
                    }
                    if(k==1)dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][l] + arr[i][j]);
                }
            }
        }
    }
    ll ans=INT_MAX;
//    for(i=0;i<n;i++){
//        for(j=0;j<m;j++){
//            cout<<*min_element(all(dp[i][j]))<<' ';
//        }
//        cout<<'\n';
//    }
    for(j=0;j<m;j++){
        for(ll k=0;k<3;k++){
            ans=min(ans,dp[n-1][j][k]);
        }
        //cout<<dp[i][j]<<' ';
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

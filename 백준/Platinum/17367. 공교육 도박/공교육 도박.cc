#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;

constexpr ll mod = 1'000'000'007;

void solve() {
    ll i,j,k;
    ll n;
    cin>>n;
    vector<vector<vector<vector<ld>>>>dp(n+1,
            vector<vector<vector<ld>>>(7,vector<vector<ld>>(7,vector<ld>(7))));
    auto calc=[](ll _a, ll _b, ll _c)->ll{
        ll a=min({_a, _b, _c}),c=max({_a,_b,_c});
        ll b=_a+_b+_c-a-c;
        if(a==c){
            return 10000+1000*c;
        }
        else if(a==b){
            return 1000+100*a;
        }
        else if(b==c){
            return 1000+100*b;
        }
        else return c*100;
    };
    function<ld(ll,ll,ll,ll)> func=[&dp,&calc,&func](ll rem, ll a, ll b, ll c)->ld{
        if(dp[rem][a][b][c])return dp[rem][a][b][c];
        if(rem==0){
            return calc(a,b,c);
        }
        else{
            ld now=calc(a,b,c);
            ld now2=0;
            for(int i=1;i<=6;i++){
                now2+=func(rem-1,b,c,i);
            }
            now2/=6;
            return dp[rem][a][b][c]=max(now,now2);
        }
    };
    ld ans=0;
    for(i=1;i<=6;i++){
        for(j=1;j<=6;j++){
            for(k=1;k<=6;k++){
                ans+=func(n-3,i,j,k);
            }
        }
    }
    cout<<fixed<<setprecision(30)<<ans/216;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
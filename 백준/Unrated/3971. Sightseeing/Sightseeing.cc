#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;
using pld = pair<ld, ld>;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

ll n,m;
vector<pair<pll,pll>>arr;
pair<ll, string> func(ll s){
    ll i,j;
    vector<vector<ll>>dp(n+1,vector<ll>(2));
    vector<vector<ll>>bef(n+1,vector<ll>(2));
    dp[0][!s]=1e12;
    for(i=0;i<n;i++){
        if(dp[i][0]+arr[i].second.first<dp[i][1]+arr[i].first.first){
            dp[i+1][0]=dp[i][0]+arr[i].second.first;
            bef[i+1][0]=0;
        }
        else{
            dp[i+1][0]=dp[i][1]+arr[i].first.first;
            bef[i+1][0]=1;
        }
        if(dp[i][0]+arr[i].second.second<dp[i][1]+arr[i].first.second){
            dp[i+1][1]=dp[i][0]+arr[i].second.second;
            bef[i+1][1]=0;
        }
        else{
            dp[i+1][1]=dp[i][1]+arr[i].first.second;
            bef[i+1][1]=1;
        }
    }
    string aaa,tmp;
    ll now=s;
    for(i=n;i>0;i--){
        tmp+=((now=bef[i][now])?'B':'F');
    }
    while(!tmp.empty()){
        aaa+=tmp.back();
        tmp.pop_back();
    }
    return {dp[n][s], aaa};
}

void solve() {
    ll i,j,k;
    ll ans=0;
    cin>>n>>m;
    arr.resize(n);
    for(i=0;i<n;i++){
        cin>>j;
        ans+=j;
        cin>>arr[i].first.first>>arr[i].first.second
            >>arr[i].second.first>>arr[i].second.second;
    }
    auto [x,sx]= func(0);
    auto [y,sy]= func(1);
    if(x<y){
        if(ans+x>m){
            cout<<"IMPOSSIBLE\n";
        }
        else cout<<sx<<'\n';
    }
    else{
        if(ans+y>m){
            cout<<"IMPOSSIBLE\n";
        }
        else cout<<sy<<'\n';
    }
}

int main(){
    setup();
    ll t=1,tc;
    cin >> t;
    for(ll tc = 0; tc < t; tc++) {
        solve();
    }
}


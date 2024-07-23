#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

constexpr ll MOD = 1e9+9;

void solve(){
    int i,j,k;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>grp(n);
    vector<ll>arr(n);
    vector<ll>dp(n);
    for(auto &x:arr)cin>>x;
    for(i=0;i<m;++i){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    vector<ll>par(n,-1);
    ll ans=0;
    auto dfs=[&](ll x, auto&&dfs)->ll{
        ll ret=0;
        for(auto y:grp[x]){
            if(par[y]==-1){
                par[y]=x;
                ret=max(ret,dfs(y,dfs));
            }
        }
        dp[x]=ret;
        if(x)arr[par[x]]-=ret;
        ans+=ret;
        return max(0ll,arr[x]-ret);
    };
    par[0]=0;
//    for(auto x:dp)cout<<x<<' ';cout<<'\n';
    cout<<ans+dfs(0,dfs)<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t st=clock();
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    int t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}
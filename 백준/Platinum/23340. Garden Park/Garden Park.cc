#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using m_os
    =tree<T, null_type,  less_equal<T>,
            rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using tlll = tuple<ll, ll, ll>;
using pld = pair<ld, ld>;
using LL = __int128;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<vector<pll>>arr(n);
    for(i=0;i<n-1;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        arr[u].push_back({v,w});
        arr[v].push_back({u,w});
    }
    vector<pll>par(n,{-1,-1});
    par[0].first=0;
    vector<vector<map<ll,ll>>>dp(n,vector<map<ll,ll>>(2));
    ll ans=0;
    function<pll(ll)>dfs=[&dp,&ans,&arr,&par,&dfs](ll x)->pll{
        ll crit=par[x].second;
        for(auto [y,w]:arr[x]){
            if(par[x].first==y) continue;
            else{
                par[y]={x,w};
                auto [inc,dec]=dfs(y);
                dp[x][0][w]+=inc;
                dp[x][1][w]+=dec;
                ans+=inc+dec;
            }
        }
        map<ll,ll>sum;
        sum[-1]=0;
        pll ret={1,1};
        for(int i=0;i<2;i++){
            for(auto [w,c]:dp[x][i]){
                if(i==0){
                    ll pp=prev(sum.end())->second;
                    sum[w]=pp+c;
                    if(crit==-1||w<crit)ret.first+=c;
                }
                else{
                    if(crit==-1||w>crit)ret.second+=c;
                }
            }
        }
        for(auto [w,c]:dp[x][1]){
            ans+=c*(prev(sum.lower_bound(w))->second);
        }
        return ret;
    };
    dfs(0);
    cout<<ans;
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
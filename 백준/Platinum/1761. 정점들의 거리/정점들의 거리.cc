#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pll = pair<ll,ll>;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<vector<pll>>grp(n+1);
    vector<vector<pll>>par(n+1,vector<pll>(21));
    vector<bool>vis(n+1);
    vector<ll>hrr(n+1);
    for(i=0;i<n-1;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        grp[x].push_back({y,z});
        grp[y].push_back({x,z});
    }
    ll tt=1;
    while(par[tt][0].first)tt=par[tt][0].first;
    function<void(ll,ll,ll)> dfs=[&](ll now, ll bef, ll d=0){
        par[now][0]= {bef,d};
        vis[now]=1;
        hrr[now]=hrr[bef]+1;
        for(int i=1;i<=20;i++){
            par[now][i]=par[par[now][i-1].first][i-1];
            par[now][i].second+=par[now][i-1].second;
        }
        for(auto [v,c]:grp[now]){
            if(!vis[v])dfs(v,now,c);
        }
    };
    dfs(tt,0,0);
    function<pll(ll,ll)>lca=[&](ll x, ll y)->pll{
        if(hrr[x]<hrr[y])swap(x,y);
        ll dh=hrr[x]-hrr[y];
        ll tmp=0;
        ll ret_d=0;
        while(dh){
            if(dh&1)ret_d+=par[x][tmp].second,x=par[x][tmp].first;
            dh>>=1;
            tmp++;
        }
        if(x==y)return {x,ret_d};
        while(par[x][0].first!=par[y][0].first){
            ll now=0;
            while(par[x][now].first!=par[y][now].first){
                ret_d+=par[x][now].second+par[y][now].second;
                x=par[x][now].first,y=par[y][now].first;
                now++;
            }
        }
        return {par[x][0].first,par[x][0].second+par[y][0].second+ret_d};
    };
    ll m;
    cin>>m;
    while(m--) {
        ll p, q;
        cin >> p >> q;
        cout << lca(p, q).second << '\n';
    }

}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ll t=1;
//    cin>>t;
    while(t--)solve();
}
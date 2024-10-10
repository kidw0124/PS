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
    vector<vector<ll>>grp(n+1);
    vector<vector<ll>>par(n+1,vector<ll>(21));
    vector<bool>vis(n+1);
    vector<ll>hrr(n+1);
    for(i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        grp[x].push_back(y);
        grp[y].push_back(x);
    }
    ll tt=1;
    while(par[tt][0])tt=par[tt][0];
    function<void(ll,ll)> dfs=[&](ll now, ll bef){
        par[now][0]=bef;
        vis[now]=1;
        hrr[now]=hrr[bef]+1;
        for(int i=1;i<=20;i++){
            par[now][i]=par[par[now][i-1]][i-1];
        }
        for(auto v:grp[now]){
            if(!vis[v])dfs(v,now);
        }
    };
    dfs(tt,0);
    function<ll(ll,ll)>lca=[&](ll x, ll y){
        if(hrr[x]<hrr[y])swap(x,y);
        ll dh=hrr[x]-hrr[y];
        ll tmp=0;
        while(dh){
            if(dh&1)x=par[x][tmp];
            dh>>=1;
            tmp++;
        }
        if(x==y)return x;
        while(par[x][0]!=par[y][0]){
            ll now=0;
            while(par[x][now]!=par[y][now]){
                x=par[x][now],y=par[y][now];
                now++;
            }
        }
        return par[x][0];
    };
    ll m;
    cin>>m;
    while(m--) {
        ll p, q;
        cin >> p >> q;
        cout << lca(p, q) << '\n';
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
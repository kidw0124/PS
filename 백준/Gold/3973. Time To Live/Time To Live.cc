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

void solve() {
    ll i,j,k;
    ll n;
    cin>>n;
    vector<vector<ll>>edges(n);
    for(i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<ll>vis(n),dep(n);
    vector<ll>par(n,-1);
    ll now=0,st;
    queue<ll>stk;
    stk.push(now);
    vis[now]=1;
    while(!stk.empty()){
        now=stk.front();
        stk.pop();
        for(auto k:edges[now]){
            if(!vis[k]){
                stk.push(k);
                vis[k]=1;
            }
        }
    }
    fill(vis.begin(), vis.end(),0);
    stk.push(now);
    dep[now]=1;
    st=now;
    vis[now]=1;
    while(!stk.empty()){
        now=stk.front();
        stk.pop();
        for(auto k:edges[now]){
            if(!vis[k]){
                stk.push(k);
                vis[k]=1;
                dep[k]=dep[now]+1;
                par[k]=now;
            }
        }
    }
    cout<<dep[now]/2<<'\n';

}

int main(){
    setup();
    ll t=1,tc;
    cin >> t;
    for(ll tc = 0; tc < t; tc++) {
        solve();
    }
}


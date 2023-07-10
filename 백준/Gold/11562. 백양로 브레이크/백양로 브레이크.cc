#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef double ld;

using ll = long long;
using pld=pair<ld,ld>;
using segment = pair<pld,pld>;

ll n,m;
vector<set<ll>>adj,radj;
vector<bool>vis;
stack<ll> stk;
set<ll>tmp;
vector<ll>grp;
vector<set<ll>>sccs;
vector<vector<ll>>roads;

void dfs(ll x){
    for(auto k:adj[x]){
        if(!vis[k]){
            vis[k]=1;
            dfs(k);
        }
    }
    stk.push(x);
}

void dfs2(ll x){
    tmp.insert(x);
    grp[x]=sccs.size();
    for(auto k:radj[x]){
        if(!vis[k]){
            vis[k]=1;
            dfs2(k);
        }
    }
}

void getscc(){
    for(ll i=0;i<n;i++) {
        if(!vis[i+1])dfs(i+1);
    }
    fill(vis.begin(),vis.end(),0);
    while(!stk.empty()){
        ll now=stk.top();
        stk.pop();
        if(!vis[now]){
            vis[now]=1;
            tmp.clear();
            dfs2(now);
            sccs.push_back(tmp);
        }
    }
}

void solve()
{
    ll i,j;
    cin>>n>>m;
    adj.resize(n+1);
    radj.resize(n+1);
    vis.resize(n+1);
    grp.resize(n+1);
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(c){
            adj[a].insert(b);
            radj[a].insert(b);
            adj[b].insert(a);
            radj[b].insert(a);
        }
        else {
            adj[a].insert(b);
            radj[b].insert(a);
        }
    }
    getscc();
//    for(auto k:sccs){
//        for(auto kk:k)cout<<kk<<' ';
//        cout<<'\n';
//    }
    ll s=sccs.size();
    roads.resize(s,vector<ll>(s,INT_MAX));
    for(i=0;i<s;i++){
        roads[i][i]=0;
    }
    for(i=1;i<=n;i++){
        for(auto k:adj[i]){
            ll ii=grp[i],kk=grp[k];
            roads[ii][kk]=min(roads[ii][kk],0ll);
            roads[kk][ii]=min(roads[kk][ii],1ll);
        }
    }
    for(i=0;i<s;i++){
        for(j=0;j<s;j++){
            for(ll k=0;k<s;k++){
                roads[i][j]=min(roads[i][j],roads[i][k]+roads[k][j]);
            }
        }
    }
    cin>>m;
    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        cout<<roads[grp[a]][grp[b]]<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
//    cin >> t;
    while(t--)solve();

    return 0;
}
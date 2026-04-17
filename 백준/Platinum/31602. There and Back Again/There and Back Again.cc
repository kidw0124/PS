#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void solve(){
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<vector<pll>>grp(n+1);
    for(i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        grp[u].push_back({v,w});
        grp[v].push_back({u,w});
    }

    vector<vector<ll>>dist(n+1,vector<ll>(2,1ll<<60));
    vector<ll>par(n+1);
    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.push({ dist[1][0]=0, 1 });
    while (pq.size()) {
        auto [d,v]=pq.top();
        pq.pop();
        if(dist[v][0]!=d&&dist[v][1]!=d)continue;
        for(auto [nv,_]:grp[v]){
            if(par[v]==nv)continue;
            ll nd=_+d;
            if(dist[nv][0]>nd){
                dist[nv][1]=dist[nv][0];
                pq.push({dist[nv][0]=nd,nv});
                par[nv]=v;
            }
            else if(dist[nv][1]>nd){
                pq.push({dist[nv][1]=nd,nv});
            }
        }
    }
    ll ans=dist[n][1];
    ll now=n;
    ll prev=n;
    while(now){
        for(auto [v,d]:grp[now]){
            if(par[now]!=v && prev!=v){
                ans=min(ans,dist[n][0]+2*d);
            }
        }
        prev=now;
        now=par[now];
    }
    ans+=dist[n][0];
    if(ans>=(1ll<<60))cout<<"-1\n";
    else cout<<ans<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
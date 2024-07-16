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
    ll n,m,s,e;
    cin>>n>>m>>s>>e;
    vector<vector<pll>>grp(n+1);
    for(i=0;i<m;++i){
        ll u,v,w;
        cin>>u>>v>>w;
        grp[u].push_back({v,w});
        grp[v].push_back({u,w});
    }
    vector<ll>dist(n+1,1e18);
    vector<ll>cnt(n+1,0);
    vector<bool>vis(n+1,false);
    dist[s]=0;
    cnt[s]=1;
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(auto [v,w]:grp[u]){
            if(dist[v]>d+w){
                dist[v]=d+w;
                cnt[v]=cnt[u];
                pq.push({dist[v],v});
            }else if(dist[v]==d+w){
                cnt[v]+=cnt[u];
                cnt[v]%=MOD;
            }
        }
    }
    cout<<cnt[e]<<'\n';
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
#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll n,m;
vector<vector<pair<ll,ll>>>edge;

ll dijk(ll st, ll en){
    vector<ll>dis(n+1,INT_MAX);
    vector<bool>vis(n+1);
    dis[st]=0;
    if(st==en)return 0;
    while(true){
        ll x=0;
        for(ll i=1;i<=n;i++){
            if(!vis[i]&&dis[x]>dis[i]){
                x=i;
            }
        }
        if(!x)break;
        vis[x]=1;
        for(auto [k,c]:edge[x]){
            dis[k]=min(dis[k],dis[x]+c);
        }
    }
    return dis[en];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll i,j,k;
    cin>>n>>m;
    edge.resize(n+1);
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    ll v,u;
    cin>>v>>u;
    cout<<min({dijk(1,v)+dijk(v,u)+dijk(u,n)+1
           ,dijk(1,u)+dijk(v,u)+dijk(v,n)+1
              ,(ll)INT_MAX})%INT_MAX-1;
}

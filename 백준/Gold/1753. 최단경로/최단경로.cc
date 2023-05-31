#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll n,m;
vector<vector<pair<ll,ll>>>edge;

void dijk(ll st){
    vector<ll>dis(n+1,INT_MAX);
    vector<bool>vis(n+1);
    dis[st]=0;
    priority_queue<pair<ll,ll>
                    ,vector<pair<ll,ll>>
                    ,greater<>>pq;
    pq.push({0,st});
    while(!pq.empty()){
        auto [d,p]=pq.top();
        pq.pop();
        if(vis[p])continue;
        else{
            vis[p]=1;
            for(auto [k,c]:edge[p]){
                dis[k]=min(dis[k],dis[p]+c);
                pq.push({dis[k],k});
            }
        }
    }
    for(ll i=1;i<=n;i++){
        if(dis[i]==INT_MAX)cout<<"INF\n";
        else cout<<dis[i]<<'\n';
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll i,j,k;
    cin>>n>>m;
    cin>>k;
    edge.resize(n+1);
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }
    dijk(k);
}

#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll n,m;

ll dfs(ll n,vector<vector<ll>>&edge,vector<bool>&vis){
    ll ret=1;
    for(auto k:edge[n]){
        if(!vis[k]){
            vis[k]=1;
            ret+=dfs(k,edge,vis);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll i,j,k;
    cin>>n>>m;
    vector<vector<ll>>edge(n+1);
    vector<bool>vis(n+1);
    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vis[1]=1;
    cout<<dfs(1,edge,vis)-1;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

struct query{
    int l,r,idx;
    int ans;
};

constexpr int MAXN=1e5+8;
constexpr int sn=333;

void solve(ll tc){
    int i,j;
    int n,m;
    cin>>n>>m;
    vector<vector<pll>>grp(n+1);
    vector<ll>dist(n+1,(ll)1e18),arr(n+1);
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        grp[u].push_back({v,w});
        grp[v].push_back({u,w});
    }
    priority_queue<pll>pq;
    dist[1]=0;
    pq.push({0,1});
    ll ans=0;
    while(!pq.empty()){
        auto [c,v]=pq.top();
        pq.pop();
        c=-c;
        if(c==dist[v]){
            ans+=c*arr[v];
            for(auto&[u,nc]:grp[v]){
                if(c+nc<dist[u]){
                    dist[u]=c+nc;
                    pq.push({-(c+nc),u});
                }
            }
        }
    }
    cout<<ans;

}

void setup(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
#endif
}
void preprocess(){
    ll i,j;
}
int main(){
    setup();
    ll t=1;
//    cin>>t;
    for(ll tc=0;tc<t;tc++){
        solve(tc+1);
    }
}

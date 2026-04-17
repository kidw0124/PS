#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

constexpr ll INF=1e18;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>arr(n),brr(n),ans(n,INF);
    vector<vector<ll>>grp(n);
    bitset<200'064>vis;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        cin>>brr[i];
    }
    priority_queue<pll>pq;
    for(i=0;i<n;i++){
        if(i-arr[i]<0||i+arr[i]>=n){
            ans[i]=brr[i];
            pq.push({-ans[i],i});
        }
        else{
            grp[i-arr[i]].push_back(i);
            grp[i+arr[i]].push_back(i);
        }
    }
    while(!pq.empty()){
        auto [cost, v]=pq.top();
        cost=-cost;
        pq.pop();
        if(vis[v])continue;
        vis[v]=1;
        for(auto u:grp[v]){
            if(vis[u])continue;
            if(cost+brr[u]>=ans[u])continue;
            else{
                ans[u]=cost+brr[u];
                pq.push({-ans[u],u});
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
}
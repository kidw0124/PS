#include <bits/stdc++.h>
#pragma gcc optimize("O3,unroll-loops")
#pragma gcc target("avx,avx2,fma")
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;

void preprocess(){

}

void solve() {
    int i,j,k;
    int n,m;
    cin>>n>>m;
    int thres = 8000;
    ll ans=0;
    vector<bool>large(n+1);
    vector<vector<int>>adj(n+1),large_adj(n+1);
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(adj[i].size()>=thres){
            large[i]=true;
            for(auto& x:adj[i]){
                large_adj[x].push_back(i);
            }
        }
        sort(adj[i].begin(),adj[i].end());
    }
    for(i=1;i<=n;i++){
        if(large[i]){
            for(auto& x:large_adj[i]){
                for(auto& y:large_adj[i]){
                    if(binary_search(adj[x].begin(),adj[x].end(),y)){
                        ans+=2;
                    }
                }
            }
        }
        else{
            for(auto& x:adj[i]){
                for(auto& y:adj[i]){
                    if(binary_search(adj[x].begin(),adj[x].end(),y)){
                        if(large[x] && large[y]){
                            ans+=12;
                        }
                        else if(large[x] || large[y]){
                            ans+=3;
                        }
                        else{
                            ans+=2;
                        }
                    }
                }
            }
        }
    }
    assert(ans%12==0);
    cout<<ans/12;


}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}

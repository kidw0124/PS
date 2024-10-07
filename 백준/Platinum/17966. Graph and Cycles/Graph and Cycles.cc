#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

void solve() {
    int i,j;
    ll n;
    cin>>n;
    vector<vector<ll>>grp(n,vector<ll>(n));
    vector<priority_queue<pll>>pq(n);
    for(i=0;i<n*(n-1)/2;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        grp[a-1][b-1]=c;
        grp[b-1][a-1]=c;
        pq[a-1].push({c,b-1});
        pq[b-1].push({c,a-1});
    }
    ll ans=0;
    for(i=0;i<n;i++){
        while(pq[i].size()){
            auto [c,v]=pq[i].top();
            pq[i].pop();
            pq[i].pop();
            ans+=c;
        }
    }
    cout<<ans<<'\n';

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
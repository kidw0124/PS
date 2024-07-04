#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

void solve() {
    ll i,j,k;
    ll n, m;
    cin>>n>>m;
    vector<pll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(), arr.end(),[](const pll&a, const pll&b){
        return pair(a.second,a.first) < pair(b.second,b.first);
    });
    ll ans=0;
    ll now=0;
    multiset<ll>pq;
    for(i=0;i<m-1;i++)pq.insert(0);
    for(i=0;i<n;i++){
        auto [s,e]=arr[i];
        if(now>=s){
            continue;
        }
        auto it=pq.upper_bound(-s);
        if(it==pq.end()){
            now=e;
            ans++;
        }
        else{
            pq.erase(it);
            pq.insert(-e);
        }
    }
    cout<<ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
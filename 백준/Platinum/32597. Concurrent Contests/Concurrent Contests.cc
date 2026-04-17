#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;

#define debug(...) __dbg(#__VA_ARGS__, __VA_ARGS__)

struct ra{
    ll p,q;
    bool operator<(const ra&r)const{
        return p*r.q<r.p*q;
    }
};

void solve() {
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<pll>arr(n);
    vector<ll>brr(m);
    for(i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    for(i=0;i<m;i++)cin>>brr[i];
    sort(arr.begin(), arr.end(),greater<>());
    vector<pair<vector<ll>,ll>>vct(m);
    for(i=0;i<n;i++){
        ra r={0,100};
        ll now=0;
        for(j=0;j<m;j++){
            ra p={brr[j],vct[j].second+arr[i].first};
            if(r<p){
                now=j;
                r=p;
            }
        }
        vct[now].second+=arr[i].first;
        vct[now].first.push_back(arr[i].second);
    }
    for(i=0;i<m;i++){
        cout<<vct[i].first.size()<<' ';
        for(auto k:vct[i].first)cout<<k<<' ';
        cout<<'\n';
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
    // cin >> tc;
    while (tc--) solve();
}
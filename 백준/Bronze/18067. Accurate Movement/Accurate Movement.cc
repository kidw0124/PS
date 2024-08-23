#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

void solve() {
    ll i,j;
    ll a,b,n;
    cin>>a>>b>>n;
    pll u={0,b},d={0,a};
    for(i=0;;i++){
        if(u.second>=n && d.second>=n) {
            cout<<i<<'\n';
            return;
        }
        if(u.first==d.first)d={u.second-a,u.second};
        else u={d.first,d.first+b};
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
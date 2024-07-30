#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    ld theta=(n-2)*acos((ld)-1)/n;
    ld r=(1-cos(theta))/2;
    cout<<setprecision(5)<<fixed<<10000/(1-r)<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("baklava.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
#endif
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
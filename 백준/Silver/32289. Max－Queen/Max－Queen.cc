#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll i,j;
    ll n,m;
    cin>>n>>m;
    cout<<((n-2)*(m-2)*8+4*3+(n*m-(n-2)*(m-2)-4)*5)/2<<'\n';
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
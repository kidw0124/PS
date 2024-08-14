 #include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll l, r, b, k; cin >> l >> r >> b >> k;
    ll c = (l + b - 1) / b * b;
    cout << c * k << '\n';
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
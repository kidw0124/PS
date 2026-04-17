#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector a(n, 0), b(n, 0), c(2, 0);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c : s) (c & 1 ? a[i] : b[i])++;
        if (a[i]) c[0] = 1;
        if (b[i]) c[1] = 1;
    }

    vector dp(4, 1 << 30); dp[0] = 0;
    for (int i = 0; i < n; i++) {
        vector ndp(4, 1 << 30);
        for (int s = 0; s < 4; s++) {
            ndp[s | 1] = min(ndp[s | 1], dp[s] + a[i]);
            ndp[s | 2] = min(ndp[s | 2], dp[s] + b[i]);
        }
        dp.swap(ndp);
    }

    if (c[0] && c[1]) cout << dp[3] << '\n';
    else cout << 0 << '\n';
}
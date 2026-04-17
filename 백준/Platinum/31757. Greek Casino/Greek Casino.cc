#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using namespace std;

void solve() {
    int n; cin >> n;
    double acc = 0;
    vector w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i], acc += w[i];

    vector divisor(n + 1, vector(0, 0));
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j += i) divisor[j].push_back(i);

    vector p(n + 1, vector(0, 0));
    for (int i = 1; i <= n; i++) {
        p[i] = vector((n + i - 1) / i + 1, 0);
        for (int d1 : divisor[i]) {
            for (int d2 : divisor[i]) {
                auto l = lcm(1LL * d1, 1LL * d2);
                if (l != i) continue;
                p[d1][i / d1] += w[d2];
            }
        }
    }

    vector dp(n + 1, 0.);
    for (int i = n; i >= 1; i--) {
        double a = 1 - p[i][1] / acc;
        double b = p[i][1] / acc;
        for (int j = 2; i * j <= n; j++) b += p[i][j] / acc * (dp[i * j] + 1);
        dp[i] = b / a;
    }
    cout << fixed << setprecision(20);
    cout << dp[1] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    fastio;
#endif
    cout<<setprecision(10)<<fixed;
    solve();
}
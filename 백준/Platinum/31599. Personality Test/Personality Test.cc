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
    int n, m, k; cin >> n >> m >> k;
    vector v(n, string{});
    for (int i = 0; i < n; i++) cin >> v[i];

    vector buc(m, vector(26, vector(0, 0)));
    for (int i = 0; i < n; i++) {
        auto check = [&](int x) -> bool { // [x, i)
            vector c(i, 0);
            for (int j = 0; j < m; j++) {
                if (v[i][j] == '.') continue;
                for (int p : buc[j][v[i][j] - 'A']) {
                    if (p < x) continue;
                    if (++c[p] == k) return 1;
                }
            }
            return 0;
        };
        if (i && check(0)) {
            int lo = 0, hi = i;
            while (lo + 1 < hi) {
                int mid = lo + hi >> 1;
                if (check(mid)) lo = mid;
                else hi = mid;
            }
            cout << lo + 1 << ' ' << i + 1 << '\n';
            return 0;
        }
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.') continue;
            buc[j][v[i][j] - 'A'].push_back(i);
        }
    }
    cout << -1 << '\n';
}
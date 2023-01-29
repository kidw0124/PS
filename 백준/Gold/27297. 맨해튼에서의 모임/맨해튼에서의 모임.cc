#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i, j;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> points(n, vector<ll>(m));
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> points[j][i];
        }
    }
    ll ans = 0;
    for (i = 0; i < n; i++) {
        sort(points[i].begin(), points[i].end());
        for (j = 0; j < m; j++) {
            assert(ans>=0);
            ans += abs(points[i][j] - points[i][m / 2]);
        }
    }
    cout << ans << '\n';
    for (i = 0; i < n; i++) {
        cout << points[i][m / 2] << ' ';
    }
    cout << '\n';
    return 0;
}
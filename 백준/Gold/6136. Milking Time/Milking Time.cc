#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

struct milk {
    int s,e,c;
};

void solve() {
    int i,j;
    int n,m,r;
    cin >> n >> m >> r;
    vector<milk> a(m);
    for (i = 0; i < m; i++) cin >> a[i].s >> a[i].e >> a[i].c, a[i].e += r;
    sort(a.begin(), a.end(), [](milk &a, milk &b) {
        return a.e < b.e;
    });
    vector<int> dp(n+r+1);
    for(i = 0; i < m; i++) {
        for(j = 0; j <= a[i].s; j++) {
            dp[a[i].e] = max(dp[a[i].e], dp[j] + a[i].c);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
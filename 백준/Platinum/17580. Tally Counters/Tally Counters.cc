#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

void preprocess(){
}

void solve(){
    ll n, m, nn, p, res = 1e18;
    ll i, j, k;
    cin >> n >> m;
    if(n == 0 && m == 0)exit(0);
    nn = (n + 1) / 2;
    vector<ll> a(n);
    vector<vector<ll>> dp(n, vector<ll>(nn, 1e18));
    for(i = 0; i < n; i++)cin >> a[i];
    for(i = 0; i < n; i++) {
        cin >> p;
        a[i] = (p + m - a[i]%m) % m;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < nn; j++) {
            if(i == 0) {
                dp[i][j] = j * m + a[i];
            }
            else {
                for(k = max(0ll, j-1); k <= min(nn-1, j+1); k++) {
                    if(k * m + a[i - 1] < j * m + a[i]) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * m + a[i] - k * m - a[i - 1]);
                    }
                    else {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                    }
                }
            }
            if(i == n - 1)res = min(res, dp[i][j]);
        }
    }

    cout << *min_element(dp[n-1].begin(), dp[n - 1].end()) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    while(true)solve();
    return 0;
}
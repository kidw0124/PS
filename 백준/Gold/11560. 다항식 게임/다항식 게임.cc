#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll k, n, i, j, l;
    vector<ll> dp(220), dp2(220);
    cin >> k >> n;
    dp[0] = 1;
    dp[1] = 1;
    for(i = 2; i <= k; i++) {
        dp2 = dp;
        fill(dp.begin(), dp.end(), 0);
        for(j = 0; j <= i; j++) {
            for(l = 0; l < 220 - j; l++) {
                dp[l + j] += dp2[l];
            }
        }
    }
    cout << dp[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--)solve();

    return 0;
}
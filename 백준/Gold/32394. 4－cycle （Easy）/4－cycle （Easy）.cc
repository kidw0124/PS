#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pll = pair<ll, ll>;

#define debug if constexpr (xdebug) cout << "[DEBUG] "

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

void solve(ll testcase){
    int i,j;
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> grp(n+1, vector<bool>(n+1));
    for(i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        grp[u][v] = grp[v][u] = true;
    }
    ll ans = 0;
    for(i = 1; i <= n; i++){
        for(j=i+1;j<=n;j++){
            ll cnt = 0;
            for(int k = 1; k <= n; k++){
                if(grp[i][k] && grp[j][k]) cnt++;
            }
            ans += cnt * (cnt-1) / 2;
        }
    }
    cout << ans/2 % (ll)(1e9+7) << '\n';




}

int main(){

#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t st = clock();
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    clock_t ed = clock();
#ifdef kidw0124
    clock_t en = clock();
    cout << "Time: " << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}

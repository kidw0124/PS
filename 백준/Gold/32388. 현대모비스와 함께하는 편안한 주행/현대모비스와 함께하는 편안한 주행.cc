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
    double a,b;
    cin >> a >> b;
    int n;
    cin >> n;
    vector<pair<double, double>> v(n);
    for(auto &[x, y] : v) cin >> x >> y;
    v.push_back({a, b});
    v.push_back({0, 0});
    vector<vector<double>>dist(n+2, vector<double>(n+2, 1e9));
    for(i = 0; i < n+2; i++){
        for(j = 0; j < n+2; j++){
            if(i == j) dist[i][j] = 0;
            else{
                dist[i][j] = sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first)
                        + (v[i].second - v[j].second) * (v[i].second - v[j].second));
                if(i<n)dist[i][j]-=1;
                if(j<n)dist[i][j]-=1;
                if(dist[i][j] < 0) dist[i][j] = 0;
            }
        }
    }
    vector<double>ans(n+2, 2e9);
    vector<bool>vis(n+2, false);
    ans[n] = 0;
    for(i = 0; i < n+1; i++){
        int mn = -1;
        for(j = 0; j < n+2; j++){
            if(vis[j]) continue;
            if(mn == -1 || ans[j] < ans[mn]) mn = j;
        }
        vis[mn] = true;
        for(j = 0; j < n+2; j++){
            ans[j] = min(ans[j], ans[mn] + dist[mn][j]);
        }
    }
    cout << fixed << setprecision(10) << ans[n+1] << '\n';






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
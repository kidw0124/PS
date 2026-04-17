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
    int n,m,r;
    cin >> n >> m >> r;
    vector<vector<int>>grp(n);
    vector<bool>broken(n);
    for(i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
    for(i=0;i<m;i++){
        int a;
        cin >> a;
        a--;
        broken[a] = true;
    }
    vector<int>vis(n);
    vector<vector<int>>dp(n,vector<int>(r+1));
    function<void(int)>dfs = [&](int now){
        vis[now] = 1;
        for(auto &x:grp[now]){
            if(vis[x]) continue;
            dfs(x);
            for(i=r;i>=0;i--){
                for(j=0;j<=i;j++){
                    dp[now][i] = max(dp[now][i],dp[now][i-j]+dp[x][j]);
                }
            }
        }
        if(broken[now]){
            for(i=r;i>0;i--){
                dp[now][i] = dp[now][i-1] + 1;
            }
            dp[now][0]=0;
        }
        else{
            for(i=0;i<=r;i++){
                dp[now][i]++;
            }
        }
    };
    dfs(0);
    cout << *max_element(dp[0].begin(),dp[0].end()) << endl;







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

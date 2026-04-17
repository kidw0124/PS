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
    cin >> n >> m;
    vector<ll> arr(m);
    for(i = 0; i < m; i++) cin >> arr[i];
    constexpr ll mod = 1e9 + 7;
    vector<ll> invfact(n + 1),inv(n + 1);
    auto modpow = [&](ll a, ll b){
        ll ans = 1;
        while(b){
            if(b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    };
    vector<ll> factorial(n + 1);
    factorial[0]=invfact[0]=inv[1] = 1;
    for(i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
        if(i > 1) inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        invfact[i] = invfact[i - 1] * inv[i] % mod;
    }
    ll ans=factorial[n];
    for(i = 0; i < m; i++){
        ans = ans * invfact[arr[i]] % mod;
    }
    ans *= modpow(2, n - m);
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << '\n';







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

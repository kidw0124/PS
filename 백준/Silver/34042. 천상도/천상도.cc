#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = long long;
using pll = pair<ll, ll>;
#define debug             \
    if constexpr (ddebug) \
    cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1e18;
ll n;
 
void solve(ll testcase)
{
    ll i, j;
    map<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    if (mp[-1])
    {
        if (n == 1)
            cout << -1;
        else if (mp[0] && !mp[1] && !mp[2] && !mp[-2])
        {
            if (mp[-1] > 1)
                cout << 1;
            else
                cout << 0;
        }
        else
            cout << (1ll << (mp[2] + mp[-2]));
    }
    else if (mp[-2])
    {
        mp[-2] &= -2;
        if (n == 1)
            cout << -2;
        else if (mp[0] && !mp[1] && !mp[2] && !mp[-2])
            cout << 0;
        else
            cout << (1ll << (mp[2] + mp[-2]));
    }
    else if (!mp[1] && !mp[2])
        cout << 0;
    else
        cout << (1ll << mp[2]);
}
 
void setup()
{
    if (ddebug)
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}
 
void preprocess()
{
    ll i, j, k;
}
 
signed main()
{
    setup();
    preprocess();
    ll t = 1;
    cin >> n >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        solve(testcase);
        cout << "\n";
    }
    return 0;
}

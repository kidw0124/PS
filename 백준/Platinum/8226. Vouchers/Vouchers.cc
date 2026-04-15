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
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= long double;
const ll mod=1e9+7;
constexpr ll MAXN=1e6;

void solve(ll testcase) {
    ll i,j;
    ll n,m;
    cin>>m;
    bitset<MAXN+1>bs,vis;
    vector<ll>now(MAXN+1,1);
    for (i=0;i<m;i++) {
        cin>>j;
        bs.set(j);
    }
    cin>>n;
    ll p=0;
    vector<ll>ans;
    for (i=0;i<n;i++) {
        ll x;
        cin>>x;
        j=now[x];
        ll t=0;
        while (t<x&&x*j<=MAXN){
            if (!vis.test(x*j)) {
                t++;
                if (bs.test(x*j)) {
                    ans.push_back(p+t);
                }
                vis.set(x*j);
            }
            j++;
        }
        p+=x;
        now[x]=j;
    }
    cout<<ans.size()<<"\n";
    for (auto&k:ans)cout<<k<<" ";

}

void setup() {
    if (ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j, k;
}

signed main() {
    setup();
    preprocess();
    ll t = 1;
    // cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}

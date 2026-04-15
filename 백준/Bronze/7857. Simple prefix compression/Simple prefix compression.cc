#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("inline")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define debug \
if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= long double;

void solve(ll testcase) {
    ll i,j;
    ll n,ans=0;
    cin>>n;
    ans=n-1;
    string str;
    for (i=0;i<n;i++) {
        string nstr;
        cin>>nstr;
        for (j=0;j<min(str.size(),nstr.size());j++) {
            if (str[j]!=nstr[j]) break;
        }
        ans+=nstr.size()-j;
        str=nstr;
    }
    cout<<ans<<"\n";
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
    //    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}
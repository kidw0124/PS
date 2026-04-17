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

void solve(ll testcase) {
    ll i, j;
    ll n;
    cin>>n;
    cout<<fixed<<setprecision(10)<<sqrt(n)*4;
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

void preprocess() { ll i, j, k; }

signed main() {
  setup();
  preprocess();
  ll t = 1;
//  cin >> t;
  for (ll testcase = 1; testcase <= t; testcase++) {
    solve(testcase);
    cout << "\n";
  }
  return 0;
}

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
    cin>>n>>m;
    vector<ll>arr(n+1),brr(n+1),pfx(n+1);
    for (i=1;i<=n;i++) {
        cin>>arr[i];
        pfx[i]=pfx[i-1]+arr[i];
    }
    for (i=1;i<=n;i++) {
        cin>>brr[i];
    }
    auto sum=[&](ll l,ll r) {
        l=max(l,1ll);
        r=min(r,n);
        if (l>r) return 0ll;
        return pfx[r]-pfx[l-1];
    };
    ll ans=0;
    multiset<ll>st;
    st.insert(0);
    vector<ll>dp(n+1,-1e18);
    dp[0]=0;
    for (i=1;i<=n;i++) {
        ll tmp=*st.rbegin();
        dp[i]=max(dp[i],tmp+pfx[i-1]-arr[i]);
        if (i>=m) {
            dp[i]=max(dp[i],dp[i-m]+sum(i-m+1,i)+brr[i]);
            st.erase(st.find(dp[i-m]-pfx[i-m]));
        }
        st.insert(dp[i]-pfx[i]);
    }
    ans=dp[n];
    for (i=1;i<=min(n,m);i++) {
        ans=max(ans,dp[n-i]+sum(n-i+1,n));
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
    // cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}

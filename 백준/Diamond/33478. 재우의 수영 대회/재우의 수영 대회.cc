#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "
void solve(ll testcase){
    ll a,b,c;
    cin >> a >> b >> c;
    ld p=(ld)(a+b+c)/2;
    ld pa=(ld)(-a+b+c)/2,pb=(ld)(a-b+c)/2,pc=(ld)(a+b-c)/2;
    ld ans=sqrt(pa*pb*pc/(4*p));
    cout << fixed << setprecision(20) << ans <<'\n';
}

void setup() {
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
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
    cin >> t;
#ifdef kidw0124
    clock_t st = clock();
#endif
    for (ll testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
#ifdef kidw0124
    cout << "\n\nTime: " << (clock() - st) * 1.0 / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}

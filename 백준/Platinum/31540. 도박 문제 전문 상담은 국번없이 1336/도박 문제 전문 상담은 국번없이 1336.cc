#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

const ll mod = 1e9+7;

void setup()
{
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

ll modinverse(ll a, ll m){
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

void preprocess() {
    ll i, j;

}

void solve(ll testcase){
    ll i,j,k;
    ll n,m,t,s=0;
    cin >> n >> m >> t;
    vector<ll>a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
        s+=a[i];
    }
    cout<<fixed<<setprecision(100);
    if(m==1){
        ll ma=*max_element(all(a));
        cout<<s-ma*ma*t/(ld)s;
        return;
    }
    ld p=m/(ld)(m-1);
    ld sump = 0;
    for(i=0;i<n;i++){
        debug << i<<'\n';
        sump += pow(a[i],2*p);
    }
    debug<< sump << '\n';
    sump = pow(sump,1/p);
    debug<< sump << '\n';
    cout<<s-sump*pow(t,1/(ld)m)/(ld)s;

}

int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        solve(testcase);
    }
    return 0;
}

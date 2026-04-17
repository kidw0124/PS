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
vector<ull>a({0,4}),b({0,4});

void preprocess() {
    ll i, j;
    for(i=2;a[i-1]<=(ull)1e18;i++){
        a.push_back(2*a[i-1]+4*b[i-1]);
        b.push_back(2+2*b[i-1]);
    }

}

void solve(ll testcase){
    ll i,j,k;
    ll n;
    cin>>n;
    ll idx=0;
    while(a[idx+1]<=n)idx++;
    if(a[idx]+b[idx]>n){
        cout<<"eoaud0108\n";
    }
    else{
        cout<<"kidw0124\n";
    }

}

int main()
{
    setup();
    preprocess();
    ll t = 1;
    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        solve(testcase);
    }
    return 0;
}

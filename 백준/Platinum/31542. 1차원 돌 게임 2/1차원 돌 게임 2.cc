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
vector<ull>ans;

void preprocess() {
    ll i, j;
    for(i=1;i<32;i++){
        if((1ull<<(i<<1))>(ull)3e18)break;
        ans.push_back(((1ull<<(i<<1))-1)*8/3);
        if(i>=2)ans.push_back(((1ull<<(i<<1))-10)/3);
        if(i>=2)ans.push_back(((1ull<<(i<<1))-7)/3);
    }

}

void solve(ll testcase){
    ll i,j,k;
    ll n;
    cin>>n;
    if(find(all(ans),n)==ans.end()){
        cout<<"kidw0124\n";
    }
    else{
        cout<<"eoaud0108\n";
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

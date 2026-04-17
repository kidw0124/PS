#include<bits/stdc++.h>

using namespace std;

using ll = long long;

using pll = pair<ll,ll>;

using ld = long double;

using pld = pair<ld,ld>;

typedef unsigned long long ull;

typedef __float128 LD;

//typedef __int128_t LL;

//typedef __uint128_t ULL;

typedef pair<int, int> pii;

typedef vector<int> vi;

typedef pair<ll, ll> pll;

typedef vector<ll> vl;

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;

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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b)

{

    if (a && b)

        return a * (b / gcd(a, b));

    return a + b;

}

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

const ll MAXN = 1e6+5;

vector<vector<ll>> ans(MAXN, vector<ll>(8, 0));

void preprocess() {

    ll i, j;

    for(i=0;i<8;i++) {

        ans[0][i] = 1;

        ans[1][i] = 1;

    }

    for(i=2;i<MAXN;i++) {

        for(j=0;j<8;j++){

            if(j>>0&1) {

                ans[i][j] += ans[i-2][j]*ans[i-1][j] % mod;

                ans[i][j]%=mod;

            }

            if(j>>1&1) {

                ans[i][j] += ans[i-1][j]*ans[i-1][j] % mod;

                ans[i][j]%=mod;

            }

            if(j>>2&1) {

                ans[i][j] += ans[i-1][j]*ans[i-2][j] % mod;

                ans[i][j]%=mod;

            }

        }

    }

}

void solve(ll testcase){

    ll i,j,k;

    ll h, n;

    cin>>h>>n;

    bitset<3>bs;

    for(i=0;i<n;i++){

        cin>>j;

        bs[j+1]=1;

    }

    cout<<ans[h][bs.to_ulong()]<<'\n';

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
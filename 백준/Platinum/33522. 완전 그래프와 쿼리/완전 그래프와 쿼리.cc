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
#include <ext/rope>
using namespace __gnu_cxx;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

constexpr ll MOD = 1e9+7;

ll modmul(ll a, ll b, ll mod = MOD) {
    return (a * b) % mod;
}

void solve(ll testcase){
    ll i, j,k;
    ll n;
    cin >> n;
    vector<int>primes,is_prime(n+1);
    primes.reserve(n);
    for(i=2;i<=n;i++){
        if(!is_prime[i]){
            primes.push_back(i);
            for(j=i*i;j<=n;j+=i){
                is_prime[j] = 1;
            }
        }
    }
    cout<<(n+1)/2+n-primes.size()-1<<'\n';
    for(i=1;i<=n;i+=2){
        cout << "1 " << i << '\n';
    }
    for(i=1;i<=n;i++){
        if(is_prime[i]){
            cout << "2 "<<i << '\n';
        }
    }

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
//    cin >> t;
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

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

ll x,y,z,mod=1000000007;
vector<int>a,w;
int add(int x, int y) { return (x+y) % mod; }
int mul(int x, ll y) { return (x*y) % mod; }

ll kitamasa(ll n) {
    vector<int> c(z+1, 0); c[1] = 1;

    // n = 1 만들기
    int b = 62;
    while ((n>>b)%2==0) b--;

    for (b--; ~b; b--) {
        // c(n) -> c(2n)
        vector<int> d(2*z+1, 0);
        for (int i=1; i<=z; i++) for (int j=1; j<=z; j++) d[i+j] = (d[i+j]+ (c[i]*(ll) c[j]))%mod;
        for (int i=2*z; i>z; i--) for (int j=1; j<=z; j++) d[i-j] = (d[i-j]+(d[i]*(ll) w[j]))%mod;
        d.resize(z+1);
        c = d;
        // c(n) -> c(n+1)
        if ((n>>b)&1) {
            vector<int> d(z+1, 0);
            d[1] = mul(c[z], w[z]);
            for (int i=2; i<=z; i++) d[i] = (c[i-1] + (c[z]* (ll)w[z+1-i]))%mod;
            c = d;
        }
    }

    ll ans = 0;
    for (int i=1; i<=z; i++) ans += (a[i]* (ll)c[i]),ans%=mod;
    return ans;
}

int main() {
    setup();
    ll i,j,n;
    cin>>n>>x>>y>>z;
    x%=mod;y%=mod;
    a.resize(z+1),w.resize(z+1);
    for(i=1;i<=z;i++){
        a[i]= powm(x,i,mod);
    }
    a[z]=add(a[z],mod-y);
    for(i=1;i<z;i++){
        w[i]=x-1;
    }
    w[z]=x-y;
    cout<<kitamasa(n);
}
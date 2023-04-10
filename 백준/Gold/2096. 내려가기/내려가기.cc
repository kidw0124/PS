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
typedef long double ld;
typedef __float128 LD;
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
pair<ll, ll> extended_gcd(ll a, ll b) {
    if (b == 0) return { 1, 0 };
    auto t = extended_gcd(b, a % b);
    return { t.second, t.first - t.second * (a / b) };
}
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first % m + m) % m;
}
ll large_mod_mul(ll a, ll b, ll m) {
    return ll((__int128)a*(__int128)b%m);
}
ll modpow(ll n, ll k, ll m) {
    ll ret = 1;
    n %= m;
    while (k) {
        if (k & 1) ret = large_mod_mul(ret, n, m);
        n = large_mod_mul(n, n, m);
        k /= 2;
    }
    return ret;
}
bool test_witness(ull a, ull n, ull s) {
    if (a >= n) a %= n;
    if (a <= 1) return true;
    ull d = n >> s;
    ull x = modpow(a, d, n);
    if (x == 1 || x == n-1) return true;
    while (s-- > 1) {
        x = large_mod_mul(x, x, n);
        if (x == 1) return false;
        if (x == n-1) return true;
    }
    return false;
}
bool is_prime(ull n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    ull d = n >> 1, s = 1;
    for(; (d&1) == 0; s++) d >>= 1;
#define T(a) test_witness(a##ull, n, s)
    if (n < 4759123141ull) return T(2) && T(7) && T(61);
    return T(2) && T(325) && T(9375) && T(28178)
           && T(450775) && T(9780504) && T(1795265022);
#undef T
}
ll pollard_rho(ll n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution <ll> dis(1, n - 1);
    ll x = dis(gen);
    ll y = x;
    ll c = dis(gen);
    ll g = 1;
    while (g == 1) {
        x = (large_mod_mul(x, x, n) + c) % n;
        y = (large_mod_mul(y, y, n) + c) % n;
        y = (large_mod_mul(y, y, n) + c) % n;
        g = gcd(abs(x - y), n);
    }
    return g;
}
void factorize(ll n, map<ll,ll>& fl) {
    if (n == 1) {
        return;
    }
    if (n % 2 == 0) {
        fl[2]++;
        factorize(n / 2, fl);
    }
    else if (is_prime(n)) {
        fl[n]++;
    }
    else {
        ll f = pollard_rho(n);
        factorize(f, fl);
        factorize(n / f, fl);
    }
}

const ll mod=1e8+7;
const LD eps=1e-12;

vector<vector<ll>>operator*(vector<vector<ll>>&a,vector<vector<ll>>&b){
    vector<vector<ll>>ret(a.size(),vector<ll>(b[0].size()));
    for(ll i=0;i<a.size();i++){
        for(ll j=0;j<b[0].size();j++){
            for(ll k=0;k<a[0].size();k++){
                ret[i][j]+=a[i][k]*b[k][j];
                ret[i][j]%=mod;
            }
        }
    }
    return ret;
}

vector<vector<ll>>operator^(vector<vector<ll>>&a,ll n){
    if(n==0){
        vector<vector<ll>>ret(a.size(),vector<ll>(a.size()));
        for(ll i=0;i<a.size();i++){
            ret[i][i]=1;
        }
        return ret;
    }
    if(n==1){
        return a;
    }
    else{
        auto p=a^(n>>1);
        p=p*p;
        if(n&1)p=p*a;
        return p;
    }
}

const ll INF = INT_MAX;

void solve() {
    ll i, j;
    ll n;
    cin>>n;
    vector<vector<ll>>arr(2,vector<ll>(3));
    vector<vector<pll>>dp(2,vector<pll>(3));
    cin>>dp[0][0].first>>dp[0][1].first>>dp[0][2].first;
    dp[0][0].second=dp[0][0].first;
    dp[0][1].second=dp[0][1].first;
    dp[0][2].second=dp[0][2].first;
    for(i=1;i<n;i++){
        for(j=0;j<3;j++){
            cin>>arr[i%2][j];
        }
        dp[i%2][0].first=arr[i%2][0]+min(dp[(i-1)%2][0].first,dp[(i-1)%2][1].first);
        dp[i%2][1].first=arr[i%2][1]+min({dp[(i - 1)%2][0].first, dp[(i - 1)%2][1].first,dp[(i-1)%2][2].first});
        dp[i%2][2].first=arr[i%2][2]+min(dp[(i-1)%2][1].first,dp[(i-1)%2][2].first);
        dp[i%2][0].second=arr[i%2][0]+max(dp[(i-1)%2][0].second,dp[(i-1)%2][1].second);
        dp[i%2][1].second=arr[i%2][1]+max({dp[(i - 1)%2][0].second, dp[(i - 1)%2][1].second,dp[(i-1)%2][2].second});
        dp[i%2][2].second=arr[i%2][2]+max(dp[(i-1)%2][1].second,dp[(i-1)%2][2].second);
    }
    cout<<max({dp[(n-1)%2][0].second,dp[(n-1)%2][1].second,dp[(n-1)%2][2].second})
        <<' '<<min({dp[(n-1)%2][0].first,dp[(n-1)%2][1].first,dp[(n-1)%2][2].first});
}

int main() {
    setup();
    ll t=1;
//    cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve();
    }
    return 0;
}

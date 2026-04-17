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
 
constexpr ll mod=1e9+7;
ll modinverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}
ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
template <ll mod=mod>
struct mint{
    ll x;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
    mint inv() const {
        return modinverse(x, mod);
    }
    friend ostream& operator<<(ostream& os, const mint& a) {
        return os << a.x;
    }
    friend istream& operator>>(istream& is, mint& a) {
        ll t;
        is >> t;
        a = mint<mod>(t);
        return is;
    }
    explicit operator ll() const { return x; }
    explicit operator int() const { return x; }
    explicit operator bool() const { return x; }
    explicit operator double() const { return x; }
    explicit operator string() const { return to_string(x); }
};
 
void solve(ll testcase) {
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<ll>cnts(n+1);
    vector<ll>pivot;
    auto ask=[](const vector<ll>&v){
        cout<<"? ";
        for(const auto&x:v){
            cout<<x<<" ";
        }
        cout<<endl<<flush;
        ll res;
        cin>>res;
        return res;
    };
    auto get_value=[&pivot,&ask,&cnts](auto&&self, ll block, ll rem)->ll{
        ll q=block/rem;
        ll r=block%rem;
        if(r){
            for(ll i=0;i<r;i++)pivot.push_back(block-i);
            ll ret=self(self,rem,rem-r);
            for(ll i=0;i<r;i++)pivot.pop_back();
            for(ll i=0;i<q;i++){
                for(ll j=0;j<rem;j++){
                    pivot.push_back(i*rem+j+1);
                }
                ll cnt=cnts[block]-cnts[i*rem+1];
                ret+=cnt*ask(pivot);
                for(auto&x:pivot)cnts[x]+=cnt;
                for(ll j=0;j<rem;j++)pivot.pop_back();
            }
            return ret;
        }
        else{
            ll ret=0;
            for(ll i=0;i<q;i++){
                for(ll j=0;j<rem;j++){
                    pivot.push_back(i*rem+j+1);
                }
                ret+=ask(pivot);
                for(auto&x:pivot)cnts[x]++;
                for(ll j=0;j<rem;j++)pivot.pop_back();
            }
            return ret;
        }
    };
    ll sum=get_value(get_value, n, m);
    cout<<"! "<<sum/cnts[1]<<endl<<flush;
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
//    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}

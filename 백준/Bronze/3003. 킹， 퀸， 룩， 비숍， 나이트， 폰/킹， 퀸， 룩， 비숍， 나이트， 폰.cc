#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
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
ll powm(ll a, ll b, ll rem)
{
    ll p = 1;
    for (; b; b /= 2, a = (a * a) % rem)
        if (b & 1)
            p = (p * a) % rem;
    return p;
}
pair<ll, ll> extended_gcd(ll a, ll b)
{
    if (b == 0)
        return {1, 0};
    auto t = extended_gcd(b, a % b);
    return {t.second, t.first - t.second * (a / b)};
}
ll modinverse(ll a, ll m)
{
    return (extended_gcd(a, m).first % m + m) % m;
}

LD eps = 1e-12;
ll large_mod_mul(ll a, ll b, ll m)
{
    return ll((__int128)a * (__int128)b % m);
}
ll modpow(ll n, ll k, ll m)
{
    ll ret = 1;
    n %= m;
    while (k)
    {
        if (k & 1)
            ret = large_mod_mul(ret, n, m);
        n = large_mod_mul(n, n, m);
        k /= 2;
    }
    return ret;
}
bool test_witness(ull a, ull n, ull s)
{
    if (a >= n)
        a %= n;
    if (a <= 1)
        return true;
    ull d = n >> s;
    ull x = modpow(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (s-- > 1)
    {
        x = large_mod_mul(x, x, n);
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}
bool is_prime(ull n)
{
    if (n == 2)
        return true;
    if (n < 2 || n % 2 == 0)
        return false;
    ull d = n >> 1, s = 1;
    for (; (d & 1) == 0; s++)
        d >>= 1;
#define T(a) test_witness(a##ull, n, s)
    if (n < 4759123141ull)
        return T(2) && T(7) && T(61);
    return T(2) && T(325) && T(9375) && T(28178) && T(450775) && T(9780504) && T(1795265022);
#undef T
}
ll pollard_rho(ll n)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ll> dis(1, n - 1);
    ll x = dis(gen);
    ll y = x;
    ll c = dis(gen);
    ll g = 1;
    while (g == 1)
    {
        x = (large_mod_mul(x, x, n) + c) % n;
        y = (large_mod_mul(y, y, n) + c) % n;
        y = (large_mod_mul(y, y, n) + c) % n;
        g = gcd(abs(x - y), n);
    }
    return g;
}
void factorize(ll n, map<ll, ll> &fl)
{
    if (n == 1)
    {
        return;
    }
    if (n % 2 == 0)
    {
        fl[2]++;
        factorize(n / 2, fl);
    }
    else if (is_prime(n))
    {
        fl[n]++;
    }
    else
    {
        ll f = pollard_rho(n);
        factorize(f, fl);
        factorize(n / f, fl);
    }
}

const ll mod = 998244353;

//#ifdef ATCODER
//#include <atcoder/all>
//using namespace atcoder;
//#endif

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
    explicit operator LD() const { return x; }
    explicit operator LL() const { return x; }
    explicit operator ULL() const { return x; }
    explicit operator string() const { return to_string(x); }
};

void yes() {
    cout << "Yes\n";
}
void no() {
    cout << "No\n";
}

struct student{
    ll age;
    string name;
    void input(istream &is){
        is>>age>>name;
    }
    void output(ostream &os)const{
        os<<age<<' '<<name;
    }
    friend istream& operator>>(istream &is, student &r);
    friend ostream& operator<<(ostream &os, const student &r);
    bool operator<(const student& r)const {
        return age<r.age;
    }
};

istream& operator>>(istream &is, student &r){
    r.input(is);
    return is;
}

ostream &operator<<(ostream &os, const student &r){
    r.output(os);
    return os;
}

void solve(ll testcase){
    ll i, j;
    array<ll,6>arr,brr({1,1,2,2,2,8});
    for(i=0;i<6;i++){
        cin>>arr[i];
        cout<<brr[i]-arr[i]<<' ';
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

int main() {
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
    return 0;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma warning(disable : 4996)
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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)
#define endl '\n'

#define debug             \
    if constexpr (xdebug) \
    cout << "[DEBUG] "
#define debugv(x)         \
    if constexpr (xdebug) \
        cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c)                         \
    if constexpr (xdebug)                 \
    {                                     \
        cout << "[DEBUG] " << #c << ": "; \
        for (const auto &elem : c)        \
            cout << elem << ", ";         \
        cout << '\n';                     \
    }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
void setup()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
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

#ifdef ONLINE_JUDGE
const int TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const int TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

#ifdef ONLINE_JUDGE
const ll MAXN = 1e5 + 6e4;
#else
const ll MAXN = 1e5 + 6e4;
#endif
struct segment
{
    vector<ll> segtree, prop, dat;
    segment(int n)
    {
        segtree.resize(TSIZE * 2);
        prop.resize(TSIZE * 2);
        dat.resize(n);
    }
    void seg_init(int nod, int l, int r)
    {
        if (l == r)
            segtree[nod] = dat[l];
        else
        {
            int m = (l + r) >> 1;
            seg_init(nod << 1, l, m);
            seg_init(nod << 1 | 1, m + 1, r);
            segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
        }
    }

    void seg_relax(int nod, int l, int r)
    {
        if (prop[nod] == 0)
            return;
        if (l < r)
        {
            int m = (l + r) >> 1;
            segtree[nod << 1] += (m - l + 1) * prop[nod];
            prop[nod << 1] += prop[nod];
            segtree[nod << 1 | 1] += (r - m) * prop[nod];
            prop[nod << 1 | 1] += prop[nod];
        }
        prop[nod] = 0;
    }

    ll seg_query(int nod, int l, int r, int s, int e)
    {
        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e)
            return segtree[nod];
        seg_relax(nod, l, r);
        int m = (l + r) >> 1;
        return seg_query(nod << 1, l, m, s, e) + seg_query(nod << 1 | 1, m + 1, r, s, e);
    }

    void seg_update(int nod, int l, int r, int s, int e, int val)
    {
        if (r < s || e < l)
            return;
        if (s <= l && r <= e)
        {
            segtree[nod] += (r - l + 1) * val;
            prop[nod] += val;
            return;
        }
        seg_relax(nod, l, r);
        int m = (l + r) >> 1;
        seg_update(nod << 1, l, m, s, e, val);
        seg_update(nod << 1 | 1, m + 1, r, s, e, val);
        segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
    }
    // usage:
    // seg_update(1, 0, n ‐ 1, qs, qe, val);
    // seg_query(1, 0, n ‐ 1, qs, qe);
};

struct polynomial
{
    vector<int> coef;
    int MAXC;
    polynomial(){}
    polynomial(int c){
        MAXC=c;
        coef.resize(c);
    }
    void print()
    {
        // print polynomial in descending order of power
        vector<int> pows;
        for(int i=0;i<MAXC;i++){
            if(coef[i])pows.push_back(i);
        }
        sort(pows.begin(), pows.end(), greater<>());
        cout << '(';
        if (pows[0] == 1)
        {
            if (coef[1] == 1)
                cout << 'x';
            else if (coef[1] == -1)
                cout << "-x";
            else
                cout << coef[1] << "x";
        }
        else
        {
            if (coef[pows[0]] == 1)
                cout << "x^" << pows[0];
            else if (coef[pows[0]] == -1)
                cout << "-x^" << pows[0];
            else
                cout << coef[pows[0]] << "x^" << pows[0];
        }
        for (int i = 1; i < pows.size(); i++)
        {
            if (pows[i] == 0)
            {
                if (coef[0] > 0)
                    cout << '+' << coef[0];
                else if (coef[0] < 0)
                    cout << coef[0];
            }
            else if (pows[i] == 1)
            {
                if (coef[1] == 1)
                    cout << "+x";
                else if (coef[1] == -1)
                    cout << "-x";
                else if (coef[1] > 0)
                    cout << '+' << coef[1] << "x";
                else
                    cout << coef[1] << "x";
            }
            else
            {
                if (coef[pows[i]] == 1)
                    cout << "+x^" << pows[i];
                else if (coef[pows[i]] == -1)
                    cout << "-x^" << pows[i];
                else if (coef[pows[i]] > 0)
                    cout << '+' << coef[pows[i]] << "x^" << pows[i];
                else
                    cout << coef[pows[i]] << "x^" << pows[i];
            }
        }
        cout << ')';
    }

    void operator*=(const int &n)
    {
        coef.resize(MAXC+n);
        for(int i=MAXC-1;i>=0;i--){
            coef[i+n]+=coef[i];
            coef[i]=-coef[i];
        }
        MAXC=MAXC+n;
    }
    void operator/=(const int &n)
    {
        vector<int>coefs(MAXC);
        for(int i=MAXC-1; i>=n; i--){
            int x=i-n;
            int y=coef[i];
            coefs[x]+=y;
            coef[x]+=y;
            coef[i]=coefs[i];
        }
        for(int i=n-1;i>=0;i--)coef[i]=coefs[i];
        coef.resize(MAXC-n);
        MAXC=MAXC-n;
    }
    bool operator<(polynomial &p)
    {
        // compare polynomials in descending order of power
        if(MAXC!=p.MAXC)return MAXC < p.MAXC;
        for(int i=MAXC-1;i>=0;i--){
            if(coef[i]!=p.coef[i]){
                return coef[i]<p.coef[i];
            }
        }
        return true;
    }
};

vector<ll> mobius(MAXN, 1);
vector<ll> primes;
vector<bool> isprime(MAXN, true);
vector<ll> spf(MAXN, 0);
vector<vector<ll>> divisors(MAXN);
void preprocess()
{
    ll i, j;
    // get all mobius function with linear sieve
    mobius[1] = 1;
    for (i = 2; i < MAXN; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            mobius[i] = -1;
            spf[i] = i;
        }
        for (j = 0; j < primes.size() && i * primes[j] < MAXN && primes[j] <= spf[i]; j++)
        {
            isprime[i * primes[j]] = false;
            spf[i * primes[j]] = primes[j];
            if (spf[i] == primes[j])
                mobius[i * primes[j]] = 0;
            else
                mobius[i * primes[j]] = -mobius[i];
        }
    }
    // get all divisors
    for (i = 1; i < MAXN; i++)
    {
        for (j = i; j < MAXN; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

map<int,polynomial>cp;

polynomial cyclotomic(ll n)
{
    if(cp.find(n)!=cp.end())return cp[n];
    polynomial cyclo(2);
    vector<int> mul, div;
    cyclo.coef[0] = 1;
    cyclo.MAXC=1;
    for (auto i : divisors[n])
    {
        if (mobius[n/i] == 0)
        {
            continue;
        }
        else if (mobius[n/i] == 1)
        {
            mul.push_back(i);
        }
        else
        {
            div.push_back(i);
        }
    }
    for (auto i : mul)
    {
        cyclo *= i;
    }
    for (auto i : div)
    {
        cyclo /= i;
    }
    return cp[n]=cyclo;
}

void solve(ll testcase)
{
    ll i, j, k;
    ll n, m, c = 0, q;
    cin >> n;
    vector<polynomial> polys;
    for (auto i : divisors[n])
    {
        polys.push_back(cyclotomic(i));
    }
    sort(polys.begin(), polys.end());
    for (auto i : polys)
    {
        i.print();
    }
    cout << '\n';
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

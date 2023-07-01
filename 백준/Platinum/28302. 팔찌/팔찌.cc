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
const ll MAXN = 20;
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

map<char,ll>mp;
void preprocess() {
    ll i, j;
    mp['R']=1;
    mp['G']=2;
    mp['B']=3;
}

struct doing{
    ll idx;
    string prev;
    string now;
};
struct query{
    ll q;
    ll a,b;
    char x,y;
};

void make_one(string str,vector<doing>&vct){
    debugv(str);
    if(str.size()==1){
        return;
    }
    else if(str.size()==2){
        if(str=="RR"){
            return;
        }
        else if(str=="RB"||str=="BR"){
            vct.push_back({0,str,"G"});
            return;
        }
        else if(str=="BG"||str=="GB"){
            vct.push_back({0,str,"R"});
            return;
        }
        else if(str=="RG"||str=="GR"){
            vct.push_back({0,str,"B"});
            return;
        }
        else if(str=="BB"){
            vct.push_back({0,"B","RG"});
            vct.push_back({1,"GB","R"});
            return;
        }
        else{
            vct.push_back({0,"G","RB"});
            vct.push_back({1,"BG","R"});
            return;
        }
    }
    else{
        ll n=str.size();
        if(str[n-1]==str[n-2]&&str[n-2]==str[n-3]){
            string nex;
            switch (str[n-1]) {
                case 'R':
                    vct.push_back({n-2,"R",nex="BG"});
                    break;
                case 'B':
                    vct.push_back({n-2,"B",nex="GR"});
                    break;
                case 'G':
                    vct.push_back({n-2,"G",nex="RB"});
                    break;
            }
            char t=str[n-1];
            str.pop_back();
            str.pop_back();
            str+=nex;
            str+=t;
        }
        else{
            ll i;
            string prev;
            string nex;
            for(i=n-2;i>=0;i--){
                if(str[i]!=str[i+1]){
                    prev=str.substr(i,2);
                    break;
                }
            }
            if(prev=="RG"||prev=="GR")nex="B";
            else if(prev=="GB"||prev=="BG")nex="R";
            else if(prev=="RB"||prev=="BR")nex="G";
            vct.push_back({i,prev,nex});
            str=str.substr(0,i)+nex+str.substr(i+2);
        }
        make_one(str,vct);
    }
}

void doing_to_query(const vector<doing>&vct,vector<query>&que){
    for(auto k:vct){
        query tmp;
        if(k.now.size()>k.prev.size()){
            tmp.q=2;
            tmp.a=k.idx+1;
            tmp.x=k.now[0];
            tmp.y=k.now[1];
        }
        else{
            tmp.q=1;
            tmp.a=k.idx+1;
            tmp.b=k.idx+2;
        }
        que.push_back(tmp);
    }
}

void solve(ll testcase)
{
    ll i, j, k;
    ll n, m;
    string str1,str2;
    cin>>n>>str1;
    cin>>m>>str2;
    ll a=0,b=0;
    for(i=0;i<n;i++){
        a^=mp[str1[i]];
    }
    for(i=0;i<m;i++){
        b^=mp[str2[i]];
    }
    if(a!=b){
        cout<<-1;
        return;
    }
    vector<doing>vct,vct2;
    make_one(str1,vct);
    make_one(str2,vct2);
    reverse(all(vct2));
    for(auto&k:vct2){
        swap(k.now,k.prev);
    }
    vector<query>ans;
    doing_to_query(vct,ans);
    doing_to_query(vct2,ans);
    cout<<ans.size()<<'\n';
    for(auto k:ans){
        if(k.q==1){
            cout<<k.q<<' '<<k.a<<' '<<k.b<<'\n';
        }
        else{
            cout<<k.q<<' '<<k.a<<' '<<k.x<<' '<<k.y<<'\n';
        }
    }
}

int main()
{
    setup();
    preprocess();
    ll t = 1;
    //cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        solve(testcase);
    }
    return 0;
}

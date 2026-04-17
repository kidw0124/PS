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
#define endl '\n'
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

#ifndef kidw0124
const ll TSIZE = 1 << 17; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

struct segment{
    vector<ll> segtree, prop, dat;
    segment(ll n)
    {
        segtree.resize(TSIZE * 2);
        prop.resize(TSIZE * 2);
        dat.resize(n);
    }
    void seg_init(ll nod, ll l, ll r)
    {
        if (l == r)
            segtree[nod] = dat[l];
        else
        {
            ll m = (l + r) >> 1;
            seg_init(nod << 1, l, m);
            seg_init(nod << 1 | 1, m + 1, r);
            segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
        }
    }

    void seg_relax(ll nod, ll l, ll r)
    {
        if (prop[nod] == 0)
            return;
        if (l < r)
        {
            ll m = (l + r) >> 1;
            segtree[nod << 1] += (m - l + 1) * prop[nod];
            prop[nod << 1] += prop[nod];
            segtree[nod << 1 | 1] += (r - m) * prop[nod];
            prop[nod << 1 | 1] += prop[nod];
        }
        prop[nod] = 0;
    }

    ll seg_query(ll nod, ll l, ll r, ll s, ll e)
    {
        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e)
            return segtree[nod];
        seg_relax(nod, l, r);
        ll m = (l + r) >> 1;
        return seg_query(nod << 1, l, m, s, e) + seg_query(nod << 1 | 1, m + 1, r, s, e);
    }

    void seg_update(ll nod, ll l, ll r, ll s, ll e, ll val){
        if (r < s || e < l)
            return;
        if (s <= l && r <= e)
        {
            segtree[nod] += (r - l + 1) * val;
            prop[nod] += val;
            return;
        }
        seg_relax(nod, l, r);
        ll m = (l + r) >> 1;
        seg_update(nod << 1, l, m, s, e, val);
        seg_update(nod << 1 | 1, m + 1, r, s, e, val);
        segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
    }
    // usage:
    // seg_update(1, 0, n - 1, qs, qe, val);
    // seg_query(1, 0, n - 1, qs, qe);
};

struct segment_without_lazy{
    vector<ll> segtree, dat;
    segment_without_lazy(ll n){
        segtree.resize(TSIZE * 2);
        dat.resize(n);
    }
    void seg_init(ll nod, ll l, ll r){
        if (l == r)
            segtree[nod] = dat[l];
        else
        {
            ll m = (l + r) >> 1;
            seg_init(nod << 1, l, m);
            seg_init(nod << 1 | 1, m + 1, r);
            segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
        }
    }

    ll seg_query(ll nod, ll l, ll r, ll s, ll e){
        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e) return segtree[nod];
        ll m = (l + r) >> 1;
        return seg_query(nod << 1, l, m, s, e) + seg_query(nod << 1 | 1, m + 1, r, s, e);
    }

    void seg_update(ll nod, ll l, ll r,ll s, ll val){
        if (r < s || s < l)
            return;
        if (s <= l && r <= s){
            segtree[nod] += (r - l + 1) * val;
            return;
        }
        ll m = (l + r) >> 1;
        seg_update(nod << 1, l, m, s, val);
        seg_update(nod << 1 | 1, m + 1, r, s, val);
        segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
    }
    // usage:
    // seg_update(1, 0, n - 1, qs, qe, val);
    // seg_query(1, 0, n - 1, qs, qe);

};

struct fenwick{
    vector<ll>data;
    fenwick(ll n){
        data.resize(n+1);
    }
    void update(ll idx, ll val){
        while(idx<data.size()){
            data[idx] += val;
            idx += (idx&-idx);
        }
    }
    ll sum(ll idx){
        ll res=0;
        while(idx>0){
            res+=data[idx];
            idx-=(idx&-idx);
        }
        return res;
    }
    ll sum(ll l, ll r){
        if(r<l)return 0;
        if(r>=data.size())r=data.size()-1;
        return sum(r)-sum(l-1);
    }
};

struct segment_prefixsum{
    const ll INF=1e18;
    struct node{
        ll sum,rsum,lsum,maxsum;
    };
    vector<node>segtree;
    vector<ll>dat;
    segment_prefixsum(ll n){
        segtree.resize(TSIZE<<1);
        dat.resize(n);
    }
    void seg_init(ll nod, ll l, ll r){
        if(l==r){
            segtree[nod]={dat[l],dat[l],dat[l],dat[l]};
            return;
        }
        ll m=(l+r)>>1;
        seg_init(nod<<1,l,m);
        seg_init(nod<<1|1,m+1,r);
        segtree[nod].sum=segtree[nod<<1].sum+segtree[nod<<1|1].sum;
        segtree[nod].rsum=max(segtree[nod<<1].rsum+segtree[nod<<1|1].sum,segtree[nod<<1|1].rsum);
        segtree[nod].lsum=max(segtree[nod<<1].sum+segtree[nod<<1|1].lsum,segtree[nod<<1].lsum);
        segtree[nod].maxsum=max({segtree[nod<<1].maxsum,segtree[nod<<1|1].maxsum,segtree[nod<<1].rsum+segtree[nod<<1|1].lsum});
    }
    node seg_query(ll nod, ll l, ll r, ll s, ll e){
        if(r<s || l>e){
            return {0,-INF,-INF,-INF};
        }
        if(s<=l && r<=e){
            return segtree[nod];
        }
        ll m=(l+r)>>1;
        auto lef=seg_query(nod<<1,l,m,s,e),rig=seg_query(nod<<1|1,m+1,r,s,e);
        node ret;
        ret.sum=lef.sum+rig.sum;
        ret.lsum=max({lef.lsum,lef.sum+rig.lsum});
        ret.rsum=max({lef.rsum+rig.sum,rig.rsum});
        ret.maxsum=max({lef.maxsum,rig.maxsum,lef.rsum+rig.lsum});
        return ret;
    }
};

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

void preprocess() {
    ll i, j, k;

}

struct query{
    ll s, e, idx;
    ll k;
    ll ans=0;
};

void solve(ll testcase){
    ll i, j, k;
    ll n,m;
    cin>>n;
    segment_prefixsum seg(n);
    vector<ll>prefix(n+1);
    for(i=0;i<n;i++){
        cin>>seg.dat[i];
        prefix[i+1]=prefix[i]+seg.dat[i];
    }
    seg.seg_init(1,0,n-1);
    cin>>m;
    for(i=0;i<m;i++){
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--,x2--,y1--,y2--;
        if(y1<x2){
            auto p=seg.seg_query(1,0,n-1,x1,y1);
            auto q=seg.seg_query(1,0,n-1,x2,y2);
            ll r=prefix[x2]-prefix[y1+1];
            cout<<p.rsum+r+q.lsum<<'\n';
        }
        else{
            auto p=seg.seg_query(1,0,n-1,x1,x2-1);
            auto q=seg.seg_query(1,0,n-1,y1+1,y2);
            auto r=seg.seg_query(1,0,n-1,x2,y1);
            cout<<max({p.rsum+r.sum+q.lsum,p.rsum+r.lsum,
                        r.rsum+q.lsum,r.maxsum})<<'\n';


        }
    }
}

int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        solve(testcase);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
typedef unsigned long long ull;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using vl = vector<ll>;
using pld = pair<ld,ld>;
using LD = __float128;
using LL = __int128;
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

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif
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
void factorize(ll n, unordered_map<ll, ll> &fl)
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

struct segment
{
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

    void seg_update(ll nod, ll l, ll r, ll s, ll e, ll val)
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
        ll m = (l + r) >> 1;
        seg_update(nod << 1, l, m, s, e, val);
        seg_update(nod << 1 | 1, m + 1, r, s, e, val);
        segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
    }
    // usage:
    // seg_update(1, 0, n - 1, qs, qe, val);
    // seg_query(1, 0, n - 1, qs, qe);
};

struct golden_mine{
    struct node{
        ll lprifix, rprefix, sum, maxsum;
    };
    vector<node>seg,dat;
    golden_mine(ll n){
        seg.resize(n*4);
        dat.resize(n);
    }
    void seg_add(ll nod, ll l, ll r, ll idx, ll val){
        if(l==r){
            seg[nod].lprifix+=val;
            seg[nod].rprefix+=val;
            seg[nod].sum+=val;
            seg[nod].maxsum+=val;
            return;
        }
        if(l>idx||r<idx)return;
        ll m=(l+r)>>1;
        if(idx<=m)seg_add(nod<<1,l,m,idx,val);
        else seg_add(nod<<1|1,m+1,r,idx,val);
        seg[nod].sum=seg[nod<<1].sum+seg[nod<<1|1].sum;
        seg[nod].lprifix=max(seg[nod<<1].lprifix
                ,seg[nod<<1].sum+seg[nod<<1|1].lprifix);
        seg[nod].rprefix=max(seg[nod<<1|1].rprefix
                ,seg[nod<<1|1].sum+seg[nod<<1].rprefix);
        seg[nod].maxsum=max({seg[nod].lprifix
                             ,seg[nod].rprefix
                             ,seg[nod<<1].maxsum
                             ,seg[nod<<1|1].maxsum
                             ,seg[nod<<1].rprefix+seg[nod<<1|1].lprifix});
    }
};

void yes(){
    cout<<"Yes\n";
}

void YES(){
    cout<<"YES\n";
}

void no(){
    cout<<"No\n";
}

void NO(){
    cout<<"NO\n";
}

void preprocess(){

}

constexpr ll mod=998244353;

void solve(){
    ll i,j,k;
    ll n;
    cin>>n;
    vector<tlll>arr(n);
    vector<ll>x(n),y(n);
    for(i=0;i<n;i++){
        cin>>get<0>(arr[i])>>get<1>(arr[i])>>get<2>(arr[i]);
        x[i]=get<0>(arr[i]);
        y[i]=get<1>(arr[i]);
    }
    sort(all(x));
    sort(all(y));
    x.erase(unique(all(x)),x.end());
    y.erase(unique(all(y)),y.end());
    for(i=0;i<n;i++){
        get<0>(arr[i])=lower_bound(all(x),get<0>(arr[i]))-x.begin();
        get<1>(arr[i])=lower_bound(all(y),get<1>(arr[i]))-y.begin();
    }
    sort(all(arr));
    ll ans=0;
    for(i=0;i<x.size();i++){
        golden_mine seg(y.size());
        ll now=0;
        while(now<n&&get<0>(arr[now])<i)now++;
        for(j=i;j<x.size();j++){
            while(now<n&&get<0>(arr[now])<=j){
                seg.seg_add(1,0,y.size()-1,get<1>(arr[now]),get<2>(arr[now]));
                now++;
            }
            ans=max(ans,seg.seg[1].maxsum);
        }
    }
    cout<<ans<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t st=clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}
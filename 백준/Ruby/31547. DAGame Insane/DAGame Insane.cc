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
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

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

vector<vector<ll>>edge,redge;
vector<vector<ll>>grundy,P;
vector<vector<bool>>vis;
vector<ll>color,E,PP;
vector<vector<ll>>arr;
vector<vector<ll>>co;

template <ll n = 32>
struct Matrix{
    vector<vector<ll>>mat;
    Matrix(){
        mat.resize(n,vector<ll>(n));
    }
    static Matrix eye(){
        Matrix ret;
        for(ll i=0;i<n;i++){
            ret.mat[i][i]=1;
        }
        return ret;
    }
    Matrix operator*(const Matrix &a){
        Matrix ret;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                for(ll k=0;k<n;k++){
                    ret.mat[i][j]+=mat[i][k]*a.mat[k][j] % mod;
                    ret.mat[i][j]%=mod;
                }
            }
        }
        return ret;
    }
    vector<ll> operator[](ll i){
        return mat[i];
    }
};

const ll TSIZE_MAT = 256;

struct segment_matrix{
    vector<Matrix<>>segtree,dat;
    segment_matrix(){
        segtree.resize(TSIZE_MAT*2, Matrix<>());
        dat.resize(TSIZE_MAT, Matrix<>());
    }
    void seg_init(ll nod, ll l, ll r){
        if(l==r){
            segtree[nod]=dat[l];
        }
        else{
            ll m=(l+r)>>1;
            seg_init(nod<<1,l,m);
            seg_init(nod<<1|1,m+1,r);
            segtree[nod]=segtree[nod<<1]*segtree[nod<<1|1];
        }
    }
    Matrix<> seg_query(ll nod, ll l, ll r, ll s, ll e){
        if(r<s||e<l)return Matrix<>::eye();
        if(s<=l&&r<=e)return segtree[nod];
        ll m=(l+r)>>1;
        return seg_query(nod<<1,l,m,s,e)*seg_query(nod<<1|1,m+1,r,s,e);
    }
    // segupdate : update dat[s] to val
    void seg_update(ll nod, ll l, ll r, ll s, Matrix<> val){
        if(r<s||s<l)return;
        if(l==r){
            dat[s]=val;
            segtree[nod]=val;
            return;
        }
        ll m=(l+r)>>1;
        seg_update(nod<<1,l,m,s,val);
        seg_update(nod<<1|1,m+1,r,s,val);
        segtree[nod]=segtree[nod<<1]*segtree[nod<<1|1];
    }

};

segment_matrix segm;

void preprocess() {
    ll i, j, k;
    arr.resize(256,vector<ll>(32));
    for(i=0;i<256;i++){
        for(j=0;j<32;j++){
            cin>>arr[i][j];
        }
    }
    for(i=0;i<256;i++){
        for(j=0;j<32;j++){
            for(k=0;k<32;k++){
                segm.dat[i].mat[j^k][arr[i][j]^arr[i][k]]++;
            }
        }
    }
    segm.seg_init(1,0,255);
}


ll get_grd(int i,int j){
    if(i>j)swap(i,j);
    if(vis[i][j])return grundy[i][j];
    else{
        vis[i][j]=1;
        bitset<70>bs;
        if(i==j){
            for (auto k: edge[i]) {
                bs.set(get_grd(k,k));
            }
        }
        else {
            for (auto k: edge[i]) {
                if (k < j) {
                    bs.set(get_grd(k, j));
                } else {
                    bs.set(get_grd(j, k));
                }
            }
            for (auto k: edge[j]) {
                if (i < k) {
                    bs.set(get_grd(i, k));
                } else {
                    bs.set(get_grd(k, i));
                }
            }
        }
        bs.flip();
        return grundy[i][j]=bs._Find_first();
    }
}

void solve(ll testcase){
    ll i, j, k,n,m,r;
    ll l;
    cin>>l;
    edge.clear();
    redge.clear();
    grundy.clear();
    P.clear();
    vis.clear();
    color.clear();
    E.clear();
    PP.clear();
    co.clear();
    vector<ll>modif(32);
    for(i=0;i<32;i++){
        cin>>modif[i];
    }
    Matrix tmp_mat;
    for(i=0;i<32;i++){
        for(j=0;j<32;j++){
            tmp_mat.mat[i^j][modif[i]^modif[j]]++;
        }
    }
    segm.seg_update(1,0,255,l,tmp_mat);
    ll st,en;
    cin>>st>>en;
    Matrix da=segm.seg_query(1,0,255,st,en);
    cin>>n>>m;
    edge.resize(n);
    redge.resize(n);
    P.resize(32,vector<ll>(64));
    PP.resize(32);
    co.resize(32);
    for(i=0;i<m;i++){
        ll p,q;
        cin>>p>>q;
        edge[p].push_back(q);
        redge[q].push_back(p);
    }
    vis.resize(n,vector<bool>(n));
    grundy.resize(n,vector<ll>(n,-1));
    cin>>r;
    color.resize(r);
    E.resize(r);
    for(i=0;i<r;i++){
        cin>>color[i]>>E[i];
        co[color[i]].push_back(E[i]);
    }
    vector<ll>ans(64);
    bool x=0;
    vector<ll>points;
    for(i=0;i<n;i++){
        if(redge[i].empty()){
            points.push_back(i);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            grundy[i][j]=get_grd(i,j);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<32;k++){
                P[k][grundy[i][j]]+=da[i^j][k];
                P[k][grundy[i][j]]%=mod;
            }
        }
    }
    for(i=0;i<32;i++){
        for(j=0;j<64;j++){
            PP[i]+=P[i][j];
            PP[i]%=mod;
        }
    }
    for(i=0;i<32;i++){
        if(co[i].size()) {
            vector<ll>prob(64);
            if(co[i].size()==1){
                for(j=0;j<n;j++){
                    prob[grundy[j][j]]++;
                }
                ll inv = modinverse(n,mod);
                for(auto &k:prob){
                    k*=inv;
                    k%=mod;
                }
            }
            else if(co[i].size()==2){
                if(PP[co[i][0]^co[i][1]]==0){
                    cout<<-1<<'\n';
                    return;
                }
                ll inv = modinverse(PP[co[i][0]^co[i][1]],mod);
                for(j=0;j<64;j++){
                    prob[j]=P[co[i][0]^co[i][1]][j]*inv;
                    prob[j]%=mod;
                }
            }
            if (x) {
                vector<ll> tmp(64);
                for (j = 0; j < 64; j++) {
                    for (k = 0; k < 64; k++) {
                        tmp[j ^ k] += ans[j] * prob[k];
                        tmp[j ^ k] %= mod;
                    }
                }
                ans = tmp;
            } else {
                ans=prob;
                x=1;
            }
        }
    }
    cout<<(1+mod-ans[0])%mod<<'\n';

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

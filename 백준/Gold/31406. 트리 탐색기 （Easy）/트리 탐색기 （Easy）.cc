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
    ll i, j;


}

ll phi(ll n){
    ll ret=n;
    for(ll i=2;i*i<=n;i++) {
        if(n%i==0) {
            ret=ret/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ret=ret/n*(n-1);
    return ret;
}

ll ans(ll n, ll m){
    if(n<=1||m<=1) return min(n,m)%m;
    return powm(n,ans(n,phi(m))+phi(m),m);
}

struct node{
    ll val;
    ll depth;
    node*nex;
    node*prev;
};

void solve(ll testcase){
    ll i, j, k;
    ll n,q;
    cin>>n>>q;
    ll now=1;
    vector<bool>isopen(n+1);
    vector<vector<ll>>arr(n+1);
    vector<ll>par(n+1);
    vector<node*>ptr(n+1);
    isopen[1]=true;
    for(i=1;i<=n;i++){
        ptr[i]=new node();
        ptr[i]->val=i;
        ptr[i]->nex=ptr[i];
        ptr[i]->prev=ptr[i];
    }
    for(i=1;i<=n;i++){
        ll x;
        cin>>x;
        arr[i].resize(x);
        for(j=0;j<x;j++){
            cin>>arr[i][j];
            par[arr[i][j]]=i;
        }
        for(j=0;j<x;j++){
            if(j){
                ptr[arr[i][j]]->prev=ptr[arr[i][j-1]];
            }
            else{
                ptr[arr[i][j]]->prev=ptr[arr[i][j]];
            }
            if(j+1<x){
                ptr[arr[i][j]]->nex=ptr[arr[i][j+1]];
            }
            else{
                ptr[arr[i][j]]->nex=ptr[arr[i][j]];
            }
        }
    }
    now=arr[1][0];
    stack<ll>stk;
    stk.push(1);
    while(!stk.empty()){
        ll now2=stk.top();
        stk.pop();
        for(auto x:arr[now2]){
            stk.push(x);
            ptr[x]->depth=ptr[now2]->depth+1;
        }
    }
    node*nowptr=ptr[now];
//    nowptr->prev=ptr[now];
//    for(i=1;i<arr[1].size();i++){
//        nowptr->nex=ptr[arr[1][i]];
//        ptr[arr[1][i]]->prev=nowptr;
//        nowptr=nowptr->nex;
//    }
//    nowptr->nex=nowptr;
//    nowptr=ptr[now];
    for(i=0;i<q;i++){
        string str;
        ll moven;
        cin>>str;
        if(str=="move"){
            cin>>moven;
            if(moven<0){
                moven=-moven;
                for(j=0;j<moven;j++){
                    nowptr=nowptr->prev;
                }
            }
            else{
                for(j=0;j<moven;j++){
                    nowptr=nowptr->nex;
                }
            }
            cout<<nowptr->val<<'\n';
        }
        else{
            if(isopen[nowptr->val]){
                isopen[nowptr->val]=false;
                if(arr[nowptr->val].size()==0){
                    continue;
                }
                ll nowdepth=nowptr->depth;
                node* ptrtmp=nowptr->nex;
                while(ptrtmp->depth>nowdepth && ptrtmp->nex!=ptrtmp){
                    ptrtmp=ptrtmp->nex;
                }
                if(ptrtmp->depth<=nowdepth){
                    ptrtmp->prev->nex=ptrtmp->prev;
                    ptrtmp->prev=nowptr;
                    nowptr->nex->prev=nowptr->nex;
                    nowptr->nex=ptrtmp;
                    continue;
                }
                nowptr->nex->prev=nowptr->nex;
                nowptr->nex=nowptr;
            }
            else{
                isopen[nowptr->val]=true;
                if(arr[nowptr->val].size()==0){
                    continue;
                }
                node*ptrtmp=nowptr->nex;
                nowptr->nex=ptr[arr[nowptr->val][0]];
                nowptr->nex->prev=nowptr;
                node* rptr=nowptr->nex;
                while(rptr->nex!=rptr){
                    rptr=rptr->nex;
                }
                if(ptrtmp!=nowptr) {
                    rptr->nex = ptrtmp;
                    ptrtmp->prev = rptr;
                }
                else{
                    rptr->nex=rptr;
                }
            }
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

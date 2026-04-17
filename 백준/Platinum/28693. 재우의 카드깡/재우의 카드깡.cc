#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
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

ll gcd(ll a, ll b){
    return a&&b?gcd(b,a%b):a+b;
}

struct rational{
    ll p,q;
    bool operator<(const rational& r) const{
        return p*r.q<q*r.p;
    }
    void normalize(){
        ll g=gcd(p,q);
        p/=g;
        q/=g;
        if(q<0){
            p=-p;
            q=-q;
        }
    }
    rational(ll p=0,ll q=1):p(p),q(q){
        normalize();
    }
};

struct line{
    ll a,b;
//    rational intersect(const line& l) const{
//        return rational(l.b-b,a-l.a);
//    }
    long double intersect(const line& l) const{
        return (long double)(l.b-b)/(a-l.a);
    }
    ll func(ll x) const{
        return a*x+b;
    }
};

void preprocess() {
    ll i, j;


}

ll powm(ll a, ll b, ll m=mod){
    ll ret=1;
    while(b){
        if(b&1) ret=ret*a%m;
        a=a*a%m;
        b>>=1;
    }
    return ret;
}

ll modinv(ll a, ll m=mod){
    return powm(a,m-2,m);
}

void solve(ll testcase){
    int i,j;
    ll n;
    cin>>n;
    vector<vector<ll>>memoization(2*n+1,vector<ll>(n+1,-1));

    auto f=[&](auto &f,ll p, ll q)->ll{
        if(p==2*q)return memoization[p][q]=q;
        if(q<0 || 2*q > p)return 0;
        if(memoization[p][q]!=-1)return memoization[p][q];
        ll inv_pmq = modinv(p-q),inv_pmqm1 = modinv(p-q-1);

        return memoization[p][q]
                = (q*inv_pmq%mod*f(f,p-2,q-1)%mod
                    + (p-2*q)*inv_pmq%mod*1%mod*inv_pmqm1%mod*f(f,p-2,q)%mod
                    + (p-2*q)*inv_pmq%mod*q%mod*inv_pmqm1%mod*(f(f,p-2,q)+1)%mod
                    + (p-2*q)*inv_pmq%mod*(p-2*q-2)%mod*inv_pmqm1%mod*f(f,p,q+2)%mod
                    + 1)%mod;
    };
    cout<<f(f,2*n,0)<<'\n';
    cout<<'\n';

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

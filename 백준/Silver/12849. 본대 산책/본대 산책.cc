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

void solve(ll testcase){
    int i,j;
    int n=8,d,mod=1'000'000'007;
    cin>>d;
    vector<ll> dp(n);
    dp[0]=1;
    for(i=0;i<d;i++){
        vector<ll>tmp(n);
        tmp[0]=dp[1]+dp[2];
        tmp[1]=dp[0]+dp[2]+dp[3];
        tmp[2]=dp[0]+dp[1]+dp[3]+dp[5];
        tmp[3]=dp[1]+dp[2]+dp[4]+dp[5];
        tmp[4]=dp[3]+dp[5]+dp[6];
        tmp[5]=dp[2]+dp[3]+dp[4]+dp[7];
        tmp[6]=dp[4]+dp[7];
        tmp[7]=dp[5]+dp[6];
        for(j=0;j<n;j++){
            tmp[j]%=mod;
        }
        dp=tmp;
    }
    cout<<dp[0];


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

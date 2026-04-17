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
    int n=20;
    auto calc=[&](int x){
        return (x-1000)/50;
    };
    long double pw,pl,pd,b,s,g,p,d;
    cin >> pw >> pl >> pd;
    int maxs=calc(3000)+1;
    vector<long double> dp(maxs);
    b=s=g=p=d=0;
    dp[calc(2000)] = 1;
    for(i=0;i<n;i++){
        auto tmp=dp;
        fill(dp.begin(), dp.end(),0);
        for(j=0;j<maxs;j++){
            if(tmp[j]==0)continue;
            dp[j+1]+=tmp[j]*pw;
            dp[j-1]+=tmp[j]*pl;
            dp[j]+=tmp[j]*pd;
        }
    }
    for(i=0;i<maxs;i++){
        if(i*50+1000>=3000) d+=dp[i];
        else if(i*50+1000>=2500) p+=dp[i];
        else if(i*50+1000>=2000) g+=dp[i];
        else if(i*50+1000>=1500) s+=dp[i];
        else b+=dp[i];
    }
    cout << fixed << setprecision(8);
    cout << b << '\n' << s << '\n' << g << '\n' << p << '\n' << d << '\n';


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

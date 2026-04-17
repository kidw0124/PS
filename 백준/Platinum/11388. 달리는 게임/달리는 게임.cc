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
    ll i,j;
    ll n,m,s;
    cin>>n;
    vector<ll>arr(n),rsum(n+1,0),rrsum(n+1,0);
    for(i=0;i<n;i++) cin>>arr[i];
    for(i=n-1;i>=0;i--) rsum[i]=rsum[i+1]+arr[i];
    for(i=n-1;i>=0;i--) rrsum[i]=rrsum[i+1]+rsum[i];
    vector<ll>dp(n+1,0);
    vector<line>cht;
    dp[0]=max(0ll,arr[0]);
    cht.push_back({0,rrsum[0]});
    for(i=1;i<n;i++){
        ll x=rsum[i+1];
        while(cht.size()>1){
            line l1=cht.back();
            cht.pop_back();
            line l2=cht.back();
//            rational r=l1.intersect(l2);
            long double r=l1.intersect(l2);
            if(r<x){
                cht.push_back(l1);
                break;
            }
        }
        ll st=0,en=cht.size()-1;
        while(st<en){
            ll mid=(st+en)>>1;
            long double r=cht[mid].intersect(cht[mid+1]);
            if(r<x){
                st=mid+1;
            }
            else{
                en=mid;
            }
        }
        debug<<st<<'\n';
        dp[i]=max(dp[i-1],cht[st].func(x)-rsum[i+1]*(i+1)-rrsum[i+1]);
        cht.push_back({i+1,dp[i]+rrsum[i+1]});
    }
    cout<<dp[n-1];

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

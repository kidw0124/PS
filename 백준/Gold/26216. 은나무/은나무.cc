#include<bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll i,j;
    ll k,h;
    cin>>k>>h;
    ll q;
    bool x=1;
    cin>>q;
    LL m=1;
    for(i=0;i<h;i++){
        m*=(k+1);
        if(m>1e18)x=0;
    }
    while(q--){
        ll a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        else if(b>=m&&x)cout<<"-1\n";
        else if(a==b)cout<<"0\n";
        else{
            ll ta=a,tb=b;
            ll za=0,zb=0;
            while(ta%(k+1)==0)za++,ta/=k+1;
            while(tb%(k+1)==0)zb++,tb/=k+1;
            LL t=1;
            ll now=0;
            for(i=0;i<h;i++){
                if(a/t!=b/t&&a%t!=0&&b%t!=0)now=i;
                t*=k+1;
                if(t>b)break;
            }
            now=max({now,za,zb});
            cout<<2*(now+1)-za-zb<<'\n';
        }
    }
    return 0;
}

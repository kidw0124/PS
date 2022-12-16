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
void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
//    setup();
    ll i,j;
    ll n;
    cin>>n;
    ll k=__lg(n);
    ll sa=1,ea=n,sb=1,eb=n;
    while(k--){
        ll ma=(sa+ea)>>1,mb=(sb+eb)>>1;
        cout<<"? A "<<ma<<'\n';
        ll a,b;
        cin>>a;
        cout<<flush;
        cout<<"? B "<<mb<<'\n';
        cin>>b;
        cout<<flush;
        if(a<b){
            sa=ma+1,eb=mb;
        }
        else ea=ma,sb=mb+1;
    }
    cout<<"? A "<<sa<<'\n';
    ll a,b;
    cin>>a;
    cout<<flush;
    cout<<"? B "<<sb<<'\n';
    cin>>b;
    cout<<flush;
    cout<<"! "<<min(a,b);
    return 0;
}

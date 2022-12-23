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
    setup();
    ll i,j;
    ll n=0;
    cin>>n;
    ll p=1;
    if(n==0){
        cout<<"A";
        return 0;
    }
//    ll lim=100000;
//    p=n;
//    while(n){
//        p=n;
//        for(i=1;i*i<=n;i++)if(n%i==0)p=i;
//        debug<<n<<' '<<n/p<<' '<<p<<'\n';
//        if(lim<p+n/p+24){
//            ll sn=i-1;
//            for(i=0;i<sn;i++)cout<<"A";
//            for(i='B';i<'Z';i++)cout<<(char)i;
//            for(i=0;i<sn;i++)cout<<"Z";
//            n-=sn*sn;
//            lim-=sn+24+sn;
//        }
//        for(i=0;i<p;i++)cout<<"A";
//        for(i='B';i<'Z';i++)cout<<(char)i;
//        for(i=0;i<n/p;i++)cout<<"Z";
//        n-=n;
//        lim-=p+24+n/p;
//    }
    ll sn=0;
    string str;
    while((sn+1)*(sn+1)<=n)sn++;
    for(i=0;i<sn;i++){
        str+='A';
    }
    for(i='B';i<'Z';i++){
        str+=i;
    }
    for(i=0;i<sn;i++){
        str+='Z';
    }
    n-=sn*sn;
    if(n) {
        sn=0;
        while((sn+1)*(sn+1)<=n)sn++;
        for(i=0;i<sn;i++){
            str+='A';
        }
        for(i='B';i<'Z';i++){
            str+=i;
        }
        for(i=0;i<sn;i++){
            str+='Z';
        }
        n-=sn*sn;
        if(n){
            for(i='A';i<'Z';i++){
                str+=i;
            }
            for(i=0;i<n;i++){
                str+='Z';
            }
        }
    }
    debugv(str.size())
    cout<<str;
    return 0;
}

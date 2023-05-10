#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef tuple<ll,ll,ll>tlll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (!ndebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

ll dist(tlll&a, tlll&b){
    auto [ax,ay,az]=a;
    auto [bx,by,bz]=b;
    return (ax-bx)*(ax-bx)
            +(ay-by)*(ay-by)
            +(az-bz)*(az-bz);
}

ll inner(tlll a,tlll b){
    auto [ax,ay,az]=a;
    auto [bx,by,bz]=b;
    return ax*bx+ay*by+az*bz;
}

tlll operator-(const tlll a,const tlll b){
    auto [ax,ay,az]=a;
    auto [bx,by,bz]=b;
    return {ax-bx,ay-by,az-bz};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    tuple<ll,ll,ll>a,b,c;
    ll x,y,z;
    cin>>x>>y>>z;
    a={x,y,z};
    cin>>x>>y>>z;
    b={x,y,z};
    cin>>x>>y>>z;
    c={x,y,z};
    cout<<fixed<<setprecision(9);
    ll ab=dist(a,b),bc=dist(b,c),ca=dist(c,a);
    if(inner(b-a,b-c)<0){
        cout<<sqrt(bc);
    }
    else if(inner(a-c,a-b)<0){
        cout<<sqrt(ca);
    }
    else{
        long double s4=sqrt((ab+bc+ca)*(ab+bc+ca)-2*(ab*ab+bc*bc+ca*ca));
        cout<<s4/2.0/sqrt(ab);
    }
    return 0;
}

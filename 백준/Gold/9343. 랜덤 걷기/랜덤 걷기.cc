#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
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


ll MOD=1e9+7;

ll facto[2000000+5]={1,1};
ll ans[1000000+5]={0};
ll inv(ll n,ll p=LONG_MAX){
    if(n==1)return 1;
    else return p-(p/n)*inv(p%n,MOD)%p;
}
ll NCR(ll n, ll r, ll p=LONG_MAX){
    return facto[n]*inv(facto[r],p)%p*inv(facto[n-r],p)%p;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    ll t;
    for(i=1;i<=2000000;i++)facto[i]=(facto[i-1]*i)%MOD;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(ans[n])cout<<ans[n];
        else cout<<(ans[n]=NCR(n<<1,n,MOD)*inv(n+1,MOD)%MOD)<<'\n';
    }
    return 0;
}

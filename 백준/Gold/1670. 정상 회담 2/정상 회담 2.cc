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

ll INV[500000+5]={0,1};
ll inv(ll n,ll p=LONG_MAX){
    if(INV[n])return INV[n];
    else return INV[n]=(p-(p/n)%p)*inv(p%n)%p;
}
ll NCR(ll n, ll r, ll p=LONG_MAX){
    ll ret=1;
    if(n-r<r)r=n-r;
    for(ll i=0;i<r;i++){
        ret*=n-i;
        ret%=p;
        ret*=inv(i+1,p);
        ret%=p;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    ll n,m=987654321;
    cin>>n;
    n/=2;
    vector<ll>dp(n+1);
    dp[0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<i>>1;j++){
            dp[i]+=2*dp[j]*dp[i-j-1];
            dp[i]%=m;
        }
        if((i-1)%2==0){
            j=(i-1)/2;
            dp[i]+=dp[j]*dp[i-j-1];
            dp[i]%=m;
        }
    }
    //each(x,dp)debugv(x);
    cout<<dp[n];
    return 0;
}

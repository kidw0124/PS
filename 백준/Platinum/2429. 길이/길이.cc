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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<pll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    arr.push_back(arr[0]);
    ll s=0,t=0;
    for(i=0;i<n;i++){
        s+=arr[i].first*arr[i+1].second
            -arr[i+1].first*arr[i].second;
        if(arr[i].first==arr[i+1].first)t+=abs(arr[i].second-arr[i+1].second);
        if(arr[i].second==arr[i+1].second)t+=abs(arr[i].first-arr[i+1].first);
    }
    if(s<0)s=-s;
    cout<<fixed<<s-t/2.0<<'\n';
    return 0;
}

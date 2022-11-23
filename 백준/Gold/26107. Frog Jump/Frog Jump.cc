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
    ll n,k;
    cin>>n>>k;
    vector<pll>arr(n);
    vector<ll>brr(k),pfx(n+1),group(n);
    for(i=0;i<n;i++)cin>>arr[i].first>>arr[i].second;
    for(i=0;i<k;i++)cin>>brr[i],brr[i]--;
    sort(all(arr));
    ll now=arr[0].second;
    for(i=1;i<n;i++){
        if(now<arr[i].first){
            group[i]=group[i-1]+1;
            pfx[group[i]+1]=pfx[group[i]]+arr[i].first-now;
            now=arr[i].second;
        }
        else group[i]=group[i-1],now=max(now,arr[i].second);
    }
    now=0;
    debugc(group);
    debugc(pfx);
    ll ans=0;
    for(i=0;i<k;i++){
        ans+=abs(pfx[group[brr[i]]+1]-pfx[now+1]);
        now=group[brr[i]];
    }
    cout<<ans;

    return 0;
}

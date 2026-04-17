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
    ll n;
    cin>>n;
    vector<ll>arr(n),brr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    brr=arr;
    sort(all(brr));
    for(i=0;i<n;i++){
        arr[i]=lower_bound(brr.begin(),brr.end(),arr[i])-brr.begin();
    }
    //each(x,arr)cout<<x<<' ';
    vector<bool>vis(n);
    vector<vector<ll>>cyc;
    ll ans=0;
    for(i=0;i<n;i++){
        if(!vis[i]){
            ll x=i;
            vector<ll>tmp;
            do{
                tmp.push_back(x);
                x=arr[x];
                ans+=brr[x];
                vis[x]=1;
            }while(x!=i);
            sort(all(tmp));
            cyc.push_back(tmp);
            ans+=min(((ll)tmp.size()-2)*brr[x],brr[x]+((ll)tmp.size()+1)*brr[0]);
        }
    }
    cout<<ans;
    return 0;
}

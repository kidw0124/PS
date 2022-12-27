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

struct node{
    ll type;
    vector<ll> first;
    ll period;
};

int main(){
    setup();
    ll i,j;
    ll n,k,t;
    cin>>t;
    while(t--){
        cin>>k>>n;
        vector<vector<ll>>arr(14,vector<ll>(n+1));
        for(i=0;i<=min(n,k);i++){
            arr[0][i]=1;
        }
        for(i=1;i<14;i++){
            arr[i][0]=1;
            ll now=1<<i;
            for(j=1;j<=n;j++){
                for(ll r=0;now*r<=j&&r<=k;r++){
                    arr[i][j]+=arr[i-1][j-now*r];
                    arr[i][j]%=(ll)(1e9+7);
                }
            }
        }
        cout<<arr[13][n]<<'\n';
    }

}
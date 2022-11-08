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
    vector<vector<ll>>arr(105,vector<ll>(105));
    vector<vector<ll>>sum(105,vector<ll>(105));
    while(n--){
        ll a,b;
        cin>>a>>b;
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                arr[i+a][j+b]=1;
            }
        }
    }
    for(i=1;i<105;i++){
        for(j=1;j<105;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i-1][j-1];
        }
    }
    ll ans=0;
    for(i=0;i<101;i++){
        for(j=0;j<101;j++){
            for(ll k=i;k<101;k++){
                for(ll t=j;t<101;t++){
                    if(sum[k+1][t+1]-sum[k+1][j]-sum[i][t+1]+sum[i][j]==(k-i+1)*(t-j+1)){
                        ans=max(ans,(k-i+1)*(t-j+1));
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

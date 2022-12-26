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

const ll MAX=2500,MAXBS=20000;

ll mex(bitset<MAXBS>bs){
    for(int i=0;i<MAXBS;i++){
        if(!bs.test(i))return i;
    }
    return MAXBS;
}

int main(){
    setup();
    ll i,j,k;
    vector<vector<ll>>dp(26,vector<ll>(MAX));
    vector<ll>period({0,1,3,3,6,12,24,12,24,24,24,24,48,48,96,96,96,192,192,384,384,384,768,768,768,768});
    for(i=1;i<=25;i++) {
        ll n = 0;
        for (j = 1; j < MAX; j++) {
            if (i == 1 && j == 1)dp[i][j] = 0;
            else {
                bitset<MAXBS> bs;
                for (k = i - 1; k >= 1; k--) {
                    bs[dp[k][j]] = 1;
                }
                for (k = j - 1; k >= 1; k--) {
                    bs[dp[i][k]] = 1;
                }
                for (k = i - 1; k >= 1; k--) {
                    bs[dp[k][j]] = 1;
                }
                for (k = 1; k < min(i, j); k++) {
                    bs[dp[i - k][j - k]] = 1;
                }
                dp[i][j] = mex(bs);
            }
        }
    }
    const auto grd=[&](ll x, ll y){
        if(y<MAX) return dp[x][y];
        else{
            ll quota=(y-MAX)/period[x]+1;
            return dp[x][y-period[x]*quota]+period[x]*quota;
        }
    };
    ll t=0;
    cin>>t;
    while (t--){
        ll r,c,n;
        cin>>r>>c>>n;
        ll ans=0;
        for(i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            ans^=grd(x,y);
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }

}
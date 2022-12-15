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
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    setup();
    ll i,j;
    ll n;
    cin>>n;
    set<pll>points;
    for(i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        points.insert({x,y});
    }
    ll ans=0;
    for(pll first:points){
        for(pll second:points) {
            if (first == second) {
                continue;
            } else {
                ll dx = -first.first + second.first;
                ll dy = -first.second + second.second;
                if ((dx + dy) % 2 == 0) {
                    ll ddx = (dx + dy) / 2;
                    ll ddy = (dx - dy) / 2;
                    debug<<first.first<<' '<<first.second<<' '<<second.first<<' '<<second.second
                        <<' '<<ddx<<' '<<ddy<<'\n';
                    if (points.find({first.first + ddy, first.second + ddx}) != points.end()
                        && points.find({first.first + ddx, first.second - ddy}) != points.end()) {
                        ans = max(ans, (dx * dx + dy * dy) / 2);
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

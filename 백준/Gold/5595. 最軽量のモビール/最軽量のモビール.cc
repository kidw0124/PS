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

int main(){
    setup();
    ll i,j;
    ll n;
    cin>>n;
    vector<tuple<ll,ll,ll,ll>>arr(n+1);
    vector<ll>par(n+1),dp(n+1),dep(n+1);
    priority_queue<pll>que;
    for(i=1;i<=n;i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll g = gcd(a, b);
        arr[i] = {a / g, b / g, c, d};
        par[c] = par[d] = i;
    }
    ll root=1;
    while(par[root])root=par[root];
    queue<ll>treeq;
    treeq.push(root);
    while(!treeq.empty()){
        ll now=treeq.front();
        treeq.pop();
        auto [a,b,c,d]=arr[now];
        if(c==0&&d==0){
            que.push({dep[now],now});
        }
        dep[c]=dep[d]=dep[now]+1;
        if(c)treeq.push(c);
        if(d)treeq.push(d);
    }
    dp[0]=1;
    while(!que.empty()){
        auto [de,now]=que.top();
        que.pop();
        if(dp[now])continue;
        auto [a,b,c,d]=arr[now];
        ll g=gcd(a*dp[c],b*dp[d]);
        ll a0=a*dp[c]/g,b0=b*dp[d]/g;
        dp[now]=dp[c]*b0+dp[d]*a0;
        if(par[now]==0){
            cout<<dp[now];
            return 0;
        }
        else{
            que.push({dep[now]-1,par[now]});
        }
    }

}

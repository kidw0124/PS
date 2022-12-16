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
#define INT_MAX (ll)2147483647*2147483647

int main(){
    setup();
    ll i,j;
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>>dis(n+1,vector<ll>(k+1,INT_MAX));
    vector<vector<bool>>vis(n+1,vector<bool>(n+1));
    vector<vector<pll>>edge(n+1);
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    priority_queue<pair<ll,pll>>pq;
    pq.push({0,{1,0}});
    while(!pq.empty()){
        auto [node,skip]=pq.top().second;
        ll now = -pq.top().first;
        pq.pop();
        if(vis[node][skip])continue;
        else {
            vis[node][skip] = 1;
            dis[node][skip] = now;
            for (auto [nex, cost]: edge[node]) {
                if (!vis[nex][skip]) {
                    pq.push({-(now+cost),{nex,skip}});
                }
                if(skip<k&&!vis[nex][skip+1]){
                    pq.push({-now,{nex,skip+1}});
                }
            }
        }
    }
    cout<<*min_element(dis[n].begin(),dis[n].end());

    return 0;
}

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
    ll n,m,k;
    ll s,e;
    cin>>m>>n>>k>>s>>e;
    vector<vector<ll>>org(n+1);
    vector<pll>org_edge(m);
    vector<ll>cost(m),dis(m,INT_MAX);
    vector<vector<ll>>edge(m);
    set<tuple<ll,ll,ll>>ban;
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        org[a].push_back(i);
        org_edge[i]={a,b};
        cost[i]=c;
    }
    for(i=0;i<k;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        ban.insert({a,b,c});
    }
    for(i=0;i<m;i++){
        auto [a,b]=org_edge[i];
        for(auto k:org[b]){
            ll c=org_edge[k].second;
            if(ban.find({a,b,c})==ban.end()){
                edge[i].push_back(k);
            }
        }
    }
    priority_queue<pll>pq;
    for(i=0;i<m;i++){
        if(org_edge[i].first==s){
            pq.push({-cost[i],i});
            dis[i]=cost[i];
        }
    }
    while(!pq.empty()){
        auto [nowdis,now]=pq.top();
        nowdis=-nowdis;
        pq.pop();
        for(auto k:edge[now]){
            if(dis[k]>dis[now]+cost[k]){
                dis[k]=dis[now]+cost[k];
                pq.push({-dis[k],k});
            }
        }
    }
    ll ans=INT_MAX;
    for(i=0;i<m;i++){
        if(org_edge[i].second==e){
            ans=min(ans,dis[i]);
        }
    }
    if(s==e)cout<<0;
    else if(ans==INT_MAX)cout<<-1;
    else cout<<ans;
    return 0;
}

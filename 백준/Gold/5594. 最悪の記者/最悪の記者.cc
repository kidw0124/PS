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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>edge(n+1), redge(n+1);
    vector<bool>vis(n+1);
    vector<ll>cnt(n+1),rank(n+1);
    for(i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        redge[y].push_back(x);
        cnt[y]++;
    }
    ll r=1;
    queue<ll>que;
    for(i=1;i<=n;i++){
        if(cnt[i]==0&&!vis[i]){
            que.push(i),vis[i]=1;
            while(!que.empty()){
                ll now=que.front();
                que.pop();
                rank[now]=r++;
                debug<<now<<' '<<que.size()<<'\n';
                debugc(vis);
                for(auto k:edge[now]){
                    debugc(edge[now]);
                    if(vis[k])continue;
                    else{
                        cnt[k]--;
                        debugv(k);
                        if(cnt[k]==0){
                            que.push(k);
                            vis[k]=1;
                        }
                    }
                }
            }
        }
    }
    vector<ll>ord(n+1);
    for(i=1;i<=n;i++){
        ord[rank[i]]=i;
    }
    for(i=1;i<=n;i++){
        cout<<ord[i]<<'\n';
    }
    for(i=1;i<n;i++){
        if(rank[i]!=n&&std::find(edge[i].begin(), edge[i].end(),ord[rank[i]+1])==edge[i].end()){
            debug<<i<<' '<<ord[rank[i]+1]<<'\n';
            cout<<1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}

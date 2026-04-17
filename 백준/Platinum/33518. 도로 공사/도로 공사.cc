#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <ext/rope>
using namespace __gnu_cxx;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

struct road{
    ll u,v;
    ll l,r;
};

constexpr ll MOD = 1e9+7;

ll modmul(ll a, ll b, ll mod = MOD) {
    return (a * b) % mod;
}

void solve(ll testcase){
    ll i, j;
    ll n,m;
    cin >> n >> m;
    vector<pll>dist(n-1);
    i=2;
    for(auto &[a,b]:dist) cin >> a,b=i++;
    sort(dist.begin(),dist.end());
    vector<road>roads(m);
    vector<vector<ll>>adj(n+1);
    vector<ll>dis(n+1);
    for(i=0;i<m;i++){
        cin >> roads[i].u >> roads[i].v >> roads[i].l >> roads[i].r;
        adj[roads[i].u].push_back(i);
        adj[roads[i].v].push_back(i);
    }
    ll ans=1;
    for(const auto &[d,vv]:dist){
        ll tmp0=1,tmp1=1;
        for(const auto &k:adj[vv]){
            auto &[u,v,l,r]=roads[k];
            auto pr=u^v^vv;
            if(pr!=1 && !dis[pr])continue;
//            cout<<vv<<' '<<u<<' '<<v<<' '<<pr<<' '<<l<<' '<<r<<' '<<d-dis[pr]<<'\n';
            ll l0=max(l,d-dis[pr]);
            ll l1=max(l,d-dis[pr]+1);
//            cout<<vv<<' '<<u<<' '<<v<<' '<<pr<<' '<<l<<' '<<r<<' '<<d-dis[pr]<<'\n';
            tmp0=modmul(tmp0,max(0ll,r-l0+1));
            tmp1=modmul(tmp1,max(0ll,r-l1+1));
        }
        dis[vv]=d;
//        cout<<tmp0<<' '<<tmp1<<'\n';
//        ans=modmul(ans,tmp0);
        ans=modmul(ans,tmp0-tmp1);
    }
    if(ans<0)ans+=MOD;
    cout << ans << '\n';
}

void setup() {
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j, k;

}

signed main() {
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
#ifdef kidw0124
    clock_t st = clock();
#endif
    for (ll testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
#ifdef kidw0124
    cout << "\n\nTime: " << (clock() - st) * 1.0 / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}

#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

void yes(){
    cout<<"Yes\n";
}

void no(){
    cout<<"No\n";
}
constexpr ll mod=998244353;
ll ipow(ll a, ll b){
    if(!b)return 1;
    else{
        ll now=ipow(a,b>>1);
        if(b&1)return now*now%mod*a%mod;
        else return now*now%mod;
    }
}

void solve(){
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(auto &x:arr)cin>>x;
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(m+1,-1)));
    vector<vector<vector<pair<tlll,tlll>>>> next(n,
                                                 vector<vector<pair<tlll,tlll>>>(n+1,
                                                                                 vector<pair<tlll,tlll>>(m+1,
                                                                                                         {{-1,-1,-1},{ -1, -1, -1 }})));
    vector<vector<vector<pll>>>now(n,vector<vector<pll>>(n+1,vector<pll>(m+1,{-1,-1})));
    auto dfs=[&](ll x, ll y, ll z, auto&&dfs)->ll{
        if(dp[x][y][z]!=-1)return dp[x][y][z];
        if(z==0)return dp[x][y][z]=0;
        if(x>=y)return dp[x][y][z]=-1e9;
        auto [a,b,c,d,e,f]= make_tuple(x+1,y,z,-1,-1,-1);
        pll ppp={-1,-1};
        ll ret=dfs(x+1,y,z,dfs);
        if(ret<dfs(x+1,y,z-1,dfs)+arr[x]){
            ret=dfs(x+1,y,z-1,dfs)+arr[x];
            a=x+1;
            b=y;
            c=z-1;
            d=e=f=-1;
            ppp={x,-1};
        }
        for(ll i=x+1;i<y;i++){
            for(ll j=0;j<=z-1;j++){
                if(ret<dfs(x+1,i,j,dfs)+dfs(i+1,y,z-1-j,dfs)+arr[x]*arr[i]){
                    a=x+1;
                    b=i;
                    c=j;
                    d=i+1;
                    e=y;
                    f=z-1-j;
                    ret=dfs(x+1,i,j,dfs)+dfs(i+1,y,z-j-1,dfs)+arr[x]*arr[i];
                    ppp={x,i};
                }
            }
        }
        next[x][y][z]={{a, b, c},{d, e, f}};
        now[x][y][z]=ppp;
        debug<<x+1<<' '<<y<<' '<<z<<" : "
             <<ret<<", "
             <<a+1<<' '<<b<<' '<<c<<", "
             <<d+1<<' '<<e<<' '<<f<<", "
             <<ppp.first<<' '<<ppp.second<<'\n';
        return dp[x][y][z]=ret;
    };
    dfs(0,n,m,dfs);
    vector<ll>ans;
    vector<ll>ans2(n+1);
    queue<tlll> q;
    q.push({0,n,m});
    while(!q.empty()){
        auto [ra,rb,rc]=q.front();
        q.pop();
        if(ra>=rb || ra ==-1)continue;
        pll tmp;
        tmp=now[ra][rb][rc];
        if(tmp.first==-1){
        }
        else if(tmp.second==-1){
            ans.push_back(tmp.first+1);
            ans2[tmp.first+1]=tmp.first+1;
        }else{
            ans.push_back(tmp.first+1);
            ans2[tmp.first+1]=tmp.second+1;
            ans2[tmp.second+1]=tmp.first+1;
        }
        q.push(next[ra][rb][rc].first);
        q.push(next[ra][rb][rc].second);
    }
    for(auto x:ans)cout<<x<<'\n';
    while(ans.size()<m){
        ans.push_back(0);
        cout<<0<<'\n';
    }
    for(i=1;i<=n;i++){
        cout<<ans2[i]<<'\n';
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    ll t=1;
//    cin>>t;
#ifdef kidw0124
    clock_t st=clock();
#endif
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}
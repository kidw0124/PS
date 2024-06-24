#include<bits/stdc++.h>
using namespace std;
#ifdef ATCODER
#include<atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
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

void preprocess(){

}

constexpr ll mod=998244353;

const ll INF=1e18;

void solve(){
    int i,j,k;
    ll n,m;
    cin>>n>>m;
    n++,m++;
    pll a1,a2,b1,b2;
    cin>>a1.first>>a1.second>>a2.first>>a2.second;
    cin>>b1.first>>b1.second>>b2.first>>b2.second;
    auto get_ans=[&n,&m](pll a1,pll a2,pll b1,pll b2){
        vector<vector<ll>> dist(n,vector<ll>(m,-1));
        vector<vector<pll>> par(n,vector<pll>(m,{-1,-1}));
        queue<pll> q;
        q.push(a1);
        vector<pll> dir={{1,0},{-1,0},{0,1},{0,-1}};
        dist[a1.first][a1.second]=0;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:dir){
                ll nx=x+dx,ny=y+dy;
                if(nx<0||nx>=n||ny<0||ny>=m)continue;
                if(dist[nx][ny]!=-1)continue;
                if(nx==b1.first&&ny==b1.second)continue;
                if(nx==b2.first&&ny==b2.second)continue;
                dist[nx][ny]=dist[x][y]+1;
                par[nx][ny]={x,y};
                q.push({nx,ny});
            }
        }
        if(dist[a2.first][a2.second]==-1)return INF;
        int i,j;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(i!=a2.first||j!=a2.second)dist[i][j]=-1;
            }
        }
        pll now=a2;
        while(now!=a1){
            auto [x,y]=now;
            now=par[x][y];
            dist[now.first][now.second]=dist[x][y]-1;
        }
        dist[b1.first][b1.second]=0;
        q.push(b1);
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:dir){
                ll nx=x+dx,ny=y+dy;
                if(nx<0||nx>=n||ny<0||ny>=m)continue;
                if(dist[nx][ny]!=-1)continue;
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
        if(dist[b2.first][b2.second]==-1)return INF;
        return dist[b2.first][b2.second]+dist[a2.first][a2.second];
    };
    ll ans=INF;
    ans=min(ans,get_ans(a1,a2,b1,b2));
    ans=min(ans,get_ans(b1,b2,a1,a2));
    if(ans==INF)cout<<"IMPOSSIBLE\n";
    else cout<<ans<<'\n';
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
    preprocess();
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
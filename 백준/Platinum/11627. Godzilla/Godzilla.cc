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
    cin>>m>>n;
    vector<string> arr(n);
    pll now;
    vector<pll>machine;
    vector<vector<bool>>visited(n,vector<bool>(m,false)),visited2(n,vector<bool>(m,false));
    vector<vector<bitset<4>>>yokuk(n,vector<bitset<4>>(m,0));
    vector<ll>dx({-1,0,1,0}),dy({0,1,0,-1});
//    auto make_yokuk=[&](ll x, ll y,ll z){
//        while(x>=0&&x<n&&y>=0&&y<m){
//            if(arr[x][y]=='R')break;
//            yokuk[x][y][z]=true;
//            x+=dx[z];
//            y+=dy[z];
//        }
//    };
    for(i=0;i<n;i++)cin>>arr[i];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j]=='G'){
                now={i,j};
                visited2[i][j]=true;
            }
            else if(arr[i][j]=='M'){
                machine.push_back({i,j});
                visited[i][j]=true;
            }
        }
    }
    ll ans=0;
    while(true){
        arr[now.first][now.second]='.';
        for(i=0;i<4;i++){
            ll nx=now.first+dx[i],ny=now.second+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||visited2[nx][ny])continue;
            if(arr[nx][ny]=='R'){
                ans++;
                now={nx,ny};
                arr[nx][ny]='.';
                break;
            }
        }
        if(i==4){
            for(i=0;i<4;i++){
                ll nx=now.first+dx[i],ny=now.second+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m||visited2[nx][ny])continue;
                if(arr[nx][ny]=='.'){
                    now={nx,ny};
                    break;
                }
            }
        }
        arr[now.first][now.second]='G';
        visited2[now.first][now.second]=true;
        vector<pll>tmp;
        for(auto &it:machine){
            for(i=0;i<4;i++){
                ll nx=it.first+dx[i],ny=it.second+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny])continue;
                if(arr[nx][ny]!='R'){
                    visited[nx][ny]=true;
                    tmp.push_back({nx,ny});
                }
            }
        }
        machine=tmp;
        ll nowp=now.first;
        while(nowp>=0&&arr[nowp][now.second]!='R'){
            if(visited[nowp][now.second]){
                cout<<ans<<'\n';
                return;
            }
            nowp--;
        }
        nowp=now.first;
        while(nowp<n&&arr[nowp][now.second]!='R'){
            if(visited[nowp][now.second]){
                cout<<ans<<'\n';
                return;
            }
            nowp++;
        }
        nowp=now.second;
        while(nowp>=0&&arr[now.first][nowp]!='R'){
            if(visited[now.first][nowp]){
                cout<<ans<<'\n';
                return;
            }
            nowp--;
        }
        nowp=now.second;
        while(nowp<m&&arr[now.first][nowp]!='R'){
            if(visited[now.first][nowp]){
                cout<<ans<<'\n';
                return;
            }
            nowp++;
        }
        
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
    cin>>t;
#ifdef kidw0124
    clock_t st=clock();
#endif
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}
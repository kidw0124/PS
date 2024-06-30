#include<bits/stdc++.h>
using namespace std;
#ifdef ATCODER
#include<atcoder/all>
using namespace atcoder;
#endif
using ll = int;
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

//constexpr ll mod=998244353;

ll ans(vector<ll>arr,ll st){
    ll n=arr.size();
    ll i,j,k;
    ll ret=0;
    for(i=st;i<n-1;i++){
        if(arr[i]==i+1){
            ret=max(ret,ans(arr,i+1));
            vector<ll>tmp(arr.begin(),arr.begin()+i);
            for(j=i+2;j<n;j++)tmp.push_back(arr[j]);
            ret=max(ret,1+ans(tmp,i+1));
            if(arr[i+1]==i+2 && i+2<n){
                tmp=vector<ll>(arr.begin(),arr.begin()+i+1);
                for(j=i+3;j<n;j++)tmp.push_back(arr[j]);
                ret=max(ret,1+ans(tmp,i-1));
            }
        }
    }
//    for(auto x:arr)cout<<x<<" ";
//    cout<<"\n"<<st<<" "<<ret<<"\n";

    return ret;
}

void solve(){
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    if(n==0 && m==0)exit(0);
    vector<string>arr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    ll ans=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j]=='@'&&!vis[i][j]){
                ans++;
                queue<pll>q({{i,j}});
                vis[i][j]=true;
                while(!q.empty()){
                    auto [x,y]=q.front();
                    q.pop();
                    for(k=-1;k<=1;k++){
                        for(int l=-1;l<=1;l++){
                            ll nx=x+k,ny=y+l;
                            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
                            if(vis[nx][ny] || arr[nx][ny]=='*')continue;
                            vis[nx][ny]=true;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
    solve();
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
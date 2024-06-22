#include<bits/stdc++.h>
using namespace std;
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

void solve(){
    int i,j,k;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> grp(n);
    vector<ll> tree(n),dist(n,-1);
    vector<ll> diameter,radius;
    ll now=1;
    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
    for(i=0;i<n;i++){
        if(!tree[i]){
            ll las;
            queue<ll> q;
            q.push(i);
            tree[i]=now;
            while(!q.empty()){
                las=q.front();
                q.pop();
                for(auto &x:grp[las]){
                    if(!tree[x]){
                        tree[x]=now;
                        q.push(x);
                    }
                }
            }
            dist[las]=0;
            q.push(las);
            while(!q.empty()){
                las=q.front();
                q.pop();
                for(auto &x:grp[las]){
                    if(dist[x]==-1){
                        dist[x]=dist[las]+1;
                        q.push(x);
                    }
                }
            }
            diameter.push_back(dist[las]);
            radius.push_back((dist[las]+1)/2);
            now++;
        }
    }
    sort(radius.begin(),radius.end(),greater<ll>());
    ll ans=*max_element(diameter.begin(),diameter.end());
    if(radius.size()>=2){
        ans=max(ans,radius[0]+radius[1]+1);
    }
    if(radius.size()>=3){
        ans=max(ans,radius[1]+radius[2]+2);
    }
    cout<<ans<<endl;

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
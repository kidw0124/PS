#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n,m;

vector<vector<pll>>arr;
vector<ll>dpt;
vector<vector<pll>>sparse;

ll find_lca(ll u,ll v){
    if(dpt[u]>dpt[v])swap(u,v);
    ll d=dpt[v]-dpt[u];
    for(ll i=0;d;i++){
        if(d&1){
            v=sparse[v][i].first;
        }
        d>>=1;
    }
    if(u!=v){
        while(sparse[u][0].first!=sparse[v][0].first){
            ll i;
            for(i=0;sparse[u][i+1].first!=sparse[v][i+1].first;i++);
            u=sparse[u][i].first;
            v=sparse[v][i].first;
        }
        u=sparse[u][0].first;
        v=sparse[v][0].first;
    }
    return u;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    arr.resize(n+1);
    dpt.resize(n+1);
    sparse.resize(n+1,vector<pll>(20));
    for(i=0;i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
    }

    queue<ll>que;
    que.push(1);
    dpt[1]=1;
    while(!que.empty()){
        ll now=que.front();
        que.pop();
        for(auto k:arr[now]){
            if(dpt[k.first])continue;
            else{
                sparse[k.first][0]={now,k.second};
                dpt[k.first]=dpt[now]+1;
                que.push(k.first);
            }
        }
    }

    for(i=1;i<20;i++){
        for(j=1;j<=n;j++){
            sparse[j][i]={sparse[sparse[j][i-1].first][i-1].first,sparse[sparse[j][i-1].first][i-1].second+sparse[j][i-1].second};
        }
    }
    cin>>m;

    while(m--){
        ll a,u,v,k;
        cin>>a;
        if(a==1){
            cin>>u>>v;
            ll ans=0;
            if(dpt[u]>dpt[v])swap(u,v);
            ll d=dpt[v]-dpt[u];
            for(i=0;d;i++){
                if(d&1){
                    ans+=sparse[v][i].second;
                    v=sparse[v][i].first;
                }
                d>>=1;
            }
            if(u!=v){
                while(sparse[u][0].first!=sparse[v][0].first){
                    for(i=0;sparse[u][i+1].first!=sparse[v][i+1].first;i++);
                    ans+=sparse[u][i].second+sparse[v][i].second;
                    u=sparse[u][i].first;
                    v=sparse[v][i].first;
                }
                ans+=sparse[u][0].second+sparse[v][0].second;
                u=sparse[u][0].first;
                v=sparse[v][0].first;
            }
            cout<<ans<<'\n';
        }
        else{
            cin>>u>>v>>k;
            ll ans=0;
            ll lca=find_lca(u,v);
            if(dpt[u]-dpt[lca]+1<=k){
                k-=dpt[u]-dpt[lca]+1;
                k=dpt[v]-dpt[lca]-k;
                for(i=0;k;i++){
                    if(k&1)v=sparse[v][i].first;
                    k>>=1;
                }
                cout<<v<<'\n';
            }
            else{
                k--;
                for(i=0;k;i++){
                    if(k&1)u=sparse[u][i].first;
                    k>>=1;
                }
                cout<<u<<'\n';
            }
        }
    }

    return 0;
}

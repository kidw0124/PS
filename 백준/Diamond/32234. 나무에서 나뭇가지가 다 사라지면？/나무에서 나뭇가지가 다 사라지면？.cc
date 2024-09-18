#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;


void preprocess() {
    ;
}

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    auto brr=arr;
    vector<ll>grd(n),parxor(n);
    vector<vector<ll>>grp(n);
    for(i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    ll cnt=0;
    for(i=0;i<n;i++){
        cnt=max(cnt,(ll)grp[i].size());
    }
    if(cnt<=2){
        vector<ll>par(n,-1);
        par[0]=0;
        queue<ll>q;
        ll last=0;
        q.push(0);
        while(!q.empty()){
            ll u=q.front();
            last=u;
            q.pop();
            for(auto v:grp[u]){
                if(par[v]==-1){
                    par[v]=u;
                    q.push(v);
                }
            }
        }
        vector<ll>child(n);
        ll now=last;
        while(now!=0){
            child[par[now]]=now;
            now=par[now];
        }
        ll xor_now=arr[0];
        while(now!=last){
            if(xor_now==0){
                cout<<"kidw0124\n";
                return;
            }
            now=child[now];
            xor_now^=arr[now];
        }
        if(xor_now==0){
            cout<<"kidw0124\n";
            return;
        }
        cout<<"eoaud0108\n";
        return;
    }
    vector<bool>vis(n);
    queue<ll>que({0});
    vis[0]=1;
    parxor[0]=0;
    while(!que.empty()){
        ll u=que.front();
        que.pop();
        for(auto v:grp[u]){
            if(!vis[v]){
                vis[v]=1;
                arr[v]=arr[u]^arr[v];
                parxor[v]=arr[u];
                que.push(v);
            }
        }
    }
    vis.assign(n,0);
    vector<set<ll>>dp(n);
    function<void(ll)> dfs=[&](ll u)->void{
        vis[u]=1;
        ll g=0;
        vector<ll>pp;
        for(auto v:grp[u]){
            if(!vis[v]){
                dfs(v);
                if(dp[v].find(parxor[u])!=dp[v].end()){
                    pp.push_back(v);
                }
                if(dp[v].size()>dp[u].size())swap(dp[u],dp[v]);
                for(auto x:dp[v])dp[u].insert(x);
                dp[v].clear();
                g^=grd[v];
            }
        }
        bitset<20>tmp;
        tmp.set();
        dp[u].insert(arr[u]);
        if(brr[u]==0)tmp.reset(g);
        for(auto v:pp){
            tmp.reset(g^grd[v]);
        }
        grd[u]=tmp._Find_first();
    };
    dfs(0);
    if(grd[0]==0){
        cout<<"eoaud0108\n";
    }
    else {
        cout << "kidw0124\n";
    }


}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t beg = clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}

#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("inline")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= long double;
constexpr ll MAXN=2e6+8;

struct Dinic{
    using flow_t=int;
    struct Edge{
        int next;
        size_t inv;
        flow_t res;
    };
    int n;
    vector<vector<Edge>>graph;
    vector<int> q,l,start;
    Dinic(int _n=0):n(_n){
        graph.resize(n);
        for(int i=0;i<n;i++)graph[i].clear();
    }
    void init(int _n){
        n=_n;
        graph.resize(n);
        for(int i=0;i<n;i++)graph[i].clear();
    }
    void add_edge(int s, int e, flow_t cap, flow_t caprev=0){
        Edge forward{e,graph[e].size(),cap};
        graph[s].push_back(forward);
        Edge reverse{s,graph[s].size(),caprev};
        graph[e].push_back(reverse);
    }
    bool assign_level(int source, int sink){
        int t=0;
        memset(&l[0],0,sizeof(l[0])*l.size());
        l[source]=1;
        q[t++]=source;
        for(int h=0;h<t&&!l[sink];h++){
            int cur=q[h];
            for(const auto&e:graph[cur]){
                if(l[e.next]||e.res==0)continue;
                l[e.next]=l[cur]+1;
                q[t++]=e.next;
            }
        }
        return l[sink]!=0;
    }
    flow_t block_flow(int cur, int sink, flow_t current){
        if(cur==sink)return current;
        for(int&i=start[cur];i<graph[cur].size();i++){
            auto&e=graph[cur][i];
            if(e.res==0||l[e.next]!=l[cur]+1)continue;
            if(flow_t res = block_flow(e.next,sink,min(e.res,current))){
                e.res-=res;
                graph[e.next][e.inv].res+=res;
                return res;
            }
        }
        return 0;
    }
    flow_t solve(int source, int sink){
        q.resize(n);
        l.resize(n);
        start.resize(n);
        flow_t ans=0;
        while(assign_level(source,sink)){
            memset(&start[0],0,sizeof(start[0])*n);
            while(flow_t flow=block_flow(source,sink,numeric_limits<flow_t>::max())){
                ans+=flow;
            }
        }
        return ans;
    }
    vector<char>mincut_side(int source, int sink){
        // if side source, vis[i]=1; else vis[i]=0
        vector<char>vis(n);
        queue<int>que;
        que.push(source);
        vis[source]=1;
        while(!que.empty()){
            int cur=que.front();que.pop();
            for(const auto&e:graph[cur]){
                if(vis[e.next]||e.res==0)continue;
                vis[e.next]=1;
                que.push(e.next);
            }
        }
        return vis;
    }
    vector<pair<int,int>>mincut_edges(int source,int sink){
        solve(source,sink);
        auto S=mincut_side(source,sink);
        vector<pair<int,int>>cut;
        for(int i=0;i<n;i++)if(S[i])for(const auto&e:graph[i])
            if(!S[e.next]&&e.res==0)cut.push_back({i,e.next});
        return cut;
    }
};

void solve(ll testcase) {
    ll i,j;
    bitset<MAXN>isprime;
    isprime.set();
    isprime[0]=isprime[1]=0;
    for(i=2;i*i<MAXN;i++){
        if(isprime[i])for(j=i*i;j<MAXN;j+=i)isprime[j]=0;
    }
    ll n;
    cin>>n;
    vector<ll>arr(n);
    Dinic dinic(n+2);
    ll source=n,sink=n+1;
    for(i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]&1){
//            cerr<<i<<" "<<sink<<" 1\n";
            dinic.add_edge(i,sink,1);
        }
        else{
            dinic.add_edge(source,i,1);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ll ai=arr[i],aj=arr[j];
            if(ai&1)ai++;if(aj&1^1)aj++;
            if(isprime[ai+aj])dinic.add_edge(i,j,MAXN);
        }
    }
    if(ranges::count(arr,1)>=2){
        for(i=0;i<n;i++){
            if(arr[i]==1){
                dinic.add_edge(source,i,MAXN);
            }
        }
    }
    ll flow=dinic.solve(source,sink);
    cout<<flow<<"\n";
    auto S=dinic.mincut_side(source,sink);
//    for(int i=0;i<n;i++){
//        cout<<i<<" "<<(int)S[i]<<"\n";
//    }
    for(i=0;i<n;i++){
        if(arr[i]&1^S[i]^1)cout<<i+1<<" ";
    }
    cout<<"\n";
}

void setup() {
    if (ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
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
    // cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}
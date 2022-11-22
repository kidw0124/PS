#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 1000010;
ll n, m, graph[MAXN], up[MAXN], visited[MAXN], vtime, scc_idx[MAXN], scc_cnt, i, j, p, q, res[MAXN], maxres;
bool check[MAXN];
vector<ll> stk;
vector<ll> scc[MAXN];

void process(ll x)
{
    up[x]=visited[x]=++vtime;
    stk.push_back(x);
    ll next=graph[x];
    if(visited[next]==0){
        process(next);
        up[x]=min(up[x], up[next]);
    }
    else if(scc_idx[next]==0){
        up[x]=min(up[x], visited[next]);
    }
    if(up[x]==visited[x]){
        scc_cnt++;
        ll t;
        do{
            t=stk.back();
            stk.pop_back();
            scc_idx[t]=scc_cnt;
        }while(!stk.empty()&&t!=x);
    }
}

void get_scc()
{
    vtime=0;
    memset(visited, 0, sizeof(visited));
    scc_cnt=0;
    memset(scc_idx, 0, sizeof(scc_idx));
    for(ll k=0;k<n;k++){
        if(visited[k]==0)process(k);
    }
}

void dfs(ll x)
{
    if(graph[x]==-1){
        res[x]=1;
        return;
    }
    if(check[x])return;
    if(!check[graph[x]])dfs(graph[x]);
    check[x]=true;
    res[x]=res[graph[x]]+1;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;
    for(i=0;i<n;i++)graph[i]=-1;
    for(i=0;i<m;i++){
        cin>>p>>q;
        graph[p]=q;
    }
    get_scc();
    for(i=0;i<n;i++)scc[scc_idx[i]].push_back(i);
    for(i=0;i<n;i++)check[i]=false;
    for(i=1;i<=scc_cnt;i++){
        if(scc[i].size()>1){
            for(j=0;j<scc[i].size();j++){
                check[scc[i][j]]=true;
                res[scc[i][j]]=scc[i].size();
            }
        }
    }

    for(i=0;i<n;i++){
        if(!check[i])dfs(i);
    }

    for(i=0;i<n;i++)if(maxres<res[i])maxres=res[i];
    cout<<maxres;
    return 0;
}
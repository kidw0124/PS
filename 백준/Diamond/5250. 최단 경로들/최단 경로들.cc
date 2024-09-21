#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<int, int> pint;
typedef vector<int> vl;
#define pb(x) push_back(x)
#define aint(x) (x).begin(), (x).end()
int gcd(int a, int b){return b?gcd(b,a%b):a;}
int lcm(int a, int b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
int POW(int a, int b, int rem){int p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
int n,m,a,b,k;
vector<vector<pint>>arr;
vector<vector<int>>brr;
vector<vector<int>>parents;
vector<int> dist;
vector<int> dist2;
vector<int>road;
vector<int>rroad;
vector<int>depth;
const int INF=1e9+7;

int lca(int x, int y){
    if(depth[x]<depth[y])swap(x,y);
    int dd=depth[x]-depth[y];
    int i=0;
    while(dd){
        if(dd&1){
            x=parents[x][i];
        }
        dd>>=1;
        i++;
    }
    if(x==y)return x;
    else{
        for(i=14;i>=0;i--){
            if(parents[x][i]!=parents[y][i]){
                x=parents[x][i],y=parents[y][i];
            }
        }
        return parents[x][0];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    cin>>n>>m>>a>>b;
    arr.resize(n+1);
    brr.resize(n+1,vector<int>(n+1));
    depth.resize(n+1);
    parents.resize(n+1,vector<int>(15));
    dist.resize(n+1,INF);
    dist2.resize(n+1,INF);
    rroad.resize(n+1,-1);
    for(i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        arr[u].push_back({v,w});
        arr[v].push_back({u,w});
        brr[u][v]=brr[v][u]=w;
    }
    cin>>k;
    road.resize(k);
    priority_queue<pint>pq;
    pq.push({0,a});
    dist[a]=0;
    depth[a]=1;
    for(i=0;i<k;i++){
        cin>>road[i];
        rroad[road[i]]=i;
        if(i){
            parents[road[i]][0]=road[i-1];
            depth[road[i]]=depth[road[i-1]]+1;
            pq.push({-(dist[road[i]]=dist[road[i-1]]+brr[road[i-1]][road[i]]),road[i]});
        }
    }
    while(!pq.empty()){
        int nowc=-pq.top().first,nowv=pq.top().second;
        pq.pop();
        if(dist[nowv]!=nowc)continue;
        for(auto k:arr[nowv]){
            if(dist[k.first]>nowc+k.second){
                dist[k.first]=nowc+k.second;
                parents[k.first][0]=nowv;
                depth[k.first]=depth[nowv]+1;
                pq.push({-dist[k.first],k.first});
            }
        }
    }
    pq.push({0,b});
    dist2[b]=0;
    while(!pq.empty()){
        int nowc=-pq.top().first,nowv=pq.top().second;
        pq.pop();
        if(dist2[nowv]!=nowc)continue;
        for(auto k:arr[nowv]){
            if(dist2[k.first]>nowc+k.second){
                dist2[k.first]=nowc+k.second;
                pq.push({-dist2[k.first],k.first});
            }
        }
    }
    for(i=1;i<15;i++){
        for(j=1;j<=n;j++){
            parents[j][i]=parents[parents[j][i-1]][i-1];
        }
    }
    vector<int>ans(k+1,INF);
    for(i=1;i<=n;i++){
        for(auto k:arr[i]){
            if(rroad[i]==-1||rroad[k.first]==-1||abs(rroad[i]-rroad[k.first])!=1){
                int x=lca(b,i),y=lca(b,k.first);
                for(j=rroad[x];j<rroad[y];j++){
                    //cout<<j<<' '<<ans[j]<<' '<<dist[i]+k.second+dist2[k.first]<<' '<<i<<' '<<k.first<<' '<<k.second<<'\n';
                    ans[j]=min(ans[j],dist[i]+k.second+dist2[k.first]);
                }
            }
        }
    }
    for(i=0;i<k-1;i++){
        if(ans[i]==INF)cout<<"-1\n";
        else cout<<ans[i]<<'\n';
    }

    return 0;
}

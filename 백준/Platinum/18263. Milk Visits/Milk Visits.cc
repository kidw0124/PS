#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
const int MN = 1e5+5;
int N,M,a,b,x,p,L[MN],R[MN],cnt,S[4*MN],par[MN][20],dep[MN];
bool A[MN];
vector<int> T[MN],G[MN];
vector<ppi> Q[MN];
void dfs(int s)
{
    L[s] = ++cnt;
    for(int e : G[s]){
        if(e==par[s][0]) continue;
        par[e][0] = s;
        dep[e] = dep[s]+1;
        dfs(e);
    }
    R[s] = cnt;
}

void upt(int s, int e, int x, int y, int val, int pos)
{
    if(e<x||y<s) return;
    if(x<=s&&e<=y){
        S[pos] += val;
        return;
    }
    int m = (s+e)/2;
    upt(s,m,x,y,val,2*pos);
    upt(m+1,e,x,y,val,2*pos+1);
}

int sum(int s, int e, int x, int pos)
{
    if(e<x||x<s) return 0;
    if(s==e) return S[pos];
    int m = (s+e)/2;
    return sum(s,m,x,2*pos)+sum(m+1,e,x,2*pos+1)+S[pos];
}

int getr(int a, int b)
{
    if(dep[a]<dep[b]) swap(a,b);
    int k = 19;
    while(k>=0){
        if(dep[a]-dep[b]>=(1<<k)) a = par[a][k];
        k--;
    }
    k = 19;
    while(k>=0){
        if(par[a][k]!=par[b][k]){
            a = par[a][k];
            b = par[b][k];
        }
        k--;
    }
    if(a!=b) a = par[a][0];
    return a;
}

int main()
{
 //   freopen("milkvisits.in","r",stdin);
  //  freopen("milkvisits.out","w",stdout);
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> x;
        T[x].push_back(i);
    }
    for(int i=1; i<N; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    for(int i=1; i<20; i++)
        for(int x=1; x<=N; x++)
            par[x][i] = par[par[x][i-1]][i-1];
    for(int i=1; i<=M; i++){
        cin >> a >> b >> x;
        Q[x].emplace_back(pii(a,b),i);
    }
    for(int i=1; i<=N; i++){
        for(int x : T[i]) upt(1,N,L[x],R[x],1,1);
        for(ppi x : Q[i]){
            a = x.va.va;
            b = x.va.vb;
            p = getr(a,b);
            if(sum(1,N,L[a],1)+sum(1,N,L[b],1)-2*sum(1,N,L[par[p][0]],1)) A[x.vb] = 1;
        }
        for(int x : T[i]) upt(1,N,L[x],R[x],-1,1);
    }
    for(int i=1; i<=M; i++) cout << A[i];
}

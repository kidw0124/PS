#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, i, p, q, res, dp1[100010], dp2[100010], degree[100010];
vector<ll> path[100010];
bool check[100010];
ll dfs(ll x)
{
    check[x]=true;
    ll minimum=m*4;
    dp2[x]=-1;
    for(int k=0;k<path[x].size();k++){
        if(check[path[x][k]])continue;
        ll cur=dfs(path[x][k]);
        if(minimum>cur)minimum=cur;
        if(dp2[path[x][k]]!=-1){
            if(dp2[x]==-1)dp2[x]=dp2[path[x][k]]+1;
            else if(dp2[x]>dp2[path[x][k]]+1)dp2[x]=dp2[path[x][k]]+1;
        }
    }
    if(minimum==m*4)return dp1[x]=m;
    else{
        if(dp2[x]!=-1){
            if(minimum-1>=dp2[x]){
                dp1[x]=2*m+1-dp2[x];
                if(minimum-1>dp1[x])dp1[x]=minimum-1;
                return dp1[x];
            }
        }
        if(minimum>1)return dp1[x]=minimum-1;
        dp2[x]=0;
        res++;
        return dp1[x]=2*m+1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(i=2;i<=n;i++){
        check[i]=false;
        cin>>p>>q;
        path[p].push_back(q);
        path[q].push_back(p);
        degree[p]++;
        degree[q]++;
    }
    for(i=1;i<=n;i++){
        if(degree[i]==1){
            dfs(i);
            if(dp1[i]<=m)res++;
            break;
        }
    }
    cout<<res;
//    cout<<"\n";for(i=1;i<=n;i++)cout<<dp1[i]<<" ";
//    cout<<"\n";for(i=1;i<=n;i++)cout<<dp2[i]<<" ";
    return 0;
}
/**
20 3
1 15
15 2
2 3
3 6
2 4
4 5
2 7
7 8
8 9
9 10
10 11
11 12
5 13
13 14
12 16
16 17
17 18
2 19
19 20

**/

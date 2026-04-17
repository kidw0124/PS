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
vector<vl> arr;
vl par;
ll n;
vector<pll>dp;

void dfs(ll now){
//    if(arr[now].size()==1&&now!=1){
//        dp[now].first=0,dp[now].second=INT_MAX;
//    }
    for(auto k:arr[now]){
        if(k==par[now])continue;
        else{
            dfs(k);
            dp[now].first+=min(dp[k].first,dp[k].second);
            dp[now].second+=dp[k].first;
        }
    }
    dp[now].first+=1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    arr=*(new vector<vl>(n+1));
    par=*(new vl(n+1,-1));
    dp=*(new vector<pll>(n+1,{0,0}));
    for(i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    par[1]=0;
    stack<ll>que;
    que.push(1);
    while(!que.empty()){
        ll now=que.top();
        que.pop();
        for(auto k:arr[now]){
            if(par[k]==-1){
                que.push(k);
                par[k]=now;
            }
        }
    }
    dfs(1);
//    for(i=0;i<n+1;i++){
//        cout<<dp[i].first<<' '<<dp[i].second<<'\n';
//    }
    cout<<min(dp[1].first,dp[1].second);
    return 0;
}

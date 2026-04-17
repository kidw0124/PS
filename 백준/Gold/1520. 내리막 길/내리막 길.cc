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
ll m,n;
ll arr[505][505];
ll dp[505][505];
ll ddx[4]={0,1,0,-1},ddy[4]={1,0,-1,0};
priority_queue<pair<ll,pll>>pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    memset(arr,1000000,sizeof(arr));
    cin>>m>>n;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            cin>>arr[i][j];
            pq.push({arr[i][j],{i,j}});
        }
    }
    dp[1][1]=1;
    while(1){
        pair<ll,pll> pp=pq.top();
        pq.pop();
        ll nx=pp.second.first,ny=pp.second.second,nh=pp.first;
        if(pp.second.first==m&&pp.second.second==n){
            cout<<dp[m][n];
            return 0;
        }
        else{
            for(i=0;i<4;i++){
                ll nnx=nx+ddx[i],nny=ny+ddy[i];
                if(arr[nnx][nny]<arr[nx][ny])dp[nnx][nny]+=dp[nx][ny];

            }
        }
    }
    return 0;
}

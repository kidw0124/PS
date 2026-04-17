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
typedef struct{
    ll x, y, cost, b;
}tp;
ll dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n, m;
    cin>>n>>m;
    string arr[1005];
    bool visited[1005][1005][2]={0};
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    queue<tp>que;
    que.push({0,0,1,0});
    visited[0][0][0]=1;
    ll ans=-1;
    while(!que.empty()){
        ll nx=que.front().x,ny=que.front().y,nc=que.front().cost,nb=que.front().b;
        que.pop();
        if(nx==n-1&&ny==m-1){
            ans=nc;
            break;
        }
        for(i=0;i<4;i++){
            ll nnx=nx+dx[i],nny=ny+dy[i];
            if(nnx<0||nny<0||nnx>=n||nny>=m)continue;
            if(arr[nnx][nny]=='0'){
                if(visited[nnx][nny][nb])continue;
                else{
                    visited[nnx][nny][nb]=1;
                    visited[nnx][nny][1]=1;
                    que.push({nnx,nny,nc+1,nb});
                }
            }
            else if(nb==0){
                if(visited[nnx][nny][1])continue;
                else{
                    visited[nnx][nny][1]=1;
                    que.push({nnx,nny,nc+1,1});
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

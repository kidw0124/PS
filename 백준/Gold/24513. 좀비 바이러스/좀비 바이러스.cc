#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n,m;
pll arr[1005][1005];
ll dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    queue<pair<tuple<ll,ll,ll>,ll>>que;
    for(i=0;i<n;i++){
        rep(j,0,m){
            cin>>arr[i][j].first;
            if(arr[i][j].first>0){
                arr[i][j].second=1;
                que.push({{i,j,1},arr[i][j].first});
            }
        }
    }
    while(!que.empty()){
        ll nowx,nowy,nowc,nowt;
        tie(nowx,nowy,nowt)=que.front().first;
        nowc=que.front().second;
        que.pop();
        if(arr[nowx][nowy].first==3)continue;
        for(i=0;i<4;i++){
            ll nx=nowx+dx[i],ny=nowy+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m)continue;
            else if(arr[nx][ny].second==nowt+1&&arr[nx][ny].first!=nowc)arr[nx][ny].first=3;
            else if(arr[nx][ny].first==0&&arr[nx][ny].second==0){
                arr[nx][ny]={nowc,nowt+1};
                que.push({{nx,ny,nowt+1},nowc});
            }
        }
    }
    int ans[4]={0};
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            ans[arr[i][j].first]++;
        }
    }
    cout<<ans[1]<<' '<<ans[2]<<' '<<ans[3];
    return 0;
}

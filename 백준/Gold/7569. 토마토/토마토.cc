#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef struct{
    ll first,second,third;
} pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n,m,h;
ll arr[105][105][105];
ll ddx[6]={0,1,0,-1,0,0},ddy[6]={1,0,-1,0,0,0},ddz[6]={0,0,0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k;
    cin>>m>>n>>h;
    queue<pll>que;
    for(i=0;i<h;i++)for(j=0;j<n;j++)for(k=0;k<m;k++){
        cin>>arr[i][j][k];
        if(arr[i][j][k]==1)que.push({i,j,k});
    }
    ll ans=0;
    while(!que.empty()){
        pll now=que.front();
        que.pop();
        ans=arr[now.first][now.second][now.third];
        for(i=0;i<6;i++){
            ll nx=now.first+ddx[i];
            ll ny=now.second+ddy[i];
            ll nz=now.third+ddz[i];
            if(nx<0||ny<0||nz<0||nx>=h||ny>=n||nz>=m||arr[nx][ny][nz])continue;
            else{
                arr[nx][ny][nz]=ans+1;
                que.push({nx,ny,nz});
            }
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<n;j++)for(k=0;k<m;k++){
            if(!arr[i][j][k]){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<ans-1;

    return 0;
}

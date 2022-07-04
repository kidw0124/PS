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
ll ddy[6]={-1,1,-1,1,-1,1},ddx[6]={-1,-1,0,0,1,1};
const ll maxn=80+2;
bool isc[maxn][maxn];
pll conn[maxn][maxn];
string seats[maxn];
ll cnt,sum;
ll t,n,m;
bool dfs(pll x){
    for(ll i=0;i<6;i++){
        pll ne={x.first+ddx[i],x.second+ddy[i]};
        if(ne.first<0||ne.first>=n||ne.second<0||ne.second>=m)continue;
        if(isc[ne.first][ne.second]||seats[ne.first][ne.second]=='x')continue;
        isc[ne.first][ne.second]=true;
        if(conn[ne.first][ne.second]==make_pair(-1ll,-1ll)||dfs(conn[ne.first][ne.second])){
            conn[ne.first][ne.second]=x;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i=0;i<maxn;i++){
            for(j=0;j<maxn;j++){
                conn[i][j]={-1,-1};
            }
        }
        cnt=sum=0;
        for(i=0;i<n;i++){
            cin>>seats[i];
            sum+=count(seats[i].begin(),seats[i].end(),'.');
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j+=2){
                for(ll k=0;k<maxn;k++){
                    for(ll l=0;l<maxn;l++){
                        isc[l][k]=0;
                    }
                }
                if(seats[i][j]=='x')continue;
                else if(dfs({i,j}))cnt++;
            }
        }
        cout<<sum-cnt<<'\n';
    }
    return 0;
}

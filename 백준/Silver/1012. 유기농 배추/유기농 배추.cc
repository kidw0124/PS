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
ll t,n,m,k;
ll ddx[4]={0,0,1,-1},ddy[4]={1,-1,0,0};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        cin>>m>>n>>k;
        bool arr[51][51]={0};
        for(i=0;i<k;i++){
            ll t1,t2;
            cin>>t1>>t2;
            arr[t2][t1]=1;
        }
        ll cnt=0;
        queue<pll> que;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(arr[i][j]){
                    que.push({i,j});
                    cnt++;
                    while(!que.empty()){
                        pll x=que.front();
                        que.pop();
                        arr[x.first][x.second]=0;
                        for(ll y=0;y<4;y++){
                            if(x.first+ddx[y]<0||x.first+ddx[y]>=n||x.second+ddy[y]>=m||x.second+ddy[y]<0||!arr[x.first+ddx[y]][x.second+ddy[y]])continue;
                            arr[x.first+ddx[y]][x.second+ddy[y]]=0;
                            que.push({x.first+ddx[y],x.second+ddy[y]});
                        }
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }

    return 0;
}

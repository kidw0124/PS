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
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
vector<int> arr;
vector<vector<pii>>par;

pii _find(pii x){
    if(par[x.first][x.second]==make_pair(-1,-1))return x;
    else return par[x.first][x.second]=_find(par[x.first][x.second]);
}

void _union(pii x, pii y){
    x=_find(x);
    par[x.first][x.second]=_find(y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    int n,m,a,b;
    cin>>a>>b>>n>>m;
    vector<int>arr(n+1),brr(m+1);
    par.resize(n+1,vector<pii>(m+1,{-1,-1}));
    priority_queue<pair<int,pair<pii,pii>>>pq;
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    arr.push_back(a);
    for(i=1;i<=m;i++){
        cin>>brr[i];
    }
    brr.push_back(b);
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    for(i=0;i<=n;i++){
        for(j=0;j<m;j++){
            pq.push({-arr[i+1]+arr[i],{{i,j},{i,j+1}}});
        }
    }
    for(i=0;i<=m;i++){
        for(j=0;j<n;j++){
            pq.push({-brr[i+1]+brr[i],{{j,i},{j+1,i}}});
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            par[i][j]={-1,-1};
        }
    }
    ll ans=0;
    while(!pq.empty()){
        int nowc=-pq.top().first;
        pii x=pq.top().second.first,y=pq.top().second.second;
        pq.pop();
        if(_find(x)!=_find(y))ans+=nowc,_union(x,y);
    }
    cout<<ans;
    return 0;
}

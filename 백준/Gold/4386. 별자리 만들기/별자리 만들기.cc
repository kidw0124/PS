#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double ld;
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
ll n;
ld dist(pair<ld,ld>a,pair<ld,ld>b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
vector<ll>par;

ll _find(ll x){
    if(par[x]==-1)return x;
    else return par[x]=par[par[x]];
}

void _union(ll x, ll y){
    par[_find(y)]=_find(x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vector<pair<ld,ld>>arr(n+1);
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    par.resize(n+1,-1);
    vector<vector<ld>>brr(n+1,vector<ld>(n+1));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            brr[i][j]=dist(arr[i],arr[j]);
        }
    }
    ld ans=0;
    vector<ld> nd(n+1,99999999);
    vector<bool> vis(n+1);
    vis[0]=1;
    for(i=0;i<n;i++)nd[i]=brr[i][0];
    nd[0]=999999999;
    for(i=0;i<n-1;i++){
        ll now=0;
        for(j=0;j<n;j++){
            if(!vis[j]&&nd[j]<nd[now])now=j;
        }
        vis[now]=1;
        ans+=nd[now];
        nd[now]=999999999;
        for(j=0;j<n;j++){
            if(!vis[j])nd[j]=min(nd[j],brr[now][j]);
        }
    }
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}

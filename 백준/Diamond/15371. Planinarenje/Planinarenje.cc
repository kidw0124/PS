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
vector<vector<ll>>arr;
vector<ll>par;
vector<bool>ans,vis,mpvis;
bool match(ll a){
    if(vis[a])return false;
    else{
        vis[a]=true;
        for(auto k:arr[a]){
            if(par[k]==-1||match(par[k])){
                par[k]=a;
                return true;
            }
        }
        return false;
    }
}
void dfs(ll a){
    if(vis[a])return;
    vis[a]=true;
    ans[a]=true;
    for(auto k:arr[a])dfs(par[k]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    arr.resize(n<<1);
    ans.resize(n<<1);
    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        arr[a-1].push_back(b+n-1);
        arr[b+n-1].push_back(a-1);
    }
    par.resize(n<<1);
    vis.resize(n);
    for(i=n;i<n<<1;i++)par[i]=-1;
    for(i=0;i<n;i++){
        fill(vis.begin(),vis.end(),0);
        match(i);
    }
    mpvis.resize(n<<1,0);
    for(i=n;i<n<<1;i++)if(par[i]!=-1)mpvis[par[i]]=true;
    fill(vis.begin(),vis.end(),0);
    for(i=0;i<n;i++)if(!mpvis[i])dfs(i);
    for(i=0;i<n;i++){
        cout<<(ans[i]?"Mirko":"Slavko")<<'\n';
    }
    return 0;
}

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

vector<ll>arr,par,maxi,tot,exc;
vector<vector<ll>>child;
ll ans=(ll)-1e18;

void dfs(ll now){
    tot[now]=arr[now];
    maxi[now]=arr[now];
    if(child[now].size()==0){
        return;
    }
    else{
        vector<ll>tmp;
        for(auto k:child[now]){
            dfs(k);
            maxi[now]+=max(0ll,maxi[k]);
            tot[now]=max(tot[now],tot[k]);
            tmp.push_back(tot[k]);
            exc[now]=max(exc[now],maxi[k]>0?exc[k]:tot[k]);
        }
        tot[now]=max(tot[now],maxi[now]);
        sort(tmp.begin(),tmp.end(),greater<>());
        if(tmp.size()>1)ans=max(ans,tmp[0]+tmp[1]);
    }
    ans=max(ans,maxi[now]+exc[now]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll i,j;
    ll n;
    cin>>n;
    arr.resize(n+1),par.resize(n+1),child.resize(n+1),maxi.resize(n+1),tot.resize(n+1),exc.resize(n+1,(ll)-1e18);
    for(i=1;i<=n;i++){
        cin>>arr[i];
        cin>>par[i];
        if(par[i]>0)child[par[i]].push_back(i);
    }
    dfs(1);
    cout<<ans;

    return 0;
}

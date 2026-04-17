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
vector<vector<pll>>arr;
vector<ll>x;
ll nnn=5000005;
pair<ll,ll> dp[20][1<<20];

ll ans(ll now, ll vis){
    if(vis==((1<<n)-1)<<1){
        if(x[now]!=0){
            return x[now];
        }
        return 5000005;
    }
    pair<ll,ll>&ret=dp[now][vis];
    if(ret.first)return ret.first;
    ret.first=5000005;
    for(auto k:arr[now]){
        if(vis&(1<<(k.first)))continue;
        else{
            ll x=ans(k.first,vis|(1<<(k.first)));
            if(ret.first>max(x,k.second)){
                ret.first=max(x,k.second);
                ret.second=k.first;
            }
        }
    }
    return ret.first;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    arr.resize(n+1);
    x.resize(n+1);
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(b==1)x[a]=c;
        arr[a].push_back({b,c});
    }
    nnn=ans(1,2);
    if(nnn<5000001)cout<<nnn<<'\n';
    else {cout<<-1;return 0;}
    int now=1,nowv=0;
    while(now>0){
        cout<<now<<' ';
        nowv|=(1<<now);
        now=dp[now][nowv].second;
    }

    return 0;
}

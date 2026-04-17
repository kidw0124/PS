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
ll n;
vector<ll> arr;
vector<vector<ll>>adj;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    arr.resize(n);
    adj.resize(n,vector<ll>(n));
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            adj[i][j]=arr[i]^arr[j];
        }
    }
    ll ans=0;
    vector<ll> dist(n);
    for(i=0;i<n;i++){
        ll now=max_element(dist.begin(),dist.end())-dist.begin();
        ans+=dist[now];
        dist[now]=-1;
        for(j=0;j<n;j++){
            if(dist[j]!=-1)dist[j]=max(dist[j],adj[now][j]);
        }
    }
    cout<<ans;
    return 0;
}

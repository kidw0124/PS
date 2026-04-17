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
ll n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<ll>childcnt(n+1);
    for(i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        childcnt[y]++;
    }
    priority_queue<ll>pq;
    for(i=1;i<=n;i++){
        if(childcnt[i]==0)pq.push(-i);
    }
    while(!pq.empty()){
        ll now=-pq.top();
        pq.pop();
        cout<<now<<' ';
        for(auto k:adj[now]){
            childcnt[k]--;
            if(childcnt[k]==0)pq.push(-k);
        }
    }
    return 0;
}

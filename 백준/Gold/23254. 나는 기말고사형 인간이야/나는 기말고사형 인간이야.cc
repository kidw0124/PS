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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vl arr(m),brr(m);
    priority_queue<pll>pq;
    for(i=0;i<m;i++){
        cin>>arr[i];
    }
    for(i=0;i<m;i++){
        cin>>brr[i];
        pq.push({min(100-arr[i],brr[i]),i});
    }
    for(i=0;i<24*n;i++){
        ll pf=pq.top().first,ps=pq.top().second;
        pq.pop();
        arr[ps]+=pf;
        pq.push({min(100-arr[ps],brr[ps]),ps});

    }
    ll ans=0;
    for(i=0;i<m;i++){
        ans+=arr[i];
    }
    cout<<ans;
    return 0;
}

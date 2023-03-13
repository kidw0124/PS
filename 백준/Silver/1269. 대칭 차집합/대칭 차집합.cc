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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    set<ll>a,b;
    ll n,m;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>j;
        a.insert(j);
    }
    for(i=0;i<m;i++){
        cin>>j;
        b.insert(j);
    }
    ll cnt=0;
    for(auto k:a){
        if(b.find(k)==b.end())cnt++;
    }
    for(auto k:b){
        if(a.find(k)==a.end())cnt++;
    }
    cout<<cnt;
    return 0;
}

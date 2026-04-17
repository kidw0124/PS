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
    ll n,m;
    cin>>n;
    vector<ll>st(n);
    for(i=0;i<n;i++)cin>>st[i];
    deque<ll>arr;
    for(i=0;i<n;i++){
        cin>>j;
        if(!st[i])arr.push_back(j);
    }
    cin>>m;
    while(m--){
        cin>>i;
        arr.push_front(i);
        cout<<arr.back()<<' ';
        arr.pop_back();
    }
    return 0;
}

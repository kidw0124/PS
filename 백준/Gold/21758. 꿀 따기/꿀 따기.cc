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
    ll n;
    cin>>n;
    vector<ll>arr(n),sum(n+1);
    ll x=0;
    for(i=0;i<n;i++){
        cin>>arr[i];
        sum[i+1]=arr[i]+sum[i];
        if(i&&n-1-i)x+=arr[i];
    }
    x+=*max_element(arr.begin()+1,arr.end()-1);
    for(i=1;i<n;i++){
        x=max(x,sum[n]-arr[0]-arr[i]+sum[n]-sum[i+1]);
    }
    for(i=0;i<n-1;i++){
        x=max(x,sum[n]-arr[n-1]-arr[i]+sum[i]);
    }
    cout<<x;
    return 0;
}

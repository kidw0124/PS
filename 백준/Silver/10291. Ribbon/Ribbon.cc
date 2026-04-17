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
    while(cin>>n){
        vector<ll>arr(n);
        for(i=0;i<n;i++)cin>>arr[i];
        ll g=gcd(arr[0]-2,arr[1]-2);
        for(i=2;i<n;i++)g=gcd(g,arr[i]-2);
        cout<<g<<' ';
        ll ans=0;
        for(i=0;i<n;i++)ans+=(arr[i]-2)/g;
        cout<<ans<<'\n';
    }


    return 0;
}

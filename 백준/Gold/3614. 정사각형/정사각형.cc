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
ll n;
const ll maxn=1e6;
vector<ll>primes;

ll phi(ll x){
    ll ret=1;
    for(ll k=2;k<=x;k++){
        ll now=1;
        while(x%k==0){
            now*=k;
            x/=k;
        }
        ret*=now-now/k;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    ll ans=0;
    for(i=1;i*i<=n;i++){
        if(n%i==0){
            ans+=phi(i+1);
            if(i*i!=n)ans+=phi(n/i+1);
        }
    }
    cout<<(ans+1)/2;
    return 0;
}

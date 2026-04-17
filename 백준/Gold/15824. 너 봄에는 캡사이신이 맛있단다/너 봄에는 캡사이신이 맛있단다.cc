#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n;
ll ans;
const ll mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vl arr(n);
    vl pp(n);
    for(i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    pp[0]=1;
    for(i=1;i<n;i++){
        pp[i]=pp[i-1]*2%mod;
    }
    for(i=0;i<n;i++){
        ans+=(mod+pp[i]-pp[n-i-1])*arr[i]%mod;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}

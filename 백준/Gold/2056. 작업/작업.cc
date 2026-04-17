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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vector<ll>arr(n+1),dp(n+1);
    vector<vector<ll>>pre(n+1);
    for(i=1;i<=n;i++){
        cin>>arr[i];
        ll t;
        cin>>t;
        for(j=0;j<t;j++){
            ll k;
            cin>>k;
            pre[i].push_back(k);
        }
    }
    ll M=0;
    for(i=1;i<=n;i++){
        ll m=0;
        for(auto j:pre[i])m=max(m,dp[j]);
        dp[i]=m+arr[i];
        M=max(M,dp[i]);
    }
    cout<<M;

    return 0;
}

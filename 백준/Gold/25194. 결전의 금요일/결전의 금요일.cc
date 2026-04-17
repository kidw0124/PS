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
    vector<ll>arr(n);
    vector<bool>dp(7);
    dp[0]=1;
    for(i=0;i<n;i++){
        cin>>arr[i];
        vector<bool>ddp(7);
        for(j=0;j<7;j++){
            if(dp[j])ddp[(j+arr[i])%7]=1,ddp[j]=1;
        }
        dp=ddp;
    }
    cout<<(dp[4]?"YES":"NO");
    return 0;
}

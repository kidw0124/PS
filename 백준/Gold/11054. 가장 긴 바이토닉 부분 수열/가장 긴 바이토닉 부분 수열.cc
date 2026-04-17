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
ll arr[1005],dp[1005][3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++)cin>>arr[i];
    dp[0][0]=dp[n-1][1]=1;
    ll m=0;
    for(i=1;i<n;i++){
        dp[i][0]=1;
        dp[n-i-1][1]=1;
        for(j=0;j<i;j++){
            if(arr[i]>arr[j])dp[i][0]=max(dp[j][0]+1,dp[i][0]);
        }
        for(j=n-1;j>=n-i;j--){
            if(arr[n-i-1]>arr[j])dp[n-i-1][1]=max(dp[j][1]+1,dp[n-i-1][1]);
        }
    }
    for(i=0;i<n;i++)m=max(m,dp[i][0]+dp[i][1]-1);
    cout<<m;
    return 0;
}

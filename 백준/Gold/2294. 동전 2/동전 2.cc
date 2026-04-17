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
ll n,k,arr[105],dp[10005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>k;
    for(i=0;i<n;i++){cin>>arr[i];if(arr[i]<=k)dp[arr[i]]=1;}
    for(i=1;i<=k;i++){
        if(!dp[i])dp[i]=99999;
        for(j=0;j<n;j++){
            if(i>arr[j])dp[i]=min(dp[i],dp[i-arr[j]]+1);
        }
    }
    cout<<(dp[k]+1)%100000-1;
    return 0;
}

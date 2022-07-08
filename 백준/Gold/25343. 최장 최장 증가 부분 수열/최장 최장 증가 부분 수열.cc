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
vector<vector<ll>>arr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    arr.resize(n,vector<ll>(n));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)cin>>arr[i][j];
    }
    vector<vector<ll>>dp(n,vector<ll>(n,1));
    ll ans=1;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(ll k=0;k<=i;k++){
                for(ll l=0;l<=j;l++){
                    if(arr[k][l]<arr[i][j]){
                        dp[i][j]=max(dp[i][j],dp[k][l]+1);
                        ans=max(ans,dp[i][j]);
                    }
                }
            }
        }
    }
    cout<<ans;

    return 0;
}

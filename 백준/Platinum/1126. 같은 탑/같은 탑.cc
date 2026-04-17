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
ll n, sum;
vl arr;
vector<vector<ll>>dp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    arr.resize(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    dp.resize(n,vector<ll>(sum+1,-1));
    dp[0][0]=0;
    dp[0][arr[0]]=arr[0];
    for(i=1;i<n;i++){
        for(j=0;j<sum;j++){
            if(dp[i-1][j]+1){
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j+arr[i]]=max(dp[i][j+arr[i]],dp[i-1][j]+arr[i]);
                if(arr[i]<j){
                    dp[i][j-arr[i]]=max(dp[i][j-arr[i]],dp[i-1][j]);
                }
                else{
                    dp[i][arr[i]-j]=max(dp[i][arr[i]-j],dp[i-1][j]+arr[i]-j);
                }
            }
        }
    }
    if(dp[n-1][0]){
        cout<<dp[n-1][0];
    }
    else cout<<-1;
    return 0;
}

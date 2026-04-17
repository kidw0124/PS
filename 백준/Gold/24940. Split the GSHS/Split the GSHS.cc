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
    vl arr(n),sum(n+1);
    vector<vector<ll>>dp(n,vector<ll>(n));
    dp[n][n];
    for(i=0;i<n;i++){
        cin>>arr[i];
        sum[i+1]=sum[i]+arr[i];
        dp[i][i]=0;
    }
    for(ll dif=1;dif<n;dif++){
        for(i=0;i<n-dif;i++){
            ll c=1e18;
            for(j=0;j<dif;j++){
                ll x=dp[i][i+j]+dp[i+j+1][i+dif]+min(0ll,(sum[i+j+1]-sum[i])*(sum[i+dif+1]-sum[i+j+1]));
                c=min(c,x);
            }
            dp[i][i+dif]=c;
        }
    }
//    for(auto k:dp){
//        for(auto kk:k)cout<<kk<<' ';cout<<'\n';
//    }
    cout<<dp[0][n-1];
    return 0;
}

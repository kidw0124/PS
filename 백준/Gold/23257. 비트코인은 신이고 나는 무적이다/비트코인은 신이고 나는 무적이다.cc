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
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

    bool dp[1024][105]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n+1);
    for(i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]=abs(arr[i]);
    }
    dp[0][0]=1;
    ll ans=0;
    for(i=0;i<m;i++){
        for(j=0;j<1024;j++){
            if(dp[j][i]){
                for(ll k=1;k<=n;k++){
                    dp[j^arr[k]][i+1]=1;
                }
            }
        }
    }
    for(j=0;j<1024;j++){
        if(dp[j][m])ans=j;
    }
    cout<<ans;
    return 0;
}

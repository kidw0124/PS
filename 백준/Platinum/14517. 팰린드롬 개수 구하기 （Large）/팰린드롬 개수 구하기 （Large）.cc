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
const ll MOD=10007;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string str;
    cin>>str;
    vector<vector<ll>>dp(str.size()+1,vector<ll>(str.size()+1));
    ll ans=str.size();
    for(i=0;i<str.size();i++){
        for(j=str.size()-1;j>i;j--){
            dp[i][j]=dp[i][j+1]+(i==0?0:dp[i-1][j])+(str[i]==str[j]?1:(MOD-(i==0?0:dp[i-1][j+1]%MOD)))+MOD;
            dp[i][j]%=MOD;
            ans+=(str[i]==str[j]?1+(i==0?0:dp[i-1][j+1]%MOD):0)*(j-i);
            ans%=MOD;
        }
    }
    cout<<ans;
    return 0;
}

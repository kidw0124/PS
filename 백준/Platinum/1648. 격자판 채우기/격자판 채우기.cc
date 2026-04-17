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
const ll MOD=9901;

vector<vector<ll>>dp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,m;
    bool x=0;
    cin>>n>>m;
    dp.resize(1<<m,vector<ll>(2));
    dp[0][0]=1;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            for(ll k=0;k<(1<<m);k++){
                ll now=1<<j;
                if(k&now){
                    dp[k&(~now)][!x]=(dp[k&(~now)][!x]+dp[k][x])%MOD;
                }
                else{
                    dp[k|now][!x]=(dp[k|now][!x]+dp[k][x])%MOD;
                    now<<=1;
                    if(j<m-1&&!(k&now)){
                        dp[k|now][!x]=(dp[k|now][!x]+dp[k][x])%MOD;
                    }
                }
                dp[k][x]=0;
            }
            x=!x;
        }
    }
    cout<<dp[0][x];
    return 0;
}

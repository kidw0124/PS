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

vector<vector<ll>>dp(20);

void print(ll n,ll t){
    if(t>=(1<<n))return;
    cout<<dp[n][t]<<' ';
    print(n,t<<1);
    print(n,t<<1|1);
}

void filla(ll n, ll t,ll t1){
    if(t1>=(1<<n))return;
    dp[n][t1]=dp[n-1][t]<<1;
    if(t1>=(1<<n>>1))dp[n][t1]++;
    filla(n,t<<1,t1<<1);
    filla(n,t<<1|1,t1<<1|1);
}
void fillb(ll n, ll t,ll t1){
    if(t1>=(1<<n))return;
    dp[n][t1]=dp[n-1][t]<<1;
    if(t1<(1<<n>>1))dp[n][t1]++;
    fillb(n,t<<1,t1<<1);
    fillb(n,t<<1|1,t1<<1|1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    dp[1]={0,1};
    for(i=2;i<=n;i++){
        dp[i].resize(1<<i,1);
        filla(i,1,2);
        fillb(i,1,3);
    }
    print(n,1);
    return 0;
}

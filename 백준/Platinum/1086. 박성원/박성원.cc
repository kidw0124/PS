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
vl pow10rem(51,1);
ll n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vector<string> arr(n);
    vl rem(n,0);
    vector<vector<ll>>cnt(n+1);
    for(i=0;i<(1<<n);i++){
        ll cc=0;
        for(j=0;j<n;j++){
            if((i>>j)&1)cc++;
        }
        cnt[cc].push_back(i);
    }
    for(i=0;i<n;i++)cin>>arr[i];
    cin>>k;
    for(i=1;i<=50;i++)pow10rem[i]=(pow10rem[i-1]*10)%k;
    vector<vector<ll>> dp(1<<n,vl(k,0));
    for(i=0;i<n;i++){
        for(j=0;j<arr[i].size();j++){
            rem[i]*=10;
            rem[i]+=(arr[i][j]-'0');
            rem[i]%=k;
        }
        dp[1<<i][rem[i]]++;
    }
    for(i=1;i<n;i++){
        for(auto x:cnt[i]){
            for(j=0;j<n;j++){
                if((x>>j)&1)continue;
                else{
                    for(ll y=0;y<k;y++){
                        ll xxx=y*pow10rem[arr[j].size()]+rem[j];
                        xxx%=k;
                        dp[x|(1<<j)][xxx]+=dp[x][y];
                    }
                }
            }
        }
    }
    ll kkk=1;
    for(i=1;i<=n;i++){
        kkk*=i;
    }
    n=(1<<n)-1;
    if(dp[n][0]==0)cout<<0<<'/'<<1;
    else{
        ll g=gcd(dp[n][0],kkk);
        cout<<dp[n][0]/g<<'/'<<kkk/g;
    }
    return 0;
}

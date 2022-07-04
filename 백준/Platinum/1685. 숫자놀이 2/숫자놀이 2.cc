#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
ll n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,x=1,y=0;
    cin>>n;
    vector<ll>arr;
    for(i=0;i<n;i++){
        cin>>j;
        arr.push_back(j);
    }
    cin>>k;
    vector<ll>cannot(j),dp(j*j+1,k+1);
    dp[0]=0;
    ll ans=INT_MAX;
    for(i=1;i<dp.size();i++){
        if(x==j)x=0,y++;
        for(ll j : arr){
            if(i-j>=0){
                dp[i]=min(dp[i],dp[i-j]+1);
            }
        }
        if(dp[i]>k){
            ans=min(ans,i);
        }
        else cannot[x]=max(cannot[x],y+(k-dp[i])+1);
        x++;
    }
    for(i=0;i<j;i++){
        cannot[i]=cannot[i]*j+i;
    }
    ans=min(ans,*min_element(all(cannot)));
    cout<<(ans%2?"jjaksoon":"holsoon")<<" win at "<<ans;
    return 0;
}

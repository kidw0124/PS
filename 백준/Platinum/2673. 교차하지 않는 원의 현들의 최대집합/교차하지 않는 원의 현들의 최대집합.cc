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

vector<vector<ll>>dp(100,vector<ll>(100));
vector<pair<ll,ll>>arr;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    for(i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        arr.push_back({min(a,b)-1,max(a,b)-1});
    }
    sort(all(arr));
    for(i=0;i<100;i++){
        for(j=i;j>=0;j--){
            for(ll k=j;k<i;k++){
                dp[j][i]=max(dp[j][i],dp[j][k]+dp[k][i]+binary_search(all(arr),make_pair(j,i)));
            }
        }
    }
    cout<<dp[0][99];
    return 0;
}

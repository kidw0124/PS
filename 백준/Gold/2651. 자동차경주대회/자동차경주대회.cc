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
ll n,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>d>>n;
    vector<pll>arr(n+2,{0,0});
    stack<ll> st;
    vl dp(n+2,1ll<<32);
    vl anc(n+2,-1);
    dp[0]=0;
    for(i=1;i<=n+1;i++){ll t; cin>>t;arr[i].first=t+arr[i-1].first;}
    for(i=1;i<=n;i++)cin>>arr[i].second;
    for(i=0;i<=n;i++){
        for(j=i+1;j<=n+1;j++){
            if(arr[j].first-arr[i].first>d)break;
            if(dp[j]>dp[i]+arr[i].second){
                dp[j]=dp[i]+arr[i].second;
                anc[j]=i;
            }
        }
    }
    cout<<dp[n+1];
    i=n+1;
    while(anc[i]){
        st.push(i=anc[i]);
    }
    cout<<'\n'<<st.size()<<'\n';
    while(!st.empty()){cout<<st.top()<<' ';st.pop();}

    return 0;
}

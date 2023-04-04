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
const ll MAX=3000;
ll n;
ll m;
ll cycle=0;
vector<ll> arr;
bitset<MAX+1>dp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>j;
        arr.push_back(j);
    }
    for(i=1;i<=MAX;i++){
        for(j=0;j<m;j++){
            if(i-arr[j]>=0&&!dp[i-arr[j]])dp[i]=1;
        }
    }
    for(i=MAX/5;i>=0;i--){
        bool isCycle=true;
        for(j=0;j<i;j++){
            if(dp[MAX-j]!=dp[MAX-i-j])isCycle=0;
        }
        if(isCycle){
            cycle=i;
            break;
        }
    }
    ll ans=0;
    if(n<1000){
        for(i=1;i<=n;i++){
            if(!dp[i])ans++;
        }
        cout<<ans;
    }
    else{
        ll cycleone=0;
        for(i=1;i<=1000;i++){
            if(!dp[i])ans++;
        }
        for(i=0;i<cycle;i++){
            if(!dp[MAX-i])cycleone++;
        }
        ll times=(n-1000)/cycle;
        ans+=cycleone*times;
        for(i=1001;i<1001+(n-1000)%cycle;i++){
            if(!dp[i])ans++;
        }
        cout<<ans;
    }


    return 0;
}

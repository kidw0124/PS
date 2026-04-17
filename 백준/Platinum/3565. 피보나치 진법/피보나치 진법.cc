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
const ll MAXFIBO=70;
ll fibo[MAXFIBO]={0,1},dp[MAXFIBO]={0,1},sumdp[MAXFIBO]={0,1};
ll getone(ll cnt, ll digit){
    if(cnt==0)return 0;
    if(cnt==1)return 1;
    if(cnt<fibo[digit-1]){
        return getone(cnt,digit-1);
    }
    else{
        return dp[digit-1]+cnt-fibo[digit-1]+getone(cnt-fibo[digit-1],digit-2);
    }
}

ll countone(ll n, ll most){
    ll ret=0,st;
    bool k=0;
    for(ll i=MAXFIBO-1;i>=0;i--){
        if(n>=fibo[i]){
            n-=fibo[i];
            if(!k){
                k=true;
                st=i;
            }
            if(st-i+1<=most)ret++;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    for(i=2;i<MAXFIBO;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
        dp[i]=fibo[i]+sumdp[i-2];
        sumdp[i]=dp[i]+sumdp[i-1];
    }
    ll n;
    cin>>n;
//    for(i=0;i<10;i++){
//        cout<<dp[i]<<' ';
//    }
    for(i=1;i*fibo[i]<=n;i++){
        n-=i*fibo[i];
    }
//    cout<<n<<' '<<i<<' ';
    cout<<sumdp[i-1]+getone(n/i,i)+countone(n/i+fibo[i+1],n%i);
    return 0;
}
// 1000000000000000

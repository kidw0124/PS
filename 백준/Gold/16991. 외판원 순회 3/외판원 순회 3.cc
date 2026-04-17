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

long double arr[20][20];
long double dp[20][1<<20];
int n;
long double ans(int now, int vis){
    if(vis+1==1<<n){
        if(arr[now][0]){
            return arr[now][0];
        }
        else return -1;
    }
    else{
        long double&nowdp=dp[now][vis];
        if(nowdp){
            return nowdp;
        }
        else{
            nowdp=INT_MAX;
            for(int i=0;i<n;i++){
                if(!(1<<i&vis)&&arr[now][i]){
                    long double ret=ans(i,1<<i|vis);
                    if(ret==-1)continue;
                    nowdp=min(nowdp,ret+arr[now][i]);
                }
            }
            if(nowdp==INT_MAX)return nowdp=-1;
            else return nowdp;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    vector<pll>brr(n);
    for(i=0;i<n;i++)cin>>brr[i].first>>brr[i].second;
    for(i=0;i<n;i++)for(j=0;j<n;j++)arr[i][j]=sqrt(pow(brr[i].first-brr[j].first,2)+pow(brr[i].second-brr[j].second,2));
    cout<<setprecision(10)<<ans(0,1);

    return 0;
}
